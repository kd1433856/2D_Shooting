#include "Evil.h"

void Evil::Init()
{
	for (int e = 0;e < EvilNum;++e)
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
		ShotFlg[e] = true;
		repop = 0;
	}

	EnemyTex.Load("Texture/EvilBox1.png");

	BurnInit();
	BulletInit();
}

void Evil::Action()
{
	for (int e = 0;e < EvilNum;++e)
	{
		repop = rand() % 100 + 1;
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
			AnimCnt[e] += 0.15f;
			if (AnimCnt[e] > 22)
			{
				ShotFlg[e] = true;
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

				if (AnimCnt[e] > 1 && AnimCnt[e] < 2)
				{
					for (int b = 0;b < EvilBulletNum;++b)
					{
						if (m_buAliveFlg[b] == false)
						{
							if (ShotFlg[e] == true)
							{
								m_buAliveFlg[b] = true;
								m_buPos[b] = m_pos[e];
								m_buMove[b].x = -16;
								ShotFlg[e] = false;
								break;
							}
						}
					}
				}
			}
		}

		if (repop < 20)
		{
			if (aliveFlg[e] == false)
			{
				EvilOneAliveFlg[e] = true;
				m_aliveTime[e] = rand() & 121 + 60;
				m_pos[e].x = rand() % 601 + 1280;
				m_pos[e].y = rand() % 593 - 296;
				m_posgap[e] = rand() % 351 - 50;
				EvilmoveFlg[e] = true;
				m_move[e].y = 0;
				break;
			}
		}
	}
	BurnUpdate();
	BulletUpdate();
}

void Evil::Update()
{
	for (int e = 0;e < EvilNum;++e)
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
	for (int e = 0;e < EvilNum;++e)
	{
		if (aliveFlg[e] == true)
		{
			int evilAnime[22] = { 0,32,64,96,128,160,192,224,256,288,320,352,320,288,256,224,192,160,128,96,64,32 };
			SHADER.m_spriteShader.SetMatrix(Mat[e]);
			SHADER.m_spriteShader.DrawTex(&EnemyTex, Math::Rectangle(evilAnime[(int)AnimCnt[e]], 0, 32, 32), 1.0f);
		}
	}
	BurnDraw();
	BulletDraw();
}

void Evil::Release()
{
	EnemyTex.Release();
	m_BulletTex.Release();
}

void Evil::BurnInit()
{
	for (int b = 0;b < EvilNum;++b)
	{
		m_expPos[b] = { 0,0 };
		m_expScale[b] = { 1,1 };
		expAnimCnt[b] = 0;
		expAliveFlg[b] = false;
	}
	ExpTex.Load("Texture/Explosion.png");
}

void Evil::BurnUpdate()
{
	for (int b = 0;b < EvilNum;++b)
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

void Evil::BurnDraw()
{
	for (int b = 0;b < EvilNum;++b)
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

void Evil::B_EvilHit(int e)
{
	aliveFlg[e] = false;
	m_expPos[e] = m_pos[e];
	expAliveFlg[e] = true;
}

void Evil::Repop(int e)
{
	EvilOneAliveFlg[e] = true;
	m_aliveTime[e] = rand() & 121 + 60;
	m_pos[e].x = rand() % 601 + 1280;
	m_pos[e].y = rand() % 593 - 296;
	m_posgap[e] = rand() % 351 - 50;
	EvilmoveFlg[e] = true;
	m_move[e].y = 0;
	expAliveFlg[e] = false;
}

void Evil::BulletInit()
{
	for (int b = 0;b < EvilBulletNum;++b)
	{
		m_buPos[b] = { 0,0 };
		m_buMove[b] = { 0,0 };
		m_buScale[b] = { -0.75f,0.75f };
		m_buAnimCnt[b] = 0.0f;
		m_buAliveFlg[b] = false;
	}

	m_BulletTex.Load("Texture/EnergyBall.png");
}

void Evil::BulletUpdate()
{
	for (int b = 0;b < EvilBulletNum;++b)
	{
		if (m_buAliveFlg[b] == true)
		{
			m_buAnimCnt[b] += 0.15f;
			if (m_buAnimCnt[b] > 9)
			{
				m_buAnimCnt[b] = 0.0f;
			}

			if (m_buPos[b].x <= -700)
			{
				m_buAliveFlg[b] = false;
				m_buMove[b].x = 0;
				break;
			}

			m_buPos[b].x += m_buMove[b].x;

			m_buTransMat[b] = Math::Matrix::CreateTranslation(m_buPos[b].x, m_buPos[b].y, 0);
			m_buScaleMat[b] = Math::Matrix::CreateScale(m_buScale[b].x, m_buScale[b].y, 1);
			m_buMat[b] = m_buScaleMat[b] * m_buTransMat[b];
		}
	}
}

void Evil::BulletDraw()
{
	for (int b = 0;b < EvilBulletNum;++b)
	{
		if (m_buAliveFlg[b] == true)
		{
			SHADER.m_spriteShader.SetMatrix(m_buMat[b]);
			SHADER.m_spriteShader.DrawTex(&m_BulletTex, Math::Rectangle(128 * (int)m_buAnimCnt[b], 0, 128, 128), 1.0f);
		}
	}
}

bool Evil::GetAliveFlg(int e)
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

bool Evil::GetBulletFlg(int b)
{
	if (m_buAliveFlg[b] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
