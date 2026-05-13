#pragma once
#include"BaseEnemy.h"

class Evil:public BaseEnemy
{
public:

	Evil() {}
	~Evil() {}

	virtual void Init();
	void Action();
	virtual void Update();
	virtual void Draw();
	virtual void Release();

	void BurnInit();
	void BurnUpdate();
	void BurnDraw();

	void B_EvilHit(int e);
	void Repop(int e);

	void BulletInit();
	void BulletUpdate();
	void BulletDraw();

	Math::Vector2 GetPos(int e) { return m_pos[e]; }
	Math::Vector2 GetScale(int e) { return m_scale[e]; }
	float  GetRadius(int e) { return 16.0f * fabs(m_scale[e].x); }
	int GetNum() { return EnemyNum; }
	bool GetAliveFlg(int e);

	Math::Vector2 GetBulletPos(int b) { return m_buPos[b]; }
	int GetBulletNum() { return EvilBulletNum; }
	bool GetBulletFlg(int b);

private:

	static const int EvilNum = 20;
	bool EvilmoveFlg[EvilNum];
	int m_posgap[EvilNum];
	float m_aliveTime[EvilNum];
	bool EvilOneAliveFlg[EvilNum];

	bool ShotFlg[EvilNum];

	KdTexture m_BulletTex;

	static const int EvilBulletNum = 20;
	Math::Vector2 m_buPos[EvilBulletNum];
	Math::Vector2 m_buMove[EvilBulletNum];
	Math::Vector2 m_buScale[EvilBulletNum];
	Math::Matrix m_buMat[EvilBulletNum];
	Math::Matrix m_buScaleMat[EvilBulletNum];
	Math::Matrix m_buTransMat[EvilBulletNum];
	bool m_buAliveFlg[EvilBulletNum];
	float m_buAnimCnt[EvilBulletNum];

};
