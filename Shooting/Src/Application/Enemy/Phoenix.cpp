#include "Phoenix.h"

void Phoenix::Init()
{
	for(int e=0;e<EnemyNum;e++)
	{
		m_pos[e].x = rand() % 601 + 1280;
		//m_pos[e].x = 200;
		m_pos[e].y = rand() % 721 - 360;
		//m_pos[e].y = 0;
		m_move[e] = {-6,0};
		//m_move[e] = {0,0};
		m_scale[e] = {-2.5,2.5};
		aliveFlg[e] = true;
		AnimCnt[e] = 0;
	}

	EnemyTex.Load("Texture/Phoenixling Sprite Sheet.png");
}

void Phoenix::Action()
{
	for(int e=0;e<EnemyNum;e++)
	{
		if (aliveFlg[e] == true)
		{
			AnimCnt[e] += 0.3f;
			if (AnimCnt[e] > 4)
			{
				AnimCnt[e] = 0;
			}

			if (m_pos[e].x < -640 - (32 * 2.5))
			{
				m_pos[e].x = rand() % 401 + 1260;
				m_pos[e].y = rand() % 721 - 360;
			}
		}
	}
}

void Phoenix::Update()
{
	for (int e = 0;e < EnemyNum;e++)
	{
		if (aliveFlg[e] == true)
		{
			m_pos[e] += m_move[e];

			TransMat[e] = Math::Matrix::CreateTranslation(m_pos[e].x, m_pos[e].y, 0);
			ScaleMat[e] = Math::Matrix::CreateScale(m_scale[e].x, m_scale[e].y, 1);
			Mat[e] = ScaleMat[e] * TransMat[e];
		}
	}
}

void Phoenix::Draw()
{
	for (int e = 0;e < EnemyNum;e++)
	{
		if(aliveFlg[e] == true)
		{
			SHADER.m_spriteShader.SetMatrix(Mat[e]);
			SHADER.m_spriteShader.DrawTex(&EnemyTex, Math::Rectangle(64 * (int)AnimCnt[e], 64, 64, 64), 1.0f);
		}
	}
}

void Phoenix::Release()
{
	EnemyTex.Release();
}

void Phoenix::B_PhoenixHit(int e)
{
	aliveFlg[e] = false;
}

bool Phoenix::GetAliveFlg(int e)
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
