#include "KinectManager.h"

KinectManager::KinectManager(int fletMax)
{
	logSize = 10;

	jointsNum = sizeof(KinectV2Body::joints) / sizeof(KinectV2Joint);

	bodyPos = vector<vector<vector<Vec3>>>(6);
	currentBodyPos = vector<vector<Vec3>>(6,vector<Vec3>(jointsNum));
	handDiff = vector<double>(6);

	handAngle = vector<vector<double>>(6);

	depthDrawPos = Vec2(0, 320);
	colorDrawPos = Vec2(512, 320);
}

KinectManager::~KinectManager()
{

}

void KinectManager::Update()
{
	for (auto& hd : handDiff) 
	{
		hd = 0;
	}

	if (KinectV2::HasNewDepthFrame())
	{
		KinectV2::GetDepthFrame(depthTexture);
	}

	if (KinectV2::HasNewColorFrame())
	{
		KinectV2::GetColorFrame(colorTexture);
	}

	if (KinectV2::HasNewBodyFrame())
	{
		KinectV2::GetBodyFrame(bodies);
	}



	for (int body = 0; body < 6; body++)
	{
		if (bodyPos[body].size() > logSize)
		{
			bodyPos[body].erase(bodyPos[body].begin());
		}

		if (handAngle[body].size() > logSize)
		{
			handAngle[body].erase(handAngle[body].begin());
		}

		if (!bodies[body])
		{
			continue;
		}

		for (int joint = 0; joint < jointsNum; joint++)
		{
			currentBodyPos[body][joint] = Vec3(bodies[body]->joints[joint].depthSpacePos, bodies[body]->joints[joint].cameraSpacePos.z);
			bodyPos.push_back(currentBodyPos);
		}

		handDiff[body] = currentBodyPos[body][V2JointType::HandRight].z - currentBodyPos[body][V2JointType::ShoulderRight].z;

		Vec2 angleDiff = currentBodyPos[body][V2JointType::ElbowRight].xy() - currentBodyPos[body][V2JointType::HandRight].xy();
		handAngle[body].push_back(Atan2(angleDiff.x, angleDiff.y));
	}
}

void KinectManager::Draw(vector<int> soundTime, vector<double> fletAngle)
{
	depthTexture.draw(depthDrawPos);
	
	//colorTexture.resize(960,540).draw(colorDrawPos);
	colorTexture.draw(colorDrawPos);

	for (int body = 0; body < 6; body++)
	{
		if (!bodies[body])
		{
			continue;
		}

		for (int joint = 0; joint < jointsNum; joint++)
		{
			if (bodies[body]->joints[joint].trackingState == TrackingState::NotTracked)
			{
				continue;
			}

			if (joint == V2JointType::HandRight)
			{
				//Println(L"distance:" + ToString(handDiff));

				if (Abs(handDiff[body]) > 0.35)
				{
					Circle(currentBodyPos[body][joint].xy() + depthDrawPos, 10).draw(Palette::Red);
				}
				else
				{
					Circle(currentBodyPos[body][joint].xy() + depthDrawPos, 10).draw(Palette::Lightgreen);
				}
			}
			else if (joint == V2JointType::ElbowRight)
			{
				Circle(currentBodyPos[body][joint].xy() + depthDrawPos, 10).draw(Palette::Yellow);
			}
			else
			{
				Circle(currentBodyPos[body][joint].xy() + depthDrawPos, 10).draw(Palette::White);
			}

			bodyPos.push_back(currentBodyPos);
		}

		Line(currentBodyPos[body][V2JointType::ElbowRight].xy() + depthDrawPos, currentBodyPos[body][V2JointType::HandRight].xy() + depthDrawPos).draw(5, Palette::Purple);

		//fletèÍèäÇÃï‚èïê¸
		Vec2 base = currentBodyPos[body][V2JointType::ElbowRight].xy() + depthDrawPos;
		for (int i = 0; i < fletAngle.size(); i++)
		{
			Vec2 v = Vec2(Sin(fletAngle[i]), Cos(fletAngle[i]));

			uint32 b = 255 - (255 - soundTime[i] * 8);
			if (soundTime[i] * 8 > 255 || soundTime[i] == 0)
			{
				b = 255;
			}
			int thick = 2 + ((255 - b) / 51);
			Line(base, base - v * 150).draw(thick, { 255,255,b,255 });
		}

		//äOé¸â~
		Circle(base, 150).drawFrame(2, 2, Palette::White);
		//â~Ç…í«è]Ç∑ÇÈéËÇÃäpìxÇÃâ~
		if (handAngle.size() > 2)
		{
			if (Abs(handDiff[body]) > 0.35)
			{
				Circle(base + Vec2(Sin(handAngle[body][handAngle[body].size() - 1] + Pi), Cos(handAngle[body][handAngle[body].size() - 1] + Pi)) * 150, 15).draw(Palette::Red);
			}
			else
			{
				Circle(base + Vec2(Sin(handAngle[body][handAngle[body].size() - 1] + Pi), Cos(handAngle[body][handAngle[body].size() - 1] + Pi)) * 150, 15).draw(Palette::Lightgreen);
			}

		}
	}

}