#include "Ghost.h"

void Ghost::Init()
{
	for (int g = 0;g < GhostNum;++g)
	{
		m_pos[g].x = rand() % 241 + 400;
		m_pos[g].y = rand() % 593 - 296;
		m_move[g].x = rand() % 21 - 10;
		m_move[g].y = rand() % 21 - 10;
		m_scale[g] = { 2.0,2.0 };
		aliveFlg[g] = true;
		AnimCnt[g] = 0;
	}

	EnemyTex.Load("Texture/ghost-Sheet.png");
}

void Ghost::Action()
{
	for (int g = 0;g < GhostNum;++g)
	{
		AnimCnt[g] += 0.3f;
		if (AnimCnt[g] > 4)
		{
			AnimCnt[g] = 0;
		}

		if (m_pos[g].x <= -620)
		{
			m_move[g].x = rand() % 11;
		}
		if (m_pos[g].x >= 620)
		{
			m_move[g].x = -(rand() % 11);
		}
		if (m_pos[g].y <= -340)
		{
			m_move[g].y = rand() % 11;
		}
		if (m_pos[g].y >= 340)
		{
			m_move[g].y = -(rand() % 11);
		}
	}
}

void Ghost::Update()
{
	for (int g = 0;g < GhostNum;++g)
	{
		if (aliveFlg[g] == true)
		{
			m_pos[g] += m_move[g];

			TransMat[g] = Math::Matrix::CreateTranslation(m_pos[g].x, m_pos[g].y, 0);
			ScaleMat[g] = Math::Matrix::CreateScale(m_scale[g].x, m_scale[g].y, 1);
			Mat[g] = ScaleMat[g] * TransMat[g];
		}
	}
}

void Ghost::Draw()
{
	for (int g = 0;g < GhostNum;++g)
	{
		if (aliveFlg[g] == true)
		{
			SHADER.m_spriteShader.SetMatrix(Mat[g]);
			SHADER.m_spriteShader.DrawTex(&EnemyTex, Math::Rectangle(32 * (int)AnimCnt[g], 0, 32, 32), 1.0f);
		}
	}
}

void Ghost::Release()
{
	EnemyTex.Release();
}

bool Ghost::GetAliveFlg(int e)
{
	if (aliveFlg[e] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
