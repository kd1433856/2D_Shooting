#pragma once
#include"State.h"
#include"Player.h"
#include"LifeDraw.h"
#include"Enemy/Phoenix.h"
#include"Enemy/Evil.h"
#include"Enemy/Ghost.h"
#include"Enemy/Boss.h"
#include"Hit/PlayerEnemy.h"
#include"Hit/BulletEnemy.h"
#include"ResultScene.h"
#include"ScoreDraw.h"
#include"Back.h"

class GameScene :public State
{
public:

	GameScene() {}
	~GameScene() {}

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;

	Player* GetPlayer() { return &player; }
	Phoenix* GetPhoenix() { return &phoenix; }
	Evil* GetEvil() { return &evil; }
	Ghost* GetGhost() { return &ghost; }
	Boss* GetBoss() { return &boss; }

private:

	Player player;
	LifeDraw life;
	Phoenix phoenix;
	Evil evil;
	Ghost ghost;
	Boss boss;
	PlayerEnemy pe_hit;
	BulletEnemy be_hit;
	ResultScene result;
	ScoreDraw score;
	C_Back back;

	int stageNum;
	bool stageFlg;
	bool resultFlg;
	bool NormalRepopFlg;
	bool BossRepopFlg;
	unsigned long goalscore;

	//表示する桁数
	static const int scoremaxDirit = 7;
	static const int goalscoremaxDirit = 7;

	KdTexture m_scoreTex;
	int m_scoredigits[scoremaxDirit] = {}; //各桁の数値を格納
	int m_goalscoredigits[goalscoremaxDirit] = {}; //各桁の数値を格納

};