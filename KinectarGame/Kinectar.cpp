#include "Kinectar.h"


Kinectar::Kinectar()
{

	PitchName table[96] =
	{
		PitchName::C0,	PitchName::DF0,	PitchName::D0,	PitchName::EF0,	PitchName::E0,	PitchName::F0,	PitchName::GF0,	PitchName::G0,	PitchName::AF0,	PitchName::A0,	PitchName::BF0,	PitchName::B0,
		PitchName::C1,	PitchName::DF1,	PitchName::D1,	PitchName::EF1,	PitchName::E1,	PitchName::F1,	PitchName::GF1,	PitchName::G1,	PitchName::AF1,	PitchName::A1,	PitchName::BF1,	PitchName::B1,
		PitchName::C2,	PitchName::DF2,	PitchName::D2,	PitchName::EF2,	PitchName::E2,	PitchName::F2,	PitchName::GF2,	PitchName::G2,	PitchName::AF2,	PitchName::A2,	PitchName::BF2,	PitchName::B2,
		PitchName::C3,	PitchName::DF3,	PitchName::D3,	PitchName::EF3,	PitchName::E3,	PitchName::F3,	PitchName::GF3,	PitchName::G3,	PitchName::AF3,	PitchName::A3,	PitchName::BF3,	PitchName::B3,
		PitchName::C4,	PitchName::DF4,	PitchName::D4,	PitchName::EF4,	PitchName::E4,	PitchName::F4,	PitchName::GF4,	PitchName::G4,	PitchName::AF4,	PitchName::A4,	PitchName::BF4,	PitchName::B4,
		PitchName::C5,	PitchName::DF5,	PitchName::D5,	PitchName::EF5,	PitchName::E5,	PitchName::F5,	PitchName::GF5,	PitchName::G5,	PitchName::AF5,	PitchName::A5,	PitchName::BF5,	PitchName::B5,
		PitchName::C6,	PitchName::DF6,	PitchName::D6,	PitchName::EF6,	PitchName::E6,	PitchName::F6,	PitchName::GF6,	PitchName::G6,	PitchName::AF6,	PitchName::A6,	PitchName::BF6,	PitchName::B6,
		PitchName::C7,	PitchName::DF7,	PitchName::D7,	PitchName::EF7,	PitchName::E7,	PitchName::F7,	PitchName::GF7,	PitchName::G7,	PitchName::AF7,	PitchName::A7,	PitchName::BF7,	PitchName::B7
	};

	pitchTable = vector<PitchName>(96);
	for (int i = 0; i < 96; i++)
	{
		pitchTable[i] = table[i];
	}


	soundTime = vector<int>(fletMax, 0);

	basePitch = vector<int>(fletMax);

	//int base[] = { 28,33,38,43,47,52,57,63,69,75,80,85,90 };
	int base[] = { 52,47,43,38,33,28 };
	for (int i = 0; i < fletMax; i++)
	{
		basePitch[i] = base[i];
	}
	playingPitch = basePitch;

	inputKeyAssign = vector<Key>(fletMax);

	Key key[] = { Input::Key1, Input::Key2, Input::Key3, Input::Key4, Input::Key5, Input::Key6, Input::Key7, Input::Key8, Input::Key9, Input::Key0 };
	for (int i = 0; i < fletMax; i++)
	{
		inputKeyAssign[i] = key[i];
	}

	boardSize = Point((int)Window::Width, 200);
	boardPos = Point(0, 100);
	fletSpace = 100;
	fletMarginLeft = 10;

	Board = Rect(boardPos, boardSize);

	Str = vector<Line>(fletMax);
	Flet = vector<Line>(rowMax + 1);
	
	
	for (int i = 0; i < Str.size(); i++)
	{
		int y = boardPos.y + (boardSize.y / (fletMax*2)) + (boardSize.y/(fletMax*2))*(i*2);
		Str[i] = Line(0, y, (int)Window::Width(), y);
	}

	for (int i = 0; i < Flet.size(); i++)
	{
		int x = fletMarginLeft + i * fletSpace;
		Flet[i] = Line(x, boardPos.y, x, boardPos.y+boardSize.y);
	}

	
	buttonState = vector<vector<bool>>(rowMax, vector<bool>(fletMax, false));


	fletAngle = vector<double>(fletMax);

	for (int i = 0; i < fletMax; i++)
	{
		fletAngle[i] = Pi - (Pi / 3) - (Pi / 30 * i);// +(Pi / 12);
	}

	

	client.connect(serverAddress, port);


	m_KinectManager = new KinectManager(fletMax);

	
	if (!serial.setup(comPort, baudrate))
	{
		MessageBox::Show(L"シリアルデバイスにアクセスできません.");
	}

	if (!KinectV2::IsAvailable())
	{
		MessageBox::Show(L"KinectV2にアクセスできません.");
	}

	if (!KinectV2::Start(KinectV2DataType::Default))
	{
		MessageBox::Show(L"KinectV2を起動できませんでした.");
	}
	/*
	if (!client.isConnected())
	{
		MessageBox::Show(L"クライアントに接続できませんでした.");
	}
	*/

	Midi::SendMessage(MidiMessage::SetInstrument(0, GMInstrument::CleanGuitar));

}

Kinectar::~Kinectar()
{
	MidiMessage::AllSoundOff(0);
	serial.close();
}


void Kinectar::Run()
{
	Window::Resize(1366, 768);

	while (System::Update())
	{
		Update();

		Draw();
	}
}

void Kinectar::Update()
{
	buttonState = getButtonState(buttonState);
	m_KinectManager->Update();

	playSound();
}

void Kinectar::Draw()
{
	//ClearPrint();
	
	m_KinectManager->Draw(soundTime, fletAngle);

	//drawGuitar();
	
	//Print(soundTime, L"\n");
}

String Kinectar::getSerialMessage()
{
	Array<uint8>	receive_data;
	String str;
	String message;

	receive_data = serial.readBytes();

	for (const auto& c : receive_data)
	{
		str.push_back(c);
	}

	return str;
}

String Kinectar::getWiFiMessage()
{
	char c;
	String ret = L"";

	while (true)
	{
		if (!client.read(c))
		{
			return ret;
		}
		else
		{
			ret.push_back(c);
		}
	}

}

vector<vector<bool>> Kinectar::getButtonState(vector<vector<bool>> state)
{
	String message = getSerialMessage();
	//String message = getWiFiMessage();

	//vector<vector<bool>> buttonUpdated(rowMax, vector<bool>(fletMax, false));

	for (const auto& line: message.split(L'\n'))
	{
		String trimline = line.trim();
		vector<String> row = trimline.split(L',');
		for(int i=0;i<row.size();i++)
		{
			vector<String> part = row[i].split(L':');
			int index = -1;
			for (int j = 0; j < part.size(); j++)
			{
				//index部分
				if (j == 0 && FromString<int>(part[j]) >= 0 && FromString<int>(part[j]) <= rowMax)
				{
					index = FromString<int>(part[j]);
				}
				else if (j != 0 && part[j].length == fletMax && index != -1)
				{
					for (int n = 0; n < fletMax; n++)
					{
						if (part[j].at(n) == L'1')
						{
							state[index][n] = true;
						}
						else if(part[j].at(n) == L'0')
						{
							state[index][n] = false;
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}
	return state;
}

void Kinectar::drawGuitar()
{
	Board.draw(Palette::Brown);

	for (int i = 0; i < Str.size(); i++)
	{
		uint32 b = 255 - (255 - soundTime[i] * 8);
		if (soundTime[i] * 8 > 255 || soundTime[i] == 0)
		{
			b = 255;
		}
		int thick = 3 + ((255 - b) / 51);
		Str[i].draw(thick, { 255,255,b,255 });
	}

	for (int i = 0; i < Flet.size(); i++)
	{
		Flet[i].draw(4, Palette::Silver);
	}

	for (int i = 0; i < rowMax; i++)
	{
		for (int j = 0; j < fletMax; j++)
		{
			if (buttonState[i][j] == true)
			{
				Circle(fletMarginLeft + i * fletSpace + fletSpace / 2, boardPos.y + (boardSize.y / (fletMax * 2)) + (boardSize.y / (fletMax * 2)) * (j * 2), 15).draw(Palette::Red);
			}
		}
	}
}

void Kinectar::playSound()
{
	double currentHandAngle;
	double prevHandAngle;

	vector<vector<double>> handAngles = m_KinectManager->getHandAngle();

	for (int i = 0; i < fletMax; i++)
	{
		if (soundTime[i] > 0)
		{
			soundTime[i]++;
		}

		if (soundTime[i] >= 128)
		{
			Midi::SendMessage(MidiMessage::NoteOff(midiCh, playingPitch[i]));
			soundTime[i] = 0;
		}
	}

	//とりあえず全員分とっちゃうか
	for (int body = 0; body < 6; body++)
	{
		vector<double> ha = handAngles[body];
	
		//手が肘から一定以上手前に離れているか、手が開いていれば音を出さないようにしたい
		if (Abs(m_KinectManager->getHandDiff()[body]) > 0.35 || m_KinectManager->getHandState()[body] == HandState::Open)
		{
			return;
		}

		if (ha.size() >= 2)
		{
			currentHandAngle = ha[ha.size()-1];
			prevHandAngle = ha[ha.size() - 2];
		}
		else
		{
			currentHandAngle = 0;
			prevHandAngle = 0;
		}

		Println(ha);

		for (int i = 0; i < fletMax; i++)
		{
			if (inputKeyAssign[i].clicked 
				|| (currentHandAngle > fletAngle[i] && prevHandAngle < fletAngle[i] && prevHandAngle > 0 && currentHandAngle > 0)
				|| (currentHandAngle < fletAngle[i] && prevHandAngle > fletAngle[i] && prevHandAngle > 0 && currentHandAngle > 0))
			{
				Midi::SendMessage(MidiMessage::NoteOff(midiCh, playingPitch[i]));

				bool anyPushed = false;
				for (int j = rowMax-1; j >= 0; j--)
				{
					if (buttonState[j][i] == true && anyPushed == false)
					{
						playingPitch[i] = basePitch[i]+j+1;
						anyPushed = true;
					}
					else if (j == 0 && anyPushed == false)
					{
						playingPitch[i] = basePitch[i];
					}
				}

				Midi::SendMessage(MidiMessage::NoteOn(midiCh, pitchTable[playingPitch[i]]));
				soundTime[i] = 1;
			}
		}

		if (Input::Key0.clicked)
		{
			for (int i = 0; i < fletMax; i++)
			{
				soundTime[i] = 1;
			}
		}

	}
}

bool Kinectar::hasValidBody()
{
	return m_KinectManager->hasValidBody();
}