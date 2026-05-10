#include "ResultScene.h"
#include"SceneManager.h"

void ResultScene::Init()
{
	stage[0].m_pos = { -300,200 };
	stage[0].m_scale = { 6,6 };
	stage[1].m_pos = { -200,200 };
	stage[1].m_scale = { 6,6 };
	stage[2].m_pos = { -100,200 };
	stage[2].m_scale = { 6,6 };
	stage[3].m_pos = { 0,200 };
	stage[3].m_scale = { 6,6 };
	stage[4].m_pos = { 100,200 };
	stage[4].m_scale = { 6,6 };

	number.m_pos = { 230,200 };
	number.m_scale = { 10,10 };

	clear[0].m_pos = { -200,130 };	//g
	clear[0].m_scale = { 6,6 };
	clear[1].m_pos = { -100,130 };	//a
	clear[1].m_scale = { 6,6 };
	clear[2].m_pos = { 0,130 };		//m
	clear[2].m_scale = { 6,6 };
	clear[3].m_pos = { 100,130 };	//e
	clear[3].m_scale = { 6,6 };
	clear[4].m_pos = { -250,0 };	//c
	clear[4].m_scale = { 6,6 };
	clear[5].m_pos = { -150,0 };	//l
	clear[5].m_scale = { 6,6 };
	clear[6].m_pos = { -50,0 };		//e
	clear[6].m_scale = { 6,6 };
	clear[7].m_pos = { 50,0 };		//a
	clear[7].m_scale = { 6,6 };
	clear[8].m_pos = { 150,0 };		//r
	clear[8].m_scale = { 6,6 };

	game[0].m_pos = { -350,0 };
	game[0].m_scale = { 6,6 };
	game[1].m_pos = { -250,0 };
	game[1].m_scale = { 6,6 };
	game[2].m_pos = { -150,0 };
	game[2].m_scale = { 6,6 };
	game[3].m_pos = { -50,0 };
	game[3].m_scale = { 6,6 };
	game[4].m_pos = { 50,0 };
	game[4].m_scale = { 6,6 };
	game[5].m_pos = { 150,0 };
	game[5].m_scale = { 6,6 };
	game[6].m_pos = { 250,0 };
	game[6].m_scale = { 6,6 };
	game[7].m_pos = { 350,0 };
	game[7].m_scale = { 6,6 };

	title.m_pos = { -80,-200 };
	title.m_scale = { 0.7,0.7 };

	m_mojiTex.Load("Texture/Antiquity_SpriteSheet.png");
	m_numTex.Load("Texture/Number.png");
	m_titleTex.Load("Texture/totitle.png");
}

void ResultScene::Update(int stagePos, bool result)
{
	for (int m = 0;m < stageNum;++m)
	{
		stage[m].m_TransMat = Math::Matrix::CreateTranslation(stage[m].m_pos.x, stage[m].m_pos.y, 0);
		stage[m].m_SacleMat = Math::Matrix::CreateScale(stage[m].m_scale.x, stage[m].m_scale.y, 1);
		stage[m].m_Mat = stage[m].m_SacleMat * stage[m].m_TransMat;
	}

	number.m_TransMat = Math::Matrix::CreateTranslation(number.m_pos.x, number.m_pos.y, 0);
	number.m_SacleMat = Math::Matrix::CreateScale(number.m_scale.x, number.m_scale.y, 1);
	number.m_Mat = number.m_SacleMat * number.m_TransMat;

	for (int m = 0;m < clearNum;++m)
	{
		clear[m].m_TransMat = Math::Matrix::CreateTranslation(clear[m].m_pos.x, clear[m].m_pos.y, 0);
		clear[m].m_SacleMat = Math::Matrix::CreateScale(clear[m].m_scale.x, clear[m].m_scale.y, 1);
		clear[m].m_Mat = clear[m].m_SacleMat * clear[m].m_TransMat;
	}

	for (int m = 0;m < gameoverNum;++m)
	{
		game[m].m_TransMat = Math::Matrix::CreateTranslation(game[m].m_pos.x, game[m].m_pos.y, 0);
		game[m].m_SacleMat = Math::Matrix::CreateScale(game[m].m_scale.x, game[m].m_scale.y, 1);
		game[m].m_Mat = game[m].m_SacleMat * game[m].m_TransMat;
	}

	title.m_TransMat = Math::Matrix::CreateTranslation(title.m_pos.x, title.m_pos.y, 0);
	title.m_SacleMat = Math::Matrix::CreateScale(title.m_scale.x, title.m_scale.y, 1);
	title.m_Mat = title.m_SacleMat * title.m_TransMat;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		SCENEMANAGER.ChangeState(new TitleScene());
		SCENEMANAGER.Init();
		return;
	}
}

void ResultScene::Draw(int stagePos, bool result)
{
	if (result == false)
	{
		switch (stagePos)
		{
		case 1:
			SHADER.m_spriteShader.SetMatrix(game[0].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[1].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[2].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(208, 16, 15, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[3].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[4].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(32, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[5].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(144, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[6].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[7].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 36, 13, 16), 1.0f);

			SHADER.m_spriteShader.SetMatrix(stage[0].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(96, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[1].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[2].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[3].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[4].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);

			SHADER.m_spriteShader.SetMatrix(number.m_Mat);//行列のセット
			SHADER.m_spriteShader.DrawTex(&m_numTex, Math::Rectangle(12, 0, 4, 9), 1.0f);//画像の描画
			break;
		case 2:
			SHADER.m_spriteShader.SetMatrix(game[0].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[1].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[2].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(208, 16, 15, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[3].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[4].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(32, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[5].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(144, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[6].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[7].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 36, 13, 16), 1.0f);

			SHADER.m_spriteShader.SetMatrix(stage[0].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(96, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[1].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[2].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[3].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[4].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);

			SHADER.m_spriteShader.SetMatrix(number.m_Mat);//行列のセット
			SHADER.m_spriteShader.DrawTex(&m_numTex, Math::Rectangle(18, 0, 8, 9), 1.0f);//画像の描画
			break;
		case 3:
			SHADER.m_spriteShader.SetMatrix(game[0].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[1].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[2].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(208, 16, 15, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[3].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[4].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(32, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[5].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(144, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[6].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(game[7].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 36, 13, 16), 1.0f);

			SHADER.m_spriteShader.SetMatrix(stage[0].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(96, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[1].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 36, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[2].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[3].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 16, 13, 16), 1.0f);
			SHADER.m_spriteShader.SetMatrix(stage[4].m_Mat);
			SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);

			SHADER.m_spriteShader.SetMatrix(number.m_Mat);//行列のセット
			SHADER.m_spriteShader.DrawTex(&m_numTex, Math::Rectangle(28,0,7,9), 1.0f);//画像の描画
			break;
		default:
			break;
		}
	}
	else
	{
		SHADER.m_spriteShader.SetMatrix(clear[0].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(112, 16, 13, 16), 1.0f);
		SHADER.m_spriteShader.SetMatrix(clear[1].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
		SHADER.m_spriteShader.SetMatrix(clear[2].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(208, 16, 15, 16), 1.0f);
		SHADER.m_spriteShader.SetMatrix(clear[3].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);
		SHADER.m_spriteShader.SetMatrix(clear[4].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(48, 16, 14, 16), 1.0f);
		SHADER.m_spriteShader.SetMatrix(clear[5].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(192, 16, 14, 16), 1.0f);
		SHADER.m_spriteShader.SetMatrix(clear[6].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 16, 13, 16), 1.0f);
		SHADER.m_spriteShader.SetMatrix(clear[7].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(16, 16, 13, 16), 1.0f);
		SHADER.m_spriteShader.SetMatrix(clear[8].m_Mat);
		SHADER.m_spriteShader.DrawTex(&m_mojiTex, Math::Rectangle(80, 36, 13, 16), 1.0f);
	}
	SHADER.m_spriteShader.SetMatrix(title.m_Mat);
	SHADER.m_spriteShader.DrawTex(&m_titleTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
}

void ResultScene::Release()
{
	m_mojiTex.Release();
	m_numTex.Release();
}
