#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Run();

private:

	bool Update();
	void Draw();

	// �V�[���̃L�[�̌^�ƁA���L�f�[�^�̌^���w��
	using Scenes = SceneManager<String, GameData>;
	Scenes* scene;

	struct Title : Scenes::Scene
	{
		void init() override;

		void update() override;

		void draw() const override;
	};

	struct Menu : Scenes::Scene
	{
		void update() override;

		void init() override;

		void draw() const override;
	};

	struct Game : Scenes::Scene
	{
		void update() override;

		void init() override;

		void draw() const override;
	};
};
