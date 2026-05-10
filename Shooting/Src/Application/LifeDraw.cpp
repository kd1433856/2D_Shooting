#include "LifeDraw.h"

void LifeDraw::Init()
{
	m_lifeTex.Load("Texture/spritesheet.png");
	life[0].m_pos = { -600,320 };
	life[1].m_pos = { -540,320 };
	life[2].m_pos = { -480,320 };
	m_Hp = 0;
}

void LifeDraw::Update()
{
	life[0].m_Trans = Math::Matrix::CreateTranslation(life[0].m_pos.x, life[0].m_pos.y, 0);
	life[0].m_Scale = Math::Matrix::CreateScale(3, 3, 0);
	life[0].m_Mat = life[0].m_Scale * life[0].m_Trans;

	life[1].m_Trans = Math::Matrix::CreateTranslation(life[1].m_pos.x, life[1].m_pos.y, 0);
	life[1].m_Scale = Math::Matrix::CreateScale(3, 3, 0);
	life[1].m_Mat = life[1].m_Scale * life[1].m_Trans;

	life[2].m_Trans = Math::Matrix::CreateTranslation(life[2].m_pos.x, life[2].m_pos.y, 0);
	life[2].m_Scale = Math::Matrix::CreateScale(3, 3, 0);
	life[2].m_Mat = life[2].m_Scale * life[2].m_Trans;
}

void LifeDraw::Draw()
{
	switch (m_Hp)
	{
	case 12:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 11:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 96,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 10:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 160,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 9:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 224,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 8:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 7:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 96,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 6:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 160,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 5:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 224,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 4:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 16,81,16,14 }, 1.0f);
		break;
	case 3:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 96,81,16,14 }, 1.0f);
		break;
	case 2:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 160,81,16,14 }, 1.0f);
		break;
	case 1:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 224,81,16,14 }, 1.0f);
		break;
	case 0:
		SHADER.m_spriteShader.SetMatrix(life[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		SHADER.m_spriteShader.SetMatrix(life[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_lifeTex, Math::Rectangle{ 304,81,16,14 }, 1.0f);
		break;
	default:
		break;
	}
}

void LifeDraw::Release()
{
	m_lifeTex.Release();
}
