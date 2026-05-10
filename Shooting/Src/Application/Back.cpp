#include "Back.h"

void C_Back::Init()
{
	BackX = 0;

	b1.m_Tex.Load("Texture/_PNG/background1.png");
	b2.m_Tex.Load("Texture/_PNG/background2.png");
	b3.m_Tex.Load("Texture/_PNG/background3.png");
	b4.m_Tex.Load("Texture/_PNG/background4.png");
}

void C_Back::Update()
{
	//背景　スクロール
	BackX -= 5;

	//背景　端
	if (BackX < -1280)
	{
		BackX = 0;
	}

	b1.m_Trans_1 = Math::Matrix::CreateTranslation(BackX, 0, 0);
	b1.m_Trans_2 = Math::Matrix::CreateTranslation(BackX + 1280, 0, 0);
	b1.m_Scale = Math::Matrix::CreateScale(2, 2, 1);
	b1.m_Mat_1 = b1.m_Scale * b1.m_Trans_1;
	b1.m_Mat_2 = b1.m_Scale * b1.m_Trans_2;

	b2.m_Trans_1 = Math::Matrix::CreateTranslation(BackX, 0, 0);
	b2.m_Trans_2 = Math::Matrix::CreateTranslation(BackX + 1280, 0, 0);
	b2.m_Scale = Math::Matrix::CreateScale(2, 2, 1);
	b2.m_Mat_1 = b2.m_Scale * b2.m_Trans_1;
	b2.m_Mat_2 = b2.m_Scale * b2.m_Trans_2;

	b3.m_Trans_1 = Math::Matrix::CreateTranslation(BackX, 0, 0);
	b3.m_Trans_2 = Math::Matrix::CreateTranslation(BackX + 1280, 0, 0);
	b3.m_Scale = Math::Matrix::CreateScale(2, 2, 1);
	b3.m_Mat_1 = b3.m_Scale * b3.m_Trans_1;
	b3.m_Mat_2 = b3.m_Scale * b3.m_Trans_2;

	b4.m_Trans_1 = Math::Matrix::CreateTranslation(BackX, 0, 0);
	b4.m_Trans_2 = Math::Matrix::CreateTranslation(BackX + 1280, 0, 0);
	b4.m_Scale = Math::Matrix::CreateScale(2, 2, 1);
	b4.m_Mat_1 = b4.m_Scale * b4.m_Trans_1;
	b4.m_Mat_2 = b4.m_Scale * b4.m_Trans_2;
}

void C_Back::Draw()
{
	SHADER.m_spriteShader.SetMatrix(b1.m_Mat_1);
	SHADER.m_spriteShader.DrawTex(&b1.m_Tex, Math::Rectangle(0, 0, 640, 360), 1.0f);

	SHADER.m_spriteShader.SetMatrix(b1.m_Mat_2);
	SHADER.m_spriteShader.DrawTex(&b1.m_Tex, Math::Rectangle(0, 0, 640, 360), 1.0f);

	SHADER.m_spriteShader.SetMatrix(b2.m_Mat_1);
	SHADER.m_spriteShader.DrawTex(&b2.m_Tex, Math::Rectangle(0, 0, 640, 360), 1.0f);

	SHADER.m_spriteShader.SetMatrix(b2.m_Mat_2);
	SHADER.m_spriteShader.DrawTex(&b2.m_Tex, Math::Rectangle(0, 0, 640, 360), 1.0f);

	SHADER.m_spriteShader.SetMatrix(b3.m_Mat_1);
	SHADER.m_spriteShader.DrawTex(&b3.m_Tex, Math::Rectangle(0, 0, 640, 360), 1.0f);

	SHADER.m_spriteShader.SetMatrix(b3.m_Mat_2);
	SHADER.m_spriteShader.DrawTex(&b3.m_Tex, Math::Rectangle(0, 0, 640, 360), 1.0f);

	SHADER.m_spriteShader.SetMatrix(b4.m_Mat_1);
	SHADER.m_spriteShader.DrawTex(&b4.m_Tex, Math::Rectangle(0, 0, 640, 360), 1.0f);

	SHADER.m_spriteShader.SetMatrix(b4.m_Mat_2);
	SHADER.m_spriteShader.DrawTex(&b4.m_Tex, Math::Rectangle(0, 0, 640, 360), 1.0f);
}

void C_Back::Release()
{
	b1.m_Tex.Release();
	b2.m_Tex.Release();
	b3.m_Tex.Release();
	b4.m_Tex.Release();
}
