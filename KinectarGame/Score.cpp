#include "Score.h"

Score::Score(String path,int SamplingRate)
{
	//path‚©‚çƒ[ƒh‚·‚é
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
		else if (line.includes(L"Blank:"))
		{
			mode = 2;
		}
		else if (line.includes(L"note:"))
		{
			mode = 0;
		}
		else
		{
			vector<String> part;
			int time = (SamplingRate / m_BPM) * m_Blank;
			int flet = 0;
			int string = 0;

			switch (mode)
			{
				case 0:
					part = line.split(':')[0].split(',');
					time += Parse<int>(part[0]) * 4 * (SamplingRate / m_BPM);
					time += Parse<int>(part[1]) * (SamplingRate / m_BPM);
					time += Parse<int>(part[2]) * ((SamplingRate / m_BPM) / 2000);
					
					part = line.split(':')[1].split(',');
					string = Parse<int>(part[0]);
					flet = Parse<int>(part[1]);

					m_Notes.push_back(Note(Vec2(100, 100), string, flet, time, Vec2(10, 10), Vec2(10, 10)));
					break;
				case 1:
					m_BPM = Parse<int>(line);
					break;
				case 2:
					m_Blank = Parse<int>(line);
					break;
			}
		}
	}
}

Score::~Score()
{

}