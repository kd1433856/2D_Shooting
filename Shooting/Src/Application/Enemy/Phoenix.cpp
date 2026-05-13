#include "Phoenix.h"

void Phoenix::Init()
{
	for(int e=0;e<EnemyNum;e++)
	{
		m_pos[e].x = rand() % 1201 + 1280;
		//m_pos[e].x = 200;
		m_pos[e].y = rand() % 721 - 360;
		//m_pos[e].y = 0;
		m_move[e] = {-6,0};
		//m_move[e] = {0,0};
		m_scale[e] = {-2.5,2.5};
		aliveFlg[e] = true;
		AnimCnt[e] = 0;
		repop = 0;
	}

	EnemyTex.Load("Texture/Phoenixling Sprite Sheet.png");
	BurnInit();
}

void Phoenix::Action()
{
	for(int e=0;e<EnemyNum;e++)
	{
		repop = rand() % 100 + 1;
		if (aliveFlg[e] == true)
		{
			AnimCnt[e] += 0.3f;
			if (AnimCnt[e] > 4)
			{
				AnimCnt[e] = 0;
			}

			if (m_pos[e].x < -640 - (32 * 2.5))
			{
				aliveFlg[e] = false;
				break;
			}
		}

		if (repop < 20)
		{
			if (aliveFlg[e] == false)
			{
				aliveFlg[e] = true;
				m_pos[e].x = rand() % 1201 + 1260;
				m_pos[e].y = rand() % 721 - 360;
				AnimCnt[e] = 0;
				break;
			}
		}
	}
	BurnUpdate();
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
	BurnDraw();
}

void Phoenix::Release()
{
	EnemyTex.Release();
}

void Phoenix::BurnInit()
{
	for (int b = 0;b < EnemyNum;++b)
	{
		m_expPos[b] = { 0,0 };
		m_expScale[b] = { 1,1 };
		expAnimCnt[b] = 0;
		expAliveFlg[b] = false;
	}
	ExpTex.Load("Texture/Explosion.png");
}

void Phoenix::BurnUpdate()
{
	for (int b = 0;b < EnemyNum;++b)
	{
		if (expAliveFlg[b] == true)
		{
			expAnimCnt[b] += 0.25f;
			if (expAnimCnt[b] > 10)
			{
				expAliveFlg[b] = false;
				expAnimCnt[b] = 0;
				m_expPos[b] = { 1000,1000 };
			}
		}

		m_expTransMat[b] = Math::Matrix::CreateTranslation(m_expPos[b].x, m_expPos[b].y, 0);
		m_expScaleMat[b] = Math::Matrix::CreateScale(m_expScale[b].x, m_expScale[b].y, 1);
		m_expMat[b] = m_expScaleMat[b] * m_expTransMat[b];
	}
}

void Phoenix::BurnDraw()
{
	for (int b = 0;b < EnemyNum;++b)
	{
		if (expAliveFlg[b] == true)
		{
			if (expAnimCnt[b] > 1)
			{
				SHADER.m_spriteShader.SetMatrix(m_expMat[b]);
				SHADER.m_spriteShader.DrawTex(&ExpTex, Math::Rectangle(64 * (int)expAnimCnt[b], 0, 64, 64), 1.0f);
			}
		}
	}
}

void Phoenix::B_PhoenixHit(int e)
{
	aliveFlg[e] = false;
	m_expPos[e] = m_pos[e];
	expAliveFlg[e] = true;
}

void Phoenix::Repop(int e)
{
	aliveFlg[e] = true;
	m_pos[e].x = rand() % 1201 + 1260;
	m_pos[e].y = rand() % 721 - 360;
	AnimCnt[e] = 0;
	expAliveFlg[e] = false;
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
