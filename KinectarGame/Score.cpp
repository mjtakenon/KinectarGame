#include "Score.h"

Score::Score(String path,int SamplingRate)
{
	//pathÇ©ÇÁÉçÅ[ÉhÇ∑ÇÈ
	m_BPM = 130;
	m_Blank = 0;
	m_Notes = list<Note>();

	TextReader reader(path);

	String line;

	int mode = 0;
	while (reader.readLine(line))
	{
		if (line.includes(L"BPM:"))
		{
			mode = 1;
		}
		else if (line.includes(L"BLANK:"))
		{
			mode = 2;
		}
		else if (line.includes(L"NOTE:"))
		{
			mode = 0;
		}
		else
		{
			vector<String> part;
			int sample = (SamplingRate / m_BPM) * m_Blank;
			int flet = 0;
			int string = 0;

			switch (mode)
			{
				case 0:
					part = line.split(':')[0].split(',');
					sample += Parse<int>(part[0]) * 4 * (60 / m_BPM * SamplingRate);
					sample += Parse<int>(part[1]) * (60 / m_BPM * SamplingRate);
					sample += Parse<int>(part[2]) * (60 / m_BPM * SamplingRate) / 2000;
					
					part = line.split(':')[1].split(',');
					string = Parse<int>(part[0])-1;
					flet = Parse<int>(part[1]);

					m_Notes.push_back(Note(Vec2(0,0), string, flet, sample, Vec2(0,0), Vec2(0,0)));
					break;
				case 1:
					m_BPM = Parse<double>(line);
					break;
				case 2:
					m_Blank = Parse<double>(line);
					break;
			}
		}
	}
}

Score::~Score()
{

}