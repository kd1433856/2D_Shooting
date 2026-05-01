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

private:

	static const int EvilNum = 10;
	bool EvilmoveFlg[EvilNum];
	int m_posgap[EvilNum];
	float m_aliveTime[EvilNum];
	bool EvilOneAliveFlg[EvilNum];

};
