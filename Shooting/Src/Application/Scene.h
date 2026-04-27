#pragma once
#include"chara.h"
#include"Enemy/Phoenix.h"
#include"Hit/PlayerEnemy.h"

class Scene
{
private:

	Player player;
	Phoenix phoenix;
	PlayerEnemy pe_hit;

public:

	// ‰Šúİ’è
	void Init();

	// ‰ğ•ú
	void Release();

	// XVˆ—
	void Update();

	// •`‰æˆ—
	void Draw2D();

	// GUIˆ—
	void ImGuiUpdate();

	Player* GetPlayer() { return &player; }
	Phoenix* GetPhoenix() { return &phoenix; }

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
