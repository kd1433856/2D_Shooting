#include "Evil.h"

void Evil::Init()
{
	for (int e = 0;e < EvilNum;e++)
	{
		m_pos[e].x = rand() % 601 + 1280;
		m_pos[e].y = rand() % 593 - 296;
		m_move[e] = { 0,0 };
		m_scale[e] = { 2.0,2.0 };
		aliveFlg[e] = false;
		AnimCnt[e] = 0;
		EvilmoveFlg[e] = true;
		m_posgap[e] = rand() % 351 - 50;
		m_aliveTime[e] = rand() & 121 + 60;
		EvilOneAliveFlg[e] = true;
	}

	EnemyTex.Load("Texture/EvilBox1.png");
}

void Evil::Action()
{
	for (int e = 0;e < EvilNum;e++)
	{
		if (m_aliveTime[e] > 0)
		{
			m_aliveTime[e]--;
		}

		if (m_aliveTime[e] <= 0)
		{
			if(EvilOneAliveFlg[e]==true)
			{
				aliveFlg[e] = true;
				EvilOneAliveFlg[e] = false;
			}
			m_aliveTime[e] = 0;
		}

		if (aliveFlg[e] == true)
		{
			AnimCnt[e] += 0.2f;
			if (AnimCnt[e] > 22)
			{
				AnimCnt[e] = 0;
			}

			if (m_pos[e].x > 300 + m_posgap[e])
			{
				m_move[e].x = -5;
			}
			else
			{
				m_pos[e].x = 300 + m_posgap[e];
				m_move[e].x = 0;
				if (EvilmoveFlg[e] == true)
				{
					m_move[e].y = rand() % 11 - 5;
					EvilmoveFlg[e] = false;
				}
				if (m_pos[e].y <= -320 || m_pos[e].y >= 320)
				{
					m_move[e].y *= -1;
				}
			}
		}
	}
}

void Evil::Update()
{
	for (int e = 0;e < EvilNum;e++)
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

void Evil::Draw()
{
	for (int e = 0;e < EvilNum;e++)
	{
		if (aliveFlg[e] == true)
		{
			int evilAnime[22] = { 0,32,64,96,128,160,192,224,256,288,320,352,320,288,256,224,192,160,128,96,64,32 };
			SHADER.m_spriteShader.SetMatrix(Mat[e]);
			SHADER.m_spriteShader.DrawTex(&EnemyTex, Math::Rectangle(evilAnime[(int)AnimCnt[e]], 0, 32, 32), 1.0f);
		}
	}
}

void Evil::Release()
{
	EnemyTex.Release();
}
