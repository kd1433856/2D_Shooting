#pragma once

class BaseEnemy
{
public:

	void Init();
	void Update();
	void Draw();
	void Release();

protected:

	static const int EnemyNum = 10;
	KdTexture EnemyTex;
	Math::Vector2 m_pos[EnemyNum];
	Math::Vector2 m_move[EnemyNum];
	Math::Vector2 m_scale[EnemyNum];
	Math::Matrix Mat[EnemyNum];
	Math::Matrix ScaleMat[EnemyNum];
	Math::Matrix TransMat[EnemyNum];
	bool aliveFlg[EnemyNum];
	float AnimCnt[EnemyNum];
};