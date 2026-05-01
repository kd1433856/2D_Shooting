#pragma once
#include"BaseEnemy.h"

class Phoenix :public BaseEnemy
{
public:

	Phoenix() {}
	~Phoenix() {}

	virtual void Init();
	void Action();
	virtual void Update();
	virtual void Draw();
	virtual void Release();

	void B_PhoenixHit(int e);

	Math::Vector2 GetPos(int e) { return m_pos[e]; }
	Math::Vector2 GetScale(int e) { return m_scale[e]; }
	float  GetRadius(int e) { return 7.0f * fabs(m_scale[e].x); }
	int GetNum() { return EnemyNum; }
	bool GetAliveFlg(int e);

private:

};