#include "Phoenix.h"

void Phoenix::Init()
{
	for(int e=0;e<EnemyNum;e++)
	{
		//m_pos[e].x = rand() % 601 + 1280;
		m_pos[e].x = 0;
		//m_pos[e].y = rand() % 721 - 360;
		m_pos[e].y = 0;
		//m_move[e] = {-6,0};
		m_move[e] = {0,0};
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

void Phoenix::B_PhoenixHit()
{
	for (int e = 0;e < EnemyNum;e++)
	{
		aliveFlg[e] = true;
	}
}
