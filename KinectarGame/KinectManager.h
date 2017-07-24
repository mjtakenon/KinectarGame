#pragma once
#include <Siv3D.hpp>

using namespace std;

class KinectManager
{
public:

	KinectManager(int fletMax);
	~KinectManager();

	void Update();
	void Draw(vector<int> soundTime, vector<double> fletAngle);

	vector<double> getHandDiff() { return handDiff; };
	vector<vector<double>> getHandAngle() { return handAngle; };

private:

	array<Optional<KinectV2Body>,6>	bodies;

	vector<vector<vector<Vec3>>>	bodyPos;
	vector<vector<Vec3>>			currentBodyPos;

	vector<vector<double>>	handAngle;
	vector<double>	handDiff;

	Vec2	depthDrawPos;
	Vec2	colorDrawPos;

	int		logSize;
	int		jointsNum;

	DynamicTexture	depthTexture;
	DynamicTexture	colorTexture;

};