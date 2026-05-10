#include "TitleScene.h"
#include"SceneManager.h"

void TitleScene::Init()
{
	m_pos = { -700,0 };
	m_move = { 5,0 };
	m_scale = { 1.5,1.5 };
	AnimCnt = 0;
	PlayerTex.Load("Texture/WitchFlying.png");
	TitleTex.Load("Texture/Title.png");
	PressTex.Load("Texture/Press.png");
	back.Init();
}

void TitleScene::Update()
{
	AnimCnt += 0.15f;
	if (AnimCnt > 6)
	{
		AnimCnt = 0;
	}

	if (m_pos.x > 720)
	{
		m_move.x = -5;
		m_scale.x = -1.5f;
	}
	if (m_pos.x < -720)
	{
		m_move.x = 5;
		m_scale.x = 1.5f;
	}

	m_pos += m_move;

	m_TransMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_ScaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 1);
	m_Mat = m_ScaleMat * m_TransMat;

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		SCENEMANAGER.ChangeState(new TutorialScene());
		SCENEMANAGER.Init();
		return;
	}

	TitleTrans = Math::Matrix::CreateTranslation(0, 200, 0);
	TitleScale = Math::Matrix::CreateScale(1, 1, 1);
	TitleMat = TitleScale * TitleTrans;

	PressTrans = Math::Matrix::CreateTranslation(0, -280, 0);
	PressScale = Math::Matrix::CreateScale(1, 1, 1);
	PressMat = PressScale * PressTrans;

	back.Update();
}

void TitleScene::Draw()
{
	back.Draw();

	SHADER.m_spriteShader.SetMatrix(m_Mat);
	SHADER.m_spriteShader.DrawTex(&PlayerTex, Math::Rectangle(48 * (int)AnimCnt, 0, 48, 64), 1.0f);

	SHADER.m_spriteShader.SetMatrix(TitleMat);
	SHADER.m_spriteShader.DrawTex(&TitleTex, Math::Rectangle(0, 0, 1280, 200), 1.0f);

	SHADER.m_spriteShader.SetMatrix(PressMat);
	SHADER.m_spriteShader.DrawTex(&PressTex, Math::Rectangle(0, 0, 1280, 200), 1.0f);
}

void TitleScene::Release()
{
	TitleTex.Release();
	PressTex.Release();
	back.Release();
}
