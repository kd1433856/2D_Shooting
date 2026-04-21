#include "chara.h"

void Player::Init()
{
	player.pos = { 0,0 };
	player.move = { 0,0 };
	player.scale = { 1.5,1.5 };
	player.alpha = 1.0f;
	player.AnimCnt = 0.0f;
	RGB_r = 1.0f;
	RGB_g = 1.0f;
	RGB_b = 1.0f;
	RGB_Down = 0.05f;
	movespeed = 5;
	sutanFlg = false;
	GardFlg = false;

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

	if (GardFlg == false)
	{
		movespeed = 5;
	}
	else
	{
		movespeed = 2;
	}

	if (sutanFlg == true)
	{
		RGB_r = 0.8f;
		RGB_g = 0.8f;
		RGB_b += RGB_Down;
		if (RGB_b > 1.0f)
		{
			RGB_b = 1.0f;
			RGB_Down = -0.05f;
		}
		else if (RGB_b < 0)
		{
			RGB_b = 0.0f;
			RGB_Down = 0.05f;
		}
	}
	else
	{
		RGB_r = 1.0f;
		RGB_g = 1.0f;
		RGB_b = 1.0f;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		if (sutanFlg == false)
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
		if (sutanFlg == false)
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
		if (sutanFlg == false)
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
		if (sutanFlg == false)
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

	if (GetAsyncKeyState('P') & 0x8000)
	{
		sutanFlg = true;
	}
	if (GetAsyncKeyState('O') & 0x8000)
	{
		sutanFlg = false;
	}
	if (GetAsyncKeyState('L') & 0x8000)
	{
		GardFlg = true;
	}
	else
	{
		GardFlg = false;
	}

	player.pos += player.move;

	player.TransMat = Math::Matrix::CreateTranslation(player.pos.x, player.pos.y, 0);
	player.ScaleMat = Math::Matrix::CreateScale(player.scale.x, player.scale.y, 1);
	player.Mat = player.ScaleMat * player.TransMat;
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(player.Mat);
	const Math::Color color = { RGB_r,RGB_g,RGB_b,player.alpha };
	SHADER.m_spriteShader.DrawTex_Color(&CharaTex, Math::Rectangle{ 48 * (int)player.AnimCnt,0,48,64 }, color);
}

void Player::Release()
{
	CharaTex.Release();
	BoxTex.Release();
}

void Player::BoxInit()
{
	box.pos = { 0,0 };
	box.move = { 0,0 };
	box.scale = { 5.0,5.0 };
	box.alpha = 1.0f;

	BoxTex.Load("Texture/boxes_SpriteSheet.png");
}

void Player::BoxUpdate()
{
	if (GardFlg == true)
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
