#include "chara.h"

void Player::Init()
{
	player.pos = { 0,0 };
	player.move = { 0,0 };
	player.scale = { 1.5,1.5 };
	player.alpha = 1.0f;
	player.AnimCnt = 0.0f;
	player.aliveFlg = true;
	shotWait = 0;
	movespeed = 5;

	CharaTex.Load("Texture/WitchFlying.png");
}

void Player::Update()
{
	player.move = { 0,0 };
	player.AnimCnt+=0.15f;
	if (player.AnimCnt > 6)
	{
		player.AnimCnt = 0;
	}

	if (box.aliveFlg == false)
	{
		movespeed = 5;
	}
	else
	{
		movespeed = 2;
	}

	if (stun.aliveFlg == true)
	{
		StunUpdate();
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		if (stun.aliveFlg == false)
		{
			player.move.y = movespeed;
		}
		else
		{
			player.move.y = -movespeed;
		}
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		if (stun.aliveFlg == false)
		{
			player.move.x = -movespeed;
			player.scale.x = -1.5;
		}
		else
		{
			player.move.x = movespeed;
			player.scale.x = 1.5;
		}
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		if (stun.aliveFlg == false)
		{
			player.move.y = -movespeed;
		}
		else
		{
			player.move.y = movespeed;
		}
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		if (stun.aliveFlg == false)
		{
			player.move.x = movespeed;
			player.scale.x = 1.5;
		}
		else
		{
			player.move.x = -movespeed;
			player.scale.x = -1.5;
		}
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if(shotWait<=0)
		{
			for (int b = 0;b < BulletNum;b++)
			{
				if (bullet[b].aliveFlg == false)
				{
					bullet[b].aliveFlg = true;
					if (player.scale.x > 0)
					{
						bullet[b].move.x = 4;
						bullet[b].scale.x = 1.5f;
					}
					else
					{
						bullet[b].move.x = -4;
						bullet[b].scale.x = -1.5f;
					}
					bullet[b].pos = player.pos;
					break;
				}
			}
			shotWait = 45;
		}
	}

	if (shotWait > 0)
	{
		shotWait--;
	}

	if (GetAsyncKeyState('P') & 0x8000)
	{
		stun.aliveFlg = true;
	}
	if (GetAsyncKeyState('O') & 0x8000)
	{
		stun.aliveFlg = false;
	}
	if (GetAsyncKeyState('L') & 0x8000)
	{
		box.aliveFlg = true;
	}
	else
	{
		box.aliveFlg = false;
	}

	player.pos += player.move;

	player.TransMat = Math::Matrix::CreateTranslation(player.pos.x, player.pos.y, 0);
	player.ScaleMat = Math::Matrix::CreateScale(player.scale.x, player.scale.y, 1);
	player.Mat = player.ScaleMat * player.TransMat;
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(player.Mat);
	//const Math::Color color = { RGB_r,RGB_g,RGB_b,player.alpha };
	SHADER.m_spriteShader.DrawTex(&CharaTex, Math::Rectangle{ 48 * (int)player.AnimCnt,0,48,64 }, 1.0f);
}

void Player::Release()
{
	CharaTex.Release();
	BoxTex.Release();
	FunnelTex.Release();
	StunTex.Release();
}

void Player::BoxInit()
{
	box.pos = { 0,0 };
	box.move = { 0,0 };
	box.scale = { 5.0,5.0 };
	box.alpha = 1.0f;
	box.aliveFlg = false;

	BoxTex.Load("Texture/boxes_SpriteSheet.png");
}

void Player::BoxUpdate()
{
	if (box.aliveFlg == true)
	{
		box.alpha = 1.0f;
	}
	else
	{
		box.alpha = 0.0f;
	}

	box.pos = player.pos;

	box.TransMat = Math::Matrix::CreateTranslation(box.pos.x, box.pos.y - 5, 0);
	box.ScaleMat = Math::Matrix::CreateScale(box.scale.x, box.scale.y, 1);
	box.Mat = box.ScaleMat * box.TransMat;
}

void Player::BoxDraw()
{
	SHADER.m_spriteShader.SetMatrix(box.Mat);
	SHADER.m_spriteShader.DrawTex(&BoxTex, Math::Rectangle{ 18,18,18,18 }, box.alpha);
}

void Player::FunnelInit()
{
	funnel.pos = { 0,0 };
	funnel.move = { 0,0 };
	funnel.scale = { 1.5,1.5 };
	funnel.alpha = 1.0f;
	funnel.AnimCnt = 0.0f;
	funnelWait = 0;
	m_deg = 0;

	rotateFlg = true;
	stopFlg = false;
	starFlg = false;

	FunnelTex.Load("Texture/star1.png");
}

void Player::FunnelUpdate()
{
	funnel.AnimCnt += 0.2f;
	if (funnel.AnimCnt > 13)
	{
		funnel.AnimCnt = 0;
	}

	if (GetAsyncKeyState('K') & 0x8000)
	{

		if (starFlg == true)	//í∑âüÇµñhé~
		{
			//ÉÇÅ[Éhì¸ÇÍë÷Ç¶èàóù
			switch (rotateFlg)
			{
			case	true:
				rotateFlg = false;
				stopFlg = true;
				starFlg = false;
				break;

			case	false:
				rotateFlg = true;
				stopFlg = false;
				starFlg = false;
				break;

			default:
				break;
			}
		}
	}
	else
	{
		starFlg = true;
	}

	if (rotateFlg == true)
	{
		//âÒì]Ç≥ÇπÇÈ
		m_deg += 3;
		funnel.move.x = cos(DirectX::XMConvertToRadians(m_deg)) * 80;
		funnel.move.y = sin(DirectX::XMConvertToRadians(m_deg)) * 80;

		funnel.pos = funnel.move + player.pos;
	}

	if (stopFlg == true)
	{
		funnel.move = { 0,0 };
		funnel.pos += funnel.move;

		if (funnelWait <= 0)
		{
			for (int b = 0;b < FunnelBulletNum;b++)
			{
				if (fbullet[b].aliveFlg == false)
				{
					fbullet[b].aliveFlg = true;
					fbullet[b].move.x = 4;
					fbullet[b].pos = funnel.pos;
					break;
				}
			}
			funnelWait = 60;
		}

		if (funnelWait > 0)
		{
			funnelWait--;
		}
	}

	funnel.TransMat = Math::Matrix::CreateTranslation(funnel.pos.x, funnel.pos.y - 5, 0);
	funnel.ScaleMat = Math::Matrix::CreateScale(funnel.scale.x, funnel.scale.y, 1);
	funnel.Mat = funnel.ScaleMat * funnel.TransMat;
}

void Player::FunnelDraw()
{
	SHADER.m_spriteShader.SetMatrix(funnel.Mat);
	SHADER.m_spriteShader.DrawTex(&FunnelTex, Math::Rectangle{ 32 * (int)funnel.AnimCnt,0,32,32 }, funnel.alpha);
}

void Player::StunInit()
{
	stun.pos = { 0,0 };
	stun.move = { 0,0 };
	stun.scale = { 1.5,1.5 };
	stun.alpha = 1.0f;
	stun.aliveFlg = false;
	stun.AnimCnt = 0.0f;
	stunAnimY = 0;

	StunTex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/StunEffect/Spritesheets/StunEffect_Sheet_64x64.png");
}

void Player::StunUpdate()
{
	stun.AnimCnt += 0.15f;
	if (stun.AnimCnt > 4)
	{
		stun.AnimCnt = 0;
		stunAnimY += 1;
		if (stunAnimY > 4)
		{
			stunAnimY = 0;
		}
	}

	stun.pos = player.pos;

	stun.TransMat = Math::Matrix::CreateTranslation(stun.pos.x, stun.pos.y , 0);
	stun.ScaleMat = Math::Matrix::CreateScale(stun.scale.x, stun.scale.y, 1);
	stun.Mat = stun.ScaleMat * stun.TransMat;
}

void Player::StunDraw()
{
	if (stun.aliveFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(stun.Mat);
		SHADER.m_spriteShader.DrawTex(&StunTex, Math::Rectangle{ 64 * (int)stun.AnimCnt,64 * (int)stunAnimY,64,64 }, stun.alpha);
	}
}

void Player::BulletInit()
{
	for (int b = 0;b < BulletNum;b++)
	{
		bullet[b].pos = { 0,0 };
		bullet[b].move = { 0,0 };
		bullet[b].scale = { 1.5,1.5 };
		bullet[b].alpha = 1.0f;
		bullet[b].AnimCnt = 0.0f;
		bullet[b].aliveFlg = false;
	}

	BulletTex.Load("Texture/Charge1.png");
}

void Player::BulletUpdate()
{
	for (int b = 0;b < BulletNum;b++)
	{
		if (bullet[b].aliveFlg == true)
		{
			bullet[b].AnimCnt += 0.15f;
			if (bullet[b].AnimCnt > 5)
			{
				bullet[b].AnimCnt = 0;
			}

			if (bullet[b].pos.x > 640 || bullet[b].pos.x < -640)
			{
				bullet[b].aliveFlg = false;
			}
		}
		bullet[b].pos.x += bullet[b].move.x;

		bullet[b].TransMat = Math::Matrix::CreateTranslation(bullet[b].pos.x, bullet[b].pos.y, 0);
		bullet[b].ScaleMat = Math::Matrix::CreateScale(bullet[b].scale.x, bullet[b].scale.y, 1);
		bullet[b].Mat = bullet[b].ScaleMat * bullet[b].TransMat;
		
	}
}

void Player::BulletDraw()
{
	for (int b = 0;b < BulletNum;b++)
	{
		if (bullet[b].aliveFlg == true)
		{
			SHADER.m_spriteShader.SetMatrix(bullet[b].Mat);
			SHADER.m_spriteShader.DrawTex(&BulletTex, Math::Rectangle{ 64 * (int)bullet[b].AnimCnt,0,64,64 }, bullet[b].alpha);
		}
	}
}

void Player::FunnelBulletInit()
{
	for (int b = 0;b < FunnelBulletNum;b++)
	{
		fbullet[b].pos = { 0,0 };
		fbullet[b].move = { 0,0 };
		fbullet[b].scale = { 1.0,1.0 };
		fbullet[b].alpha = 1.0f;
		fbullet[b].AnimCnt = 0.0f;
		funneldeg[b] = 0;
		fbullet[b].aliveFlg = false;
	}
}

void Player::FunnelBulletUpdate()
{
	for (int b = 0;b < FunnelBulletNum;b++)
	{
		if (fbullet[b].aliveFlg == true)
		{
			funneldeg[b] += 8;
			if (funneldeg[b] > 360)
			{
				funneldeg[b] = 0;
			}
			fbullet[b].AnimCnt += 0.15f;
			if (fbullet[b].AnimCnt > 5)
			{
				fbullet[b].AnimCnt = 0;
			}

			if (fbullet[b].pos.x > 640)
			{
				fbullet[b].aliveFlg = false;
			}
		}
		fbullet[b].pos.x += fbullet[b].move.x;

		fbullet[b].TransMat = Math::Matrix::CreateTranslation(fbullet[b].pos.x, fbullet[b].pos.y, 0);
		fbullet[b].ScaleMat = Math::Matrix::CreateScale(fbullet[b].scale.x, fbullet[b].scale.y, 1);
		funnelRoteto = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(funneldeg[b]));
		fbullet[b].Mat = funnelRoteto * fbullet[b].ScaleMat * fbullet[b].TransMat;

	}
}

void Player::FunnelBulletDraw()
{
	for (int b = 0;b < FunnelBulletNum;b++)
	{
		if (fbullet[b].aliveFlg == true)
		{
			SHADER.m_spriteShader.SetMatrix(fbullet[b].Mat);
			SHADER.m_spriteShader.DrawTex(&FunnelTex, Math::Rectangle{ 64 * (int)fbullet[b].AnimCnt,0,32,32 }, fbullet[b].alpha);
		}
	}
}
