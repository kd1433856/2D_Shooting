#include "ScoreDraw.h"

void ScoreDraw::Init()
{
	score[0].m_pos = { 70,260 };	//s
	score[0].m_scale = { 4,4 };
	score[1].m_pos = { 110,260 };	//c
	score[1].m_scale = { 4,4 };
	score[2].m_pos = { 150,260 };	//o
	score[2].m_scale = { 4,4 };
	score[3].m_pos = { 190,260 };	//r
	score[3].m_scale = { 3.6,3.6 };
	score[4].m_pos = { 230,260 };	//e
	score[4].m_scale = { 4,4 };
	score[5].m_pos = { 100,320 };	//g
	score[5].m_scale = { 2.3,2.3 };
	score[6].m_pos = { 140,320 };	//o
	score[6].m_scale = { 2.3,2.3 };
	score[7].m_pos = { 180,320 };	//a
	score[7].m_scale = { 2.3,2.3 };
	score[8].m_pos = { 220,320 };	//l
	score[8].m_scale = { 2.3,2.3 };
	m_scoreTex.Load("Texture/Antiquity_SpriteSheet.png");
}

void ScoreDraw::Update()
{
	for (int s = 0;s < scoreNum;++s)
	{
		score[s].transMat = Math::Matrix::CreateTranslation(score[s].m_pos.x, score[s].m_pos.y, 0);
		score[s].scaleMat = Math::Matrix::CreateScale(score[s].m_scale.x, score[s].m_scale.y, 1);
		score[s].Mat = score[s].scaleMat * score[s].transMat;
	}
}

void ScoreDraw::Draw()
{
	SHADER.m_spriteShader.SetMatrix(score[0].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(191, 64, 8, 8), 1.0f);
	SHADER.m_spriteShader.SetMatrix(score[1].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(36, 64, 8, 8), 1.0f);
	SHADER.m_spriteShader.SetMatrix(score[2].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(152, 64, 8, 8), 1.0f);
	SHADER.m_spriteShader.SetMatrix(score[3].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(181, 64, 8, 10), 1.0f);
	SHADER.m_spriteShader.SetMatrix(score[4].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(56, 64, 8, 8), 1.0f);
	SHADER.m_spriteShader.SetMatrix(score[5].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(112, 16, 13, 16), 1.0f);
	SHADER.m_spriteShader.SetMatrix(score[6].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(32, 36, 13, 16), 1.0f);
	SHADER.m_spriteShader.SetMatrix(score[7].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
	SHADER.m_spriteShader.SetMatrix(score[8].Mat);
	SHADER.m_spriteShader.DrawTex(&m_scoreTex, Math::Rectangle(192, 16, 14, 16), 1.0f);
}

void ScoreDraw::Release()
{
	m_scoreTex.Release();
}
