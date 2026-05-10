#include "TutorialScene.h"
#include"SceneManager.h"

void TutorialScene::Init()
{
	expNum = 1;
	expFlg = false;
	arrow[0].m_pos = { -500,-300 };	//←
	arrow[0].m_scale = { 5,5 };
	arrow[1].m_pos = { 500,-300 };	//→
	arrow[1].m_scale = { 5,5 };

	back.Init();
	Exp1Init();
	Exp2Init();
	Exp3Init();
	Exp4Init();
}

void TutorialScene::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (expFlg == false)
		{
			expFlg = true;
			switch (expNum)
			{
			case 2:
				expNum = 1;
				break;
			case 3:
				expNum = 2;
				break;
			case 4:
				expNum = 3;
				break;
			default:
				break;
			}
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (expFlg == false)
		{
			expFlg = true;
			switch (expNum)
			{
			case 1:
				expNum = 2;
				break;
			case 2:
				expNum = 3;
				break;
			case 3:
				expNum = 4;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		expFlg = false;
	}

	back.Update();
	switch (expNum)
	{
	case 1:
		Exp1Update();
		break;
	case 2:
		Exp2Update();
		break;
	case 3:
		Exp3Update();
		break;
	case 4:
		Exp4Update();
		break;
	default:
		break;
	}
	if (expNum == 4)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			SCENEMANAGER.ChangeState(new GameScene());
			SCENEMANAGER.Init();
			return;
		}
	}

	for (int a = 0;a < ArrowNum;++a)
	{
		arrow[a].transMat = Math::Matrix::CreateTranslation(arrow[a].m_pos.x, arrow[a].m_pos.y, 0);
		arrow[a].scaleMat = Math::Matrix::CreateScale(arrow[a].m_scale.x, arrow[a].m_scale.y, 1);
		arrow[a].Mat = arrow[a].scaleMat * arrow[a].transMat;
	}
}

void TutorialScene::Draw()
{
	back.Draw();

	SHADER.m_spriteShader.SetMatrix(arrow[0].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(529, 65, 13, 14), 1.0f);
	SHADER.m_spriteShader.SetMatrix(arrow[1].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(497, 65, 13, 14), 1.0f);

	switch (expNum)
	{
	case 1:
		Exp1Draw();
		break;
	case 2:
		Exp2Draw();
		break;
	case 3:
		Exp3Draw();
		break;
	case 4:
		Exp4Draw();
		break;
	default:
		break;
	}
	
}

void TutorialScene::Release()
{
	back.Release();
	m_tex.Release();
	m_headtex.Release();
	m_keytex.Release();
	m_movetex.Release();
	m_atkimgtex.Release();
	m_boximgtex.Release();
	m_starimgtex.Release();
	m_atkexptex.Release();
	m_starexptex.Release();
	m_boxexptex.Release();
	m_debufftex.Release();
	m_damegetex.Release();
	m_stagetex.Release();
	m_bosstex.Release();
	m_starttex.Release();
}

void TutorialScene::Exp1Init()
{
	exp.m_pos = { 0,0 };
	exp.m_scale = { 1,1 };
	m_tex.Load("Texture/Tutorial.png");
	head.m_pos = { -20,180 };
	head.m_scale = { 1,1 };
	m_headtex.Load("Texture/Up.png");
	key1[0].m_pos = { 0,0 };//↑
	key1[0].m_scale = { 5,5 };
	key1[1].m_pos = { 100,-100 };//→
	key1[1].m_scale = { 5,5 };
	key1[2].m_pos = { 0,-100 };//↓
	key1[2].m_scale = { 5,5 };
	key1[3].m_pos = { -100,-100 };//←
	key1[3].m_scale = { 5,5 };
	m_keytex.Load("Texture/tilemap_packed.png");
	keyexp1.m_pos = { 0,-200 };
	keyexp1.m_scale = { 0.7f,0.7f };
	m_movetex.Load("Texture/move.png");
}

void TutorialScene::Exp1Update()
{
	exp.transMat = Math::Matrix::CreateTranslation(exp.m_pos.x, exp.m_pos.y, 0);
	exp.scaleMat = Math::Matrix::CreateScale(exp.m_scale.x, exp.m_scale.y, 1);
	exp.Mat = exp.scaleMat * exp.transMat;
	head.transMat = Math::Matrix::CreateTranslation(head.m_pos.x, head.m_pos.y, 0);
	head.scaleMat = Math::Matrix::CreateScale(head.m_scale.x, head.m_scale.y, 1);
	head.Mat = head.scaleMat * head.transMat;
	for (int k = 0;k < Key1Num;++k)
	{
		key1[k].transMat = Math::Matrix::CreateTranslation(key1[k].m_pos.x, key1[k].m_pos.y, 0);
		key1[k].scaleMat = Math::Matrix::CreateScale(key1[k].m_scale.x, key1[k].m_scale.y, 1);
		key1[k].Mat = key1[k].scaleMat * key1[k].transMat;
	}
	keyexp1.transMat = Math::Matrix::CreateTranslation(keyexp1.m_pos.x, keyexp1.m_pos.y, 0);
	keyexp1.scaleMat = Math::Matrix::CreateScale(keyexp1.m_scale.x, keyexp1.m_scale.y, 1);
	keyexp1.Mat = keyexp1.scaleMat * keyexp1.transMat;
}

void TutorialScene::Exp1Draw()
{
	SHADER.m_spriteShader.SetMatrix(exp.Mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	SHADER.m_spriteShader.SetMatrix(head.Mat);
	SHADER.m_spriteShader.DrawTex(&m_headtex, Math::Rectangle(0, 0, 1280, 150), 1.0f);

	SHADER.m_spriteShader.SetMatrix(key1[0].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(481, 65, 13, 14), 1.0f);
	SHADER.m_spriteShader.SetMatrix(key1[1].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(497, 65, 13, 14), 1.0f);
	SHADER.m_spriteShader.SetMatrix(key1[2].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(513, 65, 13, 14), 1.0f);
	SHADER.m_spriteShader.SetMatrix(key1[3].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(529, 65, 13, 14), 1.0f);

	SHADER.m_spriteShader.SetMatrix(keyexp1.Mat);
	SHADER.m_spriteShader.DrawTex(&m_movetex, Math::Rectangle(0, 0, 1280, 150), 1.0f);
}

void TutorialScene::Exp2Init()
{
	head.m_pos = { -20,180 };
	head.m_scale = { 1,1 };

	key2[0].m_pos = { 0,180 };//Space
	key2[0].m_scale = { 5,5 };
	key2[1].m_pos = { -300,180 };//A
	key2[1].m_scale = { 5,5 };
	key2[2].m_pos = { 300,180 };//S
	key2[2].m_scale = { 5,5 };

	keyimg[0].m_pos = { 0,50 };
	keyimg[0].m_scale = { 7,7 };
	keyimg[1].m_pos = { -300,50 };
	keyimg[1].m_scale = { 3.5,3.5 };
	keyimg[2].m_pos = { 300,50 };
	keyimg[2].m_scale = { 7,7 };

	keyexp2[0].m_pos = { 20,-130 };
	keyexp2[0].m_scale = { 0.4,0.4 };
	keyexp2[1].m_pos = { -320,-130 };
	keyexp2[1].m_scale = { 0.4,0.4 };
	keyexp2[2].m_pos = { 280,-130 };
	keyexp2[2].m_scale = { 0.4,0.4 };

	m_atkimgtex.Load("Texture/Charge1.png");
	m_boximgtex.Load("Texture/boxes_SpriteSheet.png");
	m_starimgtex.Load("Texture/star1.png");
	m_atkexptex.Load("Texture/atkexp.png");
	m_starexptex.Load("Texture/starexp.png");
	m_boxexptex.Load("Texture/boxexp.png");
}

void TutorialScene::Exp2Update()
{
	exp.transMat = Math::Matrix::CreateTranslation(exp.m_pos.x, exp.m_pos.y, 0);
	exp.scaleMat = Math::Matrix::CreateScale(exp.m_scale.x, exp.m_scale.y, 1);
	exp.Mat = exp.scaleMat * exp.transMat;
	for (int k = 0;k < Key2Num;++k)
	{
		key2[k].transMat = Math::Matrix::CreateTranslation(key2[k].m_pos.x, key2[k].m_pos.y, 0);
		key2[k].scaleMat = Math::Matrix::CreateScale(key2[k].m_scale.x, key2[k].m_scale.y, 1);
		key2[k].Mat = key2[k].scaleMat * key2[k].transMat;
	}
	for (int i = 0;i < KeyImgNum;++i)
	{
		keyimg[i].transMat = Math::Matrix::CreateTranslation(keyimg[i].m_pos.x, keyimg[i].m_pos.y, 0);
		keyimg[i].scaleMat = Math::Matrix::CreateScale(keyimg[i].m_scale.x, keyimg[i].m_scale.y, 1);
		keyimg[i].Mat = keyimg[i].scaleMat * keyimg[i].transMat;
	}
	for (int k = 0;k < KeyExp2Num;++k)
	{
		keyexp2[k].transMat = Math::Matrix::CreateTranslation(keyexp2[k].m_pos.x, keyexp2[k].m_pos.y, 0);
		keyexp2[k].scaleMat = Math::Matrix::CreateScale(keyexp2[k].m_scale.x, keyexp2[k].m_scale.y, 1);
		keyexp2[k].Mat = keyexp2[k].scaleMat * keyexp2[k].transMat;
	}
}

void TutorialScene::Exp2Draw()
{
	SHADER.m_spriteShader.SetMatrix(exp.Mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	SHADER.m_spriteShader.SetMatrix(key2[0].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(497, 97, 46, 14), 1.0f);
	SHADER.m_spriteShader.SetMatrix(key2[1].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(288, 48, 16, 16), 1.0f);
	SHADER.m_spriteShader.SetMatrix(key2[2].Mat);
	SHADER.m_spriteShader.DrawTex(&m_keytex, Math::Rectangle(304, 48, 16, 16), 1.0f);

	SHADER.m_spriteShader.SetMatrix(keyimg[0].Mat);
	SHADER.m_spriteShader.DrawTex(&m_atkimgtex, Math::Rectangle(145, 0, 64, 64), 1.0f);
	SHADER.m_spriteShader.SetMatrix(keyimg[1].Mat);
	SHADER.m_spriteShader.DrawTex(&m_starimgtex, Math::Rectangle(0, 0, 32, 32), 1.0f);
	SHADER.m_spriteShader.SetMatrix(keyimg[2].Mat);
	SHADER.m_spriteShader.DrawTex(&m_boximgtex, Math::Rectangle(18, 18, 18, 18), 1.0f);

	SHADER.m_spriteShader.SetMatrix(keyexp2[0].Mat);
	SHADER.m_spriteShader.DrawTex(&m_atkexptex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
	SHADER.m_spriteShader.SetMatrix(keyexp2[1].Mat);
	SHADER.m_spriteShader.DrawTex(&m_starexptex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
	SHADER.m_spriteShader.SetMatrix(keyexp2[2].Mat);
	SHADER.m_spriteShader.DrawTex(&m_boxexptex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
}

void TutorialScene::Exp3Init()
{
	head.m_pos = { -20,180 };
	head.m_scale = { 1,1 };
	exp3[0].m_pos = { 200,0 };	//状態異常
	exp3[0].m_scale = { 0.4,0.4 };
	exp3[1].m_pos = { -200,0 };	//攻撃の説明
	exp3[1].m_scale = { 0.4,0.4 };

	m_debufftex.Load("Texture/debuffexp.png");
	m_damegetex.Load("Texture/damege.png");
}

void TutorialScene::Exp3Update()
{
	exp.transMat = Math::Matrix::CreateTranslation(exp.m_pos.x, exp.m_pos.y, 0);
	exp.scaleMat = Math::Matrix::CreateScale(exp.m_scale.x, exp.m_scale.y, 1);
	exp.Mat = exp.scaleMat * exp.transMat;

	for (int e = 0;e < Exp3Num;++e)
	{
		exp3[e].transMat = Math::Matrix::CreateTranslation(exp3[e].m_pos.x, exp3[e].m_pos.y, 0);
		exp3[e].scaleMat = Math::Matrix::CreateScale(exp3[e].m_scale.x, exp3[e].m_scale.y, 1);
		exp3[e].Mat = exp3[e].scaleMat * exp3[e].transMat;
	}
}

void TutorialScene::Exp3Draw()
{
	SHADER.m_spriteShader.SetMatrix(exp.Mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	SHADER.m_spriteShader.SetMatrix(exp3[0].Mat);
	SHADER.m_spriteShader.DrawTex(&m_debufftex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
	
	SHADER.m_spriteShader.SetMatrix(exp3[1].Mat);
	SHADER.m_spriteShader.DrawTex(&m_damegetex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
}

void TutorialScene::Exp4Init()
{
	exp4[0].m_pos = { 0,80 };	//ステージ
	exp4[0].m_scale = { 0.7,0.7 };
	exp4[1].m_pos = { 40,-40 };	//ボス
	exp4[1].m_scale = { 0.5,0.5 };
	start.m_pos = { 30,-250 };		//start
	start.m_scale = { 0.6,0.6 };

	m_stagetex.Load("Texture/stageexp.png");
	m_bosstex.Load("Texture/bossexp.png");
	m_starttex.Load("Texture/start.png");
}

void TutorialScene::Exp4Update()
{
	exp.transMat = Math::Matrix::CreateTranslation(exp.m_pos.x, exp.m_pos.y, 0);
	exp.scaleMat = Math::Matrix::CreateScale(exp.m_scale.x, exp.m_scale.y, 1);
	exp.Mat = exp.scaleMat * exp.transMat;

	for (int e = 0;e < Exp4Num;++e)
	{
		exp4[e].transMat = Math::Matrix::CreateTranslation(exp4[e].m_pos.x, exp4[e].m_pos.y, 0);
		exp4[e].scaleMat = Math::Matrix::CreateScale(exp4[e].m_scale.x, exp4[e].m_scale.y, 1);
		exp4[e].Mat = exp4[e].scaleMat * exp4[e].transMat;
	}

	start.transMat = Math::Matrix::CreateTranslation(start.m_pos.x, start.m_pos.y, 0);
	start.scaleMat = Math::Matrix::CreateScale(start.m_scale.x, start.m_scale.y, 1);
	start.Mat = start.scaleMat * start.transMat;
}

void TutorialScene::Exp4Draw()
{
	SHADER.m_spriteShader.SetMatrix(exp.Mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	SHADER.m_spriteShader.SetMatrix(exp4[0].Mat);
	SHADER.m_spriteShader.DrawTex(&m_stagetex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
	SHADER.m_spriteShader.SetMatrix(exp4[1].Mat);
	SHADER.m_spriteShader.DrawTex(&m_bosstex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	SHADER.m_spriteShader.SetMatrix(start.Mat);
	SHADER.m_spriteShader.DrawTex(&m_starttex, Math::Rectangle(0, 0, 1280, 720), 1.0f);
}
