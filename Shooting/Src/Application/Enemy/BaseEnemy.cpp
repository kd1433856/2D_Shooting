#include "BaseEnemy.h"

void BaseEnemy::Init()
{
}

void BaseEnemy::Update()
{
	for(int e=0;e<EnemyNum;e++)
	{
		m_pos[e] += m_move[e];

		TransMat[e] = Math::Matrix::CreateTranslation(m_pos[e].x, m_pos[e].y, 0);
		ScaleMat[e] = Math::Matrix::CreateScale(m_scale[e].x, m_scale[e].y, 1);
		Mat[e] = ScaleMat[e] * TransMat[e];
	}
}

void BaseEnemy::Draw()
{
}
