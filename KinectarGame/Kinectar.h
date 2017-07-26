#pragma once

#include <Siv3D.hpp>

#include "KinectManager.h"
#include "Guitar.h"

using namespace std;

class Kinectar
{
public:

	Kinectar();
	~Kinectar();

	void Run();

	void Update();
	void Draw();

	vector<int> getSoundTime() { return soundTime; };
	vector<vector<bool>> getPushedState() { return buttonState; };

	bool hasValidBody();

private:

	String getSerialMessage();
	String getWiFiMessage();
	vector<vector<bool>> getButtonState(vector<vector<bool>> state);

	void drawGuitar();

	void playSound();

private:

	Guitar* m_Guitar;
	KinectManager* m_KinectManager;

	vector<int> soundTime;
	vector<int> playingPitch;

	vector<int> basePitch;

	Serial	serial;
	vector<vector<bool>> buttonState;


	Rect Board;
	vector<Line> Str;
	vector<Line> Flet;

	Point boardPos;
	Point boardSize;
	int	fletSpace;
	int fletMarginLeft;


	const int fletMax = 6;
	const int rowMax = 5;

	const int baudrate = 115200;
	const int comPort = 3;
	const int midiCh = 0;

	
	//è‚ª”½‰‚·‚éŠp“x
	vector<double> fletAngle;

	vector<PitchName> pitchTable;

	vector<Key>	inputKeyAssign;



	//Wi-Fi’ÊMŠÖŒW
	const uint16 port = 58620;
	const IPv4 serverAddress = IPv4(192, 168, 43, 226);

	TCPClient client;

	
};
