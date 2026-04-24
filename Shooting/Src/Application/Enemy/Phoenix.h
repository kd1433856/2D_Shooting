#pragma once
#include"BaseEnemy.h"

class Phoenix :public BaseEnemy
{
public:

	virtual void Init();
	void Action();
	virtual void Draw();

private:

};