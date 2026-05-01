#pragma once
#include"Player.h"
#include"Enemy/Phoenix.h"
#include"Enemy/Evil.h"
#include"Hit/PlayerEnemy.h"
#include"Hit/BulletEnemy.h"

class Scene
{
private:

	Player player;
	Phoenix phoenix;
	Evil evil;
	PlayerEnemy pe_hit;
	BulletEnemy be_hit;

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
	Evil* GetEvil() { return &evil; }

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
