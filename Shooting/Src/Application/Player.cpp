#include "Player.h"

void Player::Init()
{
	player.pos = { -400,0 };
	player.move = { 0,0 };
	player.scale = { 1.5,1.5 };
	player.alpha = 1.0f;
	player.AnimCnt = 0.0f;
	player.aliveFlg = true;
	shotWait = 0;
	stunWait = 0;
	iceWait = 0;
	bleedWait = 0;
	movespeed = 5;
	slowmove = 0;
	m_score = 0;
	//m_score = 2000;
	//m_score = 5000;
	//m_score = 8000;
	Hp = 12;
	HpDownFlg = true;
	HpDownTime = 0;
	BoxInit();
	FunnelInit();
	StunInit();
	SlowInit();
	SilenceInit();
	IceInit();
	BleedInit();
	CharmInit();
	BulletInit();
	FunnelBulletInit();

	CharaTex.Load("Texture/WitchFlying.png");
}

void Player::Update()
{
	player.move = { 0,0 };
	player.AnimCnt += 0.15f;
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

	if (slow.aliveFlg == false)
	{
		slowmove = 0;
	}
	else
	{
		slowmove = 2;
	}

	if (player.pos.x <= -600)player.pos.x = -600;
	if (player.pos.x >= 600)player.pos.x = 600;
	if (player.pos.y <= -320)player.pos.y = -320;
	if (player.pos.y >= 330)player.pos.y = 330;

	if (ice.aliveFlg == false)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if (stun.aliveFlg == false)
			{
				player.move.y = (movespeed - slowmove);
			}
			else
			{
				player.move.y = -(movespeed - slowmove);
			}
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (stun.aliveFlg == false)
			{
				player.move.x = -(movespeed - slowmove);
				player.scale.x = -1.5;
			}
			else
			{
				player.move.x = (movespeed - slowmove);
				player.scale.x = 1.5;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (stun.aliveFlg == false)
			{
				player.move.y = -(movespeed - slowmove);
			}
			else
			{
				player.move.y = (movespeed - slowmove);
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			if (stun.aliveFlg == false)
			{
				player.move.x = (movespeed - slowmove);
				player.scale.x = 1.5;
			}
			else
			{
				player.move.x = -(movespeed - slowmove);
				player.scale.x = -1.5;
			}
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (box.aliveFlg == false && silence.aliveFlg == false)
			{
				if (shotWait <= 0)
				{
					for (int b = 0;b < BulletNum;b++)
					{
						if (bullet[b].aliveFlg == false)
						{
							bullet[b].aliveFlg = true;
							bullet[b].alpha = 1.0f;
							if (player.scale.x > 0)
							{
								bullet[b].move.x = 10;
								bullet[b].scale.x = 1.5f;
							}
							else
							{
								bullet[b].move.x = -10;
								bullet[b].scale.x = -1.5f;
							}
							bullet[b].pos = player.pos;
							break;
						}
					}
					shotWait = 15;
				}
			}
		}
	}

	if (shotWait > 0)
	{
		shotWait--;
	}

	if (stun.aliveFlg == true)
	{
		stunWait--;
		if (stunWait < 0)
		{
			stun.aliveFlg = false;
		}
	}

	if (slow.aliveFlg == true)
	{
		slowWait--;
		if (slowWait < 0)
		{
			slow.aliveFlg = false;
		}
	}

	if (silence.aliveFlg == true)
	{
		silenceWait--;
		if (silenceWait < 0)
		{
			silence.aliveFlg = false;
		}
	}

	if (ice.aliveFlg == true)
	{
		iceWait--;
		if (iceWait < 0)
		{
			ice.aliveFlg = false;
		}
	}

	if (bleed.aliveFlg == true)
	{
		bleedWait--;
		if (bleedWait < 0)
		{
			bleed.aliveFlg = false;
		}
	}

	if (charm.aliveFlg == true)
	{
		charmWait--;
		if (charmWait < 0)
		{
			charm.aliveFlg = false;
		}
	}

	if (ice.aliveFlg == false && silence.aliveFlg == false)
	{
		if (GetAsyncKeyState('S') & 0x8000)
		{
			box.aliveFlg = true;
		}
		else
		{
			box.aliveFlg = false;
		}
	}

	if (HpDownTime > 0)
	{
		HpDownTime--;
		if (HpDownTime <= 0)
		{
			HpDownFlg = true;
		}
	}

	if (Hp <= 0)
	{
		Hp = 0;
		player.aliveFlg = false;
	}

	player.pos += player.move;

	player.TransMat = Math::Matrix::CreateTranslation(player.pos.x, player.pos.y, 0);
	player.ScaleMat = Math::Matrix::CreateScale(player.scale.x, player.scale.y, 1);
	player.Mat = player.ScaleMat * player.TransMat;

	BoxUpdate();
	FunnelUpdate();
	StunUpdate();
	SlowUpdate();
	IceUpdate();
	SilenceUpdate();
	BleedUpdate();
	CharmUpdate();
	BulletUpdate();
	FunnelBulletUpdate();
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(player.Mat);
	//const Math::Color color = { RGB_r,RGB_g,RGB_b,player.alpha };
	SHADER.m_spriteShader.DrawTex(&CharaTex, Math::Rectangle{ 48 * (int)player.AnimCnt,0,48,64 }, 1.0f);
	BoxDraw();
	FunnelDraw();
	StunDraw();
	SlowDraw();
	SilenceDraw();
	IceDraw();
	BleedDraw();
	CharmDraw();
	BulletDraw();
	FunnelBulletDraw();
}

void Player::Release()
{
	CharaTex.Release();
	BoxTex.Release();
	FunnelTex.Release();
	StunTex.Release();
	BulletTex.Release();
	IceTex.Release();
	SlowTex.Release();
	BleedTex.Release();
	CharmTex.Release();
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

	if (ice.aliveFlg == false)
	{
		if (GetAsyncKeyState('A') & 0x8000)
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
		}

		if (box.aliveFlg == false && silence.aliveFlg == false)
		{
			if (funnelWait <= 0)
			{
				for (int b = 0;b < FunnelBulletNum;b++)
				{
					if (fbullet[b].aliveFlg == false)
					{
						fbullet[b].aliveFlg = true;
						fbullet[b].move.x = 10;
						fbullet[b].pos = funnel.pos;
						break;
					}
				}
				funnelWait = 20;
			}

			if (funnelWait > 0)
			{
				funnelWait--;
			}
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
	stun.scale = { 2.5,2.5 };
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

void Player::SlowInit()
{
	slow.pos = { 0,0 };
	slow.move = { 0,0 };
	slow.scale = { 2.5,2.5 };
	slow.alpha = 1.0f;
	slow.aliveFlg = false;
	slow.AnimCnt = 0.0f;
	slowAnimY = 0;

	SlowTex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/SlowEffect/Spritesheets/SlowEffect_Sheet_64x64.png");
}

void Player::SlowUpdate()
{
	slow.AnimCnt += 0.15f;
	if (slow.AnimCnt > 4)
	{
		slow.AnimCnt = 0;
		slowAnimY += 1;
		if (slowAnimY > 4)
		{
			slowAnimY = 0;
		}
	}

	slow.pos = player.pos;

	slow.TransMat = Math::Matrix::CreateTranslation(slow.pos.x, slow.pos.y, 0);
	slow.ScaleMat = Math::Matrix::CreateScale(slow.scale.x, slow.scale.y, 1);
	slow.Mat = slow.ScaleMat * slow.TransMat;
}

void Player::SlowDraw()
{
	if (slow.aliveFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(slow.Mat);
		SHADER.m_spriteShader.DrawTex(&SlowTex, Math::Rectangle{ 64 * (int)slow.AnimCnt,64 * (int)slowAnimY,64,64 }, slow.alpha);
	}
}

void Player::SilenceInit()
{
	silence.pos = { 0,0 };
	silence.move = { 0,0 };
	silence.scale = { 2.5,2.5 };
	silence.alpha = 1.0f;
	silence.aliveFlg = false;
	silence.AnimCnt = 0.0f;
	silenceAnimY = 0;

	SilenceTex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/SilenceEffect/Spritesheets/SilenceEffect_Sheet_64x64.png");
}

void Player::SilenceUpdate()
{
	silence.AnimCnt += 0.15f;
	if (silence.AnimCnt > 4)
	{
		silence.AnimCnt = 0;
		silenceAnimY += 1;
		if (silenceAnimY > 4)
		{
			silenceAnimY = 0;
		}
	}

	silence.pos = player.pos;

	silence.TransMat = Math::Matrix::CreateTranslation(silence.pos.x, silence.pos.y, 0);
	silence.ScaleMat = Math::Matrix::CreateScale(silence.scale.x, silence.scale.y, 1);
	silence.Mat = silence.ScaleMat * silence.TransMat;
}

void Player::SilenceDraw()
{
	if (silence.aliveFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(silence.Mat);
		SHADER.m_spriteShader.DrawTex(&SilenceTex, Math::Rectangle{ 64 * (int)silence.AnimCnt,64 * (int)silenceAnimY,64,64 }, silence.alpha);
	}
}

void Player::IceInit()
{
	ice.pos = { 0,0 };
	ice.move = { 0,0 };
	ice.scale = { 2.5,2.5 };
	ice.alpha = 1.0f;
	ice.aliveFlg = false;
	ice.AnimCnt = 0.0f;
	iceAnimY = 0;

	IceTex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/FreezeEffect/Spritesheets/FreezeEffect_Sheet_64x64.png");
}

void Player::IceUpdate()
{
	ice.AnimCnt += 0.15f;
	if (ice.AnimCnt > 4)
	{
		ice.AnimCnt = 0;
		iceAnimY += 1;
		if (iceAnimY > 4)
		{
			iceAnimY = 0;
		}
	}

	ice.pos = player.pos;

	ice.TransMat = Math::Matrix::CreateTranslation(ice.pos.x, ice.pos.y, 0);
	ice.ScaleMat = Math::Matrix::CreateScale(ice.scale.x, ice.scale.y, 1);
	ice.Mat = ice.ScaleMat * ice.TransMat;
}

void Player::IceDraw()
{
	if (ice.aliveFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(ice.Mat);
		SHADER.m_spriteShader.DrawTex(&IceTex, Math::Rectangle{ 64 * (int)ice.AnimCnt,64 * (int)iceAnimY,64,64 }, ice.alpha);
	}
}

void Player::BleedInit()
{
	bleed.pos = { 0,0 };
	bleed.move = { 0,0 };
	bleed.scale = { 2.5,2.5 };
	bleed.alpha = 1.0f;
	bleed.aliveFlg = false;
	bleed.AnimCnt = 0.0f;
	bleedAnimY = 0;

	BleedTex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/BleedEffect/Spritesheets/BleedEffect_Sheet_64x64.png");
}

void Player::BleedUpdate()
{
	bleed.AnimCnt += 0.15f;
	if (bleed.AnimCnt > 4)
	{
		bleed.AnimCnt = 0;
		bleedAnimY += 1;
		if (bleedAnimY > 4)
		{
			bleedAnimY = 0;
		}
	}

	bleed.pos = player.pos;

	bleed.TransMat = Math::Matrix::CreateTranslation(bleed.pos.x, bleed.pos.y, 0);
	bleed.ScaleMat = Math::Matrix::CreateScale(bleed.scale.x, bleed.scale.y, 1);
	bleed.Mat = bleed.ScaleMat * bleed.TransMat;
}

void Player::BleedDraw()
{
	if (bleed.aliveFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(bleed.Mat);
		SHADER.m_spriteShader.DrawTex(&BleedTex, Math::Rectangle{ 64 * (int)bleed.AnimCnt,64 * (int)bleedAnimY,64,64 }, bleed.alpha);
	}
}

void Player::CharmInit()
{
	charm.pos = { 0,0 };
	charm.move = { 0,0 };
	charm.scale = { 2.5,2.5 };
	charm.alpha = 1.0f;
	charm.aliveFlg = false;
	charm.AnimCnt = 0.0f;
	charmAnimY = 0;

	CharmTex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/CharmEffect/Spritesheets/CharmEffect_Sheet_64x64.png");
}

void Player::CharmUpdate()
{
	charm.AnimCnt += 0.15f;
	if (charm.AnimCnt > 4)
	{
		charm.AnimCnt = 0;
		charmAnimY += 1;
		if (charmAnimY > 4)
		{
			charmAnimY = 0;
		}
	}

	charm.pos = player.pos;

	charm.TransMat = Math::Matrix::CreateTranslation(charm.pos.x, charm.pos.y, 0);
	charm.ScaleMat = Math::Matrix::CreateScale(charm.scale.x, charm.scale.y, 1);
	charm.Mat = charm.ScaleMat * charm.TransMat;
}

void Player::CharmDraw()
{
	if (charm.aliveFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(charm.Mat);
		SHADER.m_spriteShader.DrawTex(&CharmTex, Math::Rectangle{ 64 * (int)charm.AnimCnt,64 * (int)charmAnimY,64,64 }, charm.alpha);
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
				bullet[b].alpha = 0.0f;
			}

			bullet[b].pos.x += bullet[b].move.x;

			bullet[b].TransMat = Math::Matrix::CreateTranslation(bullet[b].pos.x, bullet[b].pos.y, 0);
			bullet[b].ScaleMat = Math::Matrix::CreateScale(bullet[b].scale.x, bullet[b].scale.y, 1);
			bullet[b].Mat = bullet[b].ScaleMat * bullet[b].TransMat;
		}
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

void Player::PlayerPhoenixHit()
{
	stun.aliveFlg = true;
	stunWait = 180;
	if (HpDownFlg == true)
	{
		Hp--;
		HpDownFlg = false;
		HpDownTime = 60;
	}
}

void Player::PlayerEvilHit()
{
	slow.aliveFlg = true;
	slowWait = 180;
	if (HpDownFlg == true)
	{
		Hp--;
		HpDownFlg = false;
		HpDownTime = 60;
	}
}

void Player::PlayerGhostHit()
{
	silence.aliveFlg = true;
	silenceWait = 60;
	if (HpDownFlg == true)
	{
		Hp--;
		HpDownFlg = false;
		HpDownTime = 60;
	}
}

void Player::PlayerBossHit()
{
	stun.aliveFlg = true;
	stunWait = 180;
	if (HpDownFlg == true)
	{
		Hp--;
		HpDownFlg = false;
		HpDownTime = 60;
	}
}

void Player::PlayerBossIceBulletHit()
{
	ice.aliveFlg = true;
	iceWait = 120;
	if (HpDownFlg == true)
	{
		Hp--;
		HpDownFlg = false;
		HpDownTime = 60;
	}
}

void Player::PlayerBossArrowHit()
{
	bleed.aliveFlg = true;
	bleedWait = 30;
	if (HpDownFlg == true)
	{
		Hp--;
		HpDownFlg = false;
		HpDownTime = 30;
	}
}

void Player::PlayerBossRainHit()
{
	charm.aliveFlg = true;
	charmWait = 120;
	if (HpDownFlg == true)
	{
		Hp--;
		HpDownFlg = false;
		HpDownTime = 30;
	}
}

void Player::BulletHit(int b)
{
	if (bullet[b].aliveFlg == true)
	{
		bullet[b].alpha = 0.0f;
		bullet[b].aliveFlg = false;
	}
}

void Player::FBulletHit(int b)
{
	if (fbullet[b].aliveFlg == true)
	{
		fbullet[b].aliveFlg = false;
	}
}

void Player::SetScore()
{
	m_score += 100;
}

bool Player::GetAliveFlg()
{
	if (player.aliveFlg == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::GetGard()
{
	if (box.aliveFlg == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::GetBulletFlg(int b)
{
	if (bullet[b].aliveFlg == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::GetFBulletFlg(int b)
{
	if (fbullet[b].aliveFlg == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::GetCharmFlg()
{
	if (charm.aliveFlg == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
