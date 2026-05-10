#include "Boss.h"

void Boss::Init()
{
	m_pos = { 700,0 };
	m_move = { -5,0 };
	m_scale = { 10,10 };
	aliveFlg = true;
	AnimCnt = 0;
	m_alpha = 1.0f;
	BossHp = 20;
	BossHpDownFlg = true;
	BossHpDownTime = 0;
	ShotRandom = 0;
	ShotArrowRandom = 0;
	ShotRainRandom = 0;
	BossHpHealFlg = true;
	HealCoolTime = 0;

	resultFlg = false;

	BossTex.Load("Texture/VampireAngry.png");
	BulletInit();
	ArrowInit();
	RainInit();
	m_hpPos = { 250,320 };
	m_hpScale = { 12,10 };
	m_HpTex.Load("Texture/BossHp.png");

	m_boxPos = { 250,320 };
	m_boxScale = { 12,10 };
	m_BoxTex.Load("Texture/Book.png");
}

void Boss::Action(int stage)
{
	if (BossHp <= 0)
	{
		aliveFlg = false;
	}
	else
	{
		aliveFlg = true;
	}

	if (BossHp > 20)
	{
		BossHp = 20;
	}

	if (aliveFlg == true)
	{
		ShotRandom = rand() % 100 + 1;
		ShotArrowRandom = rand() % 100 + 1;
		ShotRainRandom = rand() % 100 + 1;
		AnimCnt += 0.2f;
		if (AnimCnt > 16)
		{
			AnimCnt = 0.0f;
		}

		if (m_pos.x <= 500)
		{
			m_pos.x = 500;
			m_move = { 0,0 };
		}

		if (BossHpDownTime > 0)
		{
			BossHpDownTime--;
			if (BossHpDownTime <= 0)
			{
				BossHpDownFlg = true;
			}
		}

		if (HealCoolTime > 0)
		{
			HealCoolTime--;
			if (HealCoolTime <= 0)
			{
				BossHpHealFlg = true;
			}
		}

		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		{
			aliveFlg = false;
		}

		switch (stage)
		{
		case 1:
			if (ShotRandom <= 10)
			{
				for (int b = 0;b < BulletNum;++b)
				{
					if (m_buAliveFlg[b] == false)
					{
						m_buAliveFlg[b] = true;
						break;
					}
				}
			}
			break;
		case 2:
			if (ShotRandom <= 10)
			{
				for (int b = 0;b < BulletNum;++b)
				{
					if (m_buAliveFlg[b] == false)
					{
						m_buAliveFlg[b] = true;
						break;
					}
				}
			}
			if (ShotArrowRandom <= 10)
			{
				for (int a = 0;a < ArrowNum;++a)
				{
					if (m_arAliveFlg[a] == false)
					{
						m_arAliveFlg[a] = true;
						break;
					}
				}
			}
			break;
		case 3:
			if (ShotRandom <= 10)
			{
				for (int b = 0;b < BulletNum;++b)
				{
					if (m_buAliveFlg[b] == false)
					{
						m_buAliveFlg[b] = true;
						break;
					}
				}
			}
			if (ShotArrowRandom <= 10)
			{
				for (int a = 0;a < ArrowNum;++a)
				{
					if (m_arAliveFlg[a] == false)
					{
						m_arAliveFlg[a] = true;
						break;
					}
				}
			}
			if (ShotRainRandom <= 10)
			{
				for (int r = 0;r < RainNum;++r)
				{
					if (m_raAliveFlg[r] == false)
					{
						m_raAliveFlg[r] = true;
						break;
					}
				}
			}
			break;
		default:
			break;
		}
	}
	BulletUpdate();
	ArrowUpdate();
	RainUpdate();

	m_hpTransMat = Math::Matrix::CreateTranslation(m_hpPos.x, m_hpPos.y, 0);
	m_hpScaleMat = Math::Matrix::CreateScale(m_hpScale.x, m_hpScale.y, 1);
	m_hpMat = m_hpScaleMat * m_hpTransMat;
	m_boxTransMat = Math::Matrix::CreateTranslation(m_boxPos.x, m_boxPos.y, 0);
	m_boxScaleMat = Math::Matrix::CreateScale(m_boxScale.x, m_boxScale.y, 1);
	m_boxMat = m_boxScaleMat * m_boxTransMat;
}

void Boss::Update()
{
	if (aliveFlg == true)
	{
		m_pos += m_move;

		TransMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
		ScaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1);
		Mat = ScaleMat * TransMat;
	}
}

void Boss::Draw()
{
	int bossAnime[16] = { 0,32,64,96,128,160,192,224,256,224,192,160,128,96,64,32 };
	SHADER.m_spriteShader.SetMatrix(Mat);
	SHADER.m_spriteShader.DrawTex(&BossTex, Math::Rectangle(bossAnime[(int)AnimCnt], 0, 32, 32), m_alpha);
	BulletDraw();
	ArrowDraw();
	RainDraw();

	SHADER.m_spriteShader.SetMatrix(m_hpMat);
	SHADER.m_spriteShader.DrawTex(&m_HpTex, Math::Rectangle(3 * (20 - BossHp), 0, 60, 3), 1.0f);
	SHADER.m_spriteShader.SetMatrix(m_boxMat);
	SHADER.m_spriteShader.DrawTex(&m_BoxTex, Math::Rectangle(0, 0, 62, 5), 1.0f);
}

void Boss::Release()
{
	BossTex.Release();
}

void Boss::BulletRepop(int b)
{
	ShotRandom = rand() % 100 + 1;
	m_buAliveFlg[b] = false;
	m_buPos[b].x = rand() % 201 + 500;
	m_buPos[b].y = rand() % 681 - 280;
	m_buMove[b].x = 0.0f;
	m_buAlpha[b] = 0.3f;
	m_buAnimCnt[b] = 0.0f;
	m_buAnimY[b] = 0;
}

void Boss::ArrowRepop(int a)
{
	ShotArrowRandom = rand() % 100 + 1;
	m_arAliveFlg[a] = false;
	m_arPos[a].x = rand() % 201 + 800;
	m_arPos[a].y = rand() % 681 - 280;
}

void Boss::B_BossHit(bool charm)
{
	if (BossHpDownFlg == true)
	{
		if(charm==false)
		{
			BossHp--;
		}
		else
		{
			BossHp++;
		}
		BossHpDownFlg = false;
		BossHpDownTime = 60;
	}
}

void Boss::BulletHit(int b)
{
	for (int b = 0;b < BulletNum;++b)
	{
		m_buAliveFlg[b] = false;
		m_buPos[b].x = rand() % 201 + 500;
		m_buPos[b].y = rand() % 681 - 280;
		m_buMove[b].x = 0.0f;
		m_buAlpha[b] = 0.3f;
		m_buAnimCnt[b] = 0.0f;
		m_buAnimY[b] = 0;
		break;
	}
}

void Boss::ArrowHit()
{
	if (BossHpHealFlg == true)
	{
		BossHp++;
		BossHpHealFlg = false;
		HealCoolTime = 30;
	}
}

void Boss::BulletInit()
{
	for (int b = 0;b < BulletNum;++b)
	{
		m_buPos[b].x = rand() % 201 + 500;
		m_buPos[b].y = rand() % 681 - 280;
		//m_buPos[b] = { 500,0 };
		m_buMove[b] = { 0,0 };
		m_buScale[b] = { -5,5 };
		m_buAnimCnt[b] = 0.0f;
		m_buAnimY[b] = 0;
		m_buAlpha[b] = 0.3f;
		m_buAliveFlg[b] = false;
	}
	m_BulletTex.Load("Texture/SnowBall.png");
}

void Boss::BulletUpdate()
{
	for (int b = 0;b < BulletNum;++b)
	{
		if (m_buAliveFlg[b] == true)
		{
			m_buAnimCnt[b] += 0.15f;
			if (m_buAnimCnt[b] > 6)
			{
				if (m_buAnimY[b] != 2)
				{
					m_buAnimY[b]++;
				}
				m_buAnimCnt[b] = 0.0f;
			}

			if (m_buAnimY[b] == 2)
			{
				m_buAlpha[b] += 0.1f;
				if (m_buAlpha[b] > 1)
				{
					m_buAlpha[b] = 1.0f;
				}
				m_buMove[b].x = -8;
			}

			if (m_buPos[b].x <= -700)
			{
				m_buAliveFlg[b] = false;
				m_buPos[b].x = rand() % 201 + 500;
				m_buPos[b].y = rand() % 681 - 280;
				m_buMove[b].x = 0.0f;
				m_buAlpha[b] = 0.3f;
				m_buAnimCnt[b] = 0.0f;
				m_buAnimY[b] = 0;
				break;
			}

			m_buPos[b].x += m_buMove[b].x;

			m_buTransMat[b] = Math::Matrix::CreateTranslation(m_buPos[b].x, m_buPos[b].y, 0);
			m_buScaleMat[b] = Math::Matrix::CreateScale(m_buScale[b].x, m_buScale[b].y, 1);
			m_buMat[b] = m_buScaleMat[b] * m_buTransMat[b];
		}
	}
}

void Boss::BulletDraw()
{
	for (int b = 0;b < BulletNum;++b)
	{
		if (m_buAliveFlg[b] == true)
		{
			SHADER.m_spriteShader.SetMatrix(m_buMat[b]);
			SHADER.m_spriteShader.DrawTex(&m_BulletTex, Math::Rectangle(32 * (int)m_buAnimCnt[b], 32 * m_buAnimY[b], 32, 32), m_buAlpha[b]);
		}
	}
}

void Boss::ArrowInit()
{
	for (int a = 0;a < ArrowNum;++a)
	{
		m_arPos[a].x = rand() % 201 + 800;
		m_arPos[a].y = rand() % 681 - 280;
		m_arMove[a] = { 0,0 };
		m_arScale[a] = { -2.5,2.5 };
		m_arAliveFlg[a] = false;
	}
	m_ArrowTex.Load("Texture/1_0.png");
}

void Boss::ArrowUpdate()
{
	for (int a = 0;a < ArrowNum;++a)
	{
		if (m_arAliveFlg[a] == true)
		{
			m_arMove[a].x = -12;

			if (m_arPos[a].x <= -700)
			{
				m_arAliveFlg[a] = false;
				m_arPos[a].x = rand() % 201 + 800;
				m_arPos[a].y = rand() % 681 - 280;
				break;
			}

			m_arPos[a].x += m_arMove[a].x;

			m_arTransMat[a] = Math::Matrix::CreateTranslation(m_arPos[a].x, m_arPos[a].y, 0);
			m_arScaleMat[a] = Math::Matrix::CreateScale(m_arScale[a].x, m_arScale[a].y, 1);
			m_arMat[a] = m_arScaleMat[a] * m_arTransMat[a];
		}
	}
}

void Boss::ArrowDraw()
{
	for (int a = 0;a < ArrowNum;++a)
	{
		if (m_arAliveFlg[a] == true)
		{
			SHADER.m_spriteShader.SetMatrix(m_arMat[a]);
			SHADER.m_spriteShader.DrawTex(&m_ArrowTex, Math::Rectangle(0,0, 44, 22), 1.0f);
		}
	}
}

void Boss::RainInit()
{
	for (int r = 0;r < RainNum;++r)
	{
		m_raPos[r].x = rand() % 920 - 620;
		m_raPos[r].y = rand() % 301 + 720;
		m_raMove[r] = { 0,-8 };
		m_raScale[r] = { 2,2 };
		m_raAnimCnt[r] = 0.0f;
		m_raAliveFlg[r] = false;
	}
	m_RainTex.Load("Texture/rain.png");
}

void Boss::RainUpdate()
{
	for (int r = 0;r < RainNum;++r)
	{
		if (m_raAliveFlg[r] == true)
		{
			m_raAnimCnt[r] += 0.15f;
			if (m_raAnimCnt[r] > 3)
			{
				m_raAnimCnt[r] = 0.0f;
			}

			if (m_raPos[r].y <= -400)
			{
				m_raAliveFlg[r] = false;
				m_raPos[r].x = rand() % 940 - 640;
				m_raPos[r].y = rand() % 301 + 720;
				break;
			}

			m_raPos[r].y += m_raMove[r].y;

			m_raTransMat[r] = Math::Matrix::CreateTranslation(m_raPos[r].x, m_raPos[r].y, 0);
			m_raScaleMat[r] = Math::Matrix::CreateScale(m_raScale[r].x, m_raScale[r].y, 1);
			m_raMat[r] = m_raScaleMat[r] * m_raTransMat[r];
		}
	}
}

void Boss::RainDraw()
{
	for (int r = 0;r < RainNum;++r)
	{
		if (m_raAliveFlg[r] == true)
		{
			SHADER.m_spriteShader.SetMatrix(m_raMat[r]);
			SHADER.m_spriteShader.DrawTex(&m_RainTex, Math::Rectangle((32 * (int)m_raAnimCnt[r]) + 64, 354, 32, 46), 1.0f);
		}
	}
}

bool Boss::GetAliveFlg()
{
	if (aliveFlg == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Boss::GetResultFlg()
{
	if (resultFlg == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Boss::GetBulletFlg(int b)
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

bool Boss::GetArrowFlg(int a)
{
	if (m_arAliveFlg[a] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Boss::GetRainFlg(int r)
{
	if (m_raAliveFlg[r] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
