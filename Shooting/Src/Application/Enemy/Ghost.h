#pragma once
#include"BaseEnemy.h"

class Ghost :public BaseEnemy
{
public:

	Ghost() {}
	~Ghost() {}

	virtual void Init();
	void Action();
	virtual void Update();
	virtual void Draw();
	virtual void Release();

	Math::Vector2 GetPos(int e) { return m_pos[e]; }
	Math::Vector2 GetScale(int e) { return m_scale[e]; }
	float  GetRadius(int e) { return 16.0f * fabs(m_scale[e].x); }
	int GetNum() { return EnemyNum; }
	bool GetAliveFlg(int e);

private:

	static const int GhostNum = 7;

};