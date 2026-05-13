#include "GameScene.h"
#include"SceneManager.h"

void GameScene::Init()
{
	stageNum = 1;
	//stageNum = 2;
	//stageNum = 3;
	stageFlg = false;
	NormalRepopFlg = false;
	BossRepopFlg = false;
	resultFlg = false;
	goalscore = 2000;
	pe_hit.SetOwner(this);
	be_hit.SetOwner(this);
	player.SetOwner(this);
	srand(time(0));
	player.Init();
	life.Init();
	phoenix.Init();
	evil.Init();
	ghost.Init();
	boss.Init();
	result.Init();
	score.Init();
	debuff.Init();
	back.Init();
	
	m_scoreTex.Load("Texture/Number.png");
}

void GameScene::Update()
{
	if (player.GetAliveFlg() == true && resultFlg == false)
	{
		switch (stageNum)
		{
		case 1:
			goalscore = 3000;
			break;
		case 2:
			goalscore = 6000;
			break;
		case 3:
			goalscore = 9000;
			break;
		default:
			break;
		}
		player.Update();
		life.SetHp(player.GetHp());
		life.Update();
		debuff.SetStunFlg(player.GetStunFlg());
		debuff.SetSlowFlg(player.GetSlowFlg());
		debuff.SetSilenceFlg(player.GetSilenceFlg());
		debuff.SetIceFlg(player.GetIceFlg());
		debuff.SetBleedFlg(player.GetBleedFlg());
		debuff.SetCharmFlg(player.GetCharmFlg());
		debuff.Update();

		unsigned long gaoltmp = goalscore;
		for (int i = goalscoremaxDirit - 1;i >= 0;--i)
		{
			//下位の桁から抽出し配列に格納
			m_goalscoredigits[i] = gaoltmp % 10;//余りを求める演算子 %
			gaoltmp /= 10;
		}

		//配列に各桁の数値を格納
		unsigned long tmp = player.GetScore();
		for (int i = scoremaxDirit - 1;i >= 0;--i)
		{
			//下位の桁から抽出し配列に格納
			m_scoredigits[i] = tmp % 10;//余りを求める演算子 %
			tmp /= 10;
		}
		
		if (NormalRepopFlg == true)
		{
			for (int e = 0; e < phoenix.GetNum(); ++e)
			{
				phoenix.Repop(e);
			}
			for (int e = 0; e < evil.GetNum(); ++e)
			{
				evil.Repop(e);
			}
			NormalRepopFlg = false;
		}

		if (player.GetScore() < goalscore)
		{
			switch (stageNum)
			{
			case 1:
				phoenix.Action();
				phoenix.Update();
				if (player.GetBariaFlg() == false)
				{
					if (player.GetGard() == false)
					{
						pe_hit.PhoenixHit();
					}
				}
				be_hit.PBulletPhoenix();
				be_hit.FBulletPhoenix();
				break;
			case 2:
				phoenix.Action();
				phoenix.Update();
				evil.Action();
				evil.Update();
				if (player.GetBariaFlg() == false)
				{
					if (player.GetGard() == false)
					{
						pe_hit.PhoenixHit();
						pe_hit.EvilHit();
						be_hit.EvilBulletHit();
					}
				}
				be_hit.PBulletPhoenix();
				be_hit.FBulletPhoenix();
				be_hit.PBulletEvil();
				be_hit.FBulletEvil();
				break;
			case 3:
				phoenix.Action();
				phoenix.Update();
				evil.Action();
				evil.Update();
				ghost.Action();
				ghost.Update();
				if (player.GetBariaFlg() == false)
				{
					if (player.GetGard() == false)
					{
						pe_hit.PhoenixHit();
						pe_hit.EvilHit();
						be_hit.EvilBulletHit();
						pe_hit.GhostHit();
					}
				}
				be_hit.PBulletPhoenix();
				be_hit.FBulletPhoenix();
				be_hit.PBulletEvil();
				be_hit.FBulletEvil();
				break;
			default:
				break;
			}
			BossRepopFlg = true;
		}

		if (BossRepopFlg == true)
		{
			boss.BossRepop();
			for (int b = 0;b < boss.GetBulletNum();++b)
			{
				boss.BulletRepop(b);
			}
			for (int a = 0;a < boss.GetArrowNum();++a)
			{
				boss.ArrowRepop(a);
			}
			BossRepopFlg = false;
		}

		if (player.GetScore() >= goalscore)
		{
			NormalRepopFlg = true;
			stageFlg = false;
			if (player.GetBariaFlg() == false)
			{
				if (player.GetGard() == false)
				{
					pe_hit.BossHit();
					be_hit.BossBulletHit();
					be_hit.BossArrowHit();
					be_hit.BossRainHit();
				}
			}

			boss.Action(stageNum);
			boss.Update();
			be_hit.PBulletBoss();
			be_hit.FBulletBoss();
		}

		if (boss.GetAliveFlg() == false)
		{
			if (stageFlg == false)
			{
				switch (stageNum)
				{
				case 1:
					stageNum = 2;
					break;
				case 2:
					stageNum = 3;
					break;
				case 3:
					resultFlg = true;
					break;
				default:
					break;
				}
				stageFlg = true;
			}
		}
	}
	else
	{
		result.Update(stageNum, resultFlg);
	}
	score.Update();
	back.Update();
}

void GameScene::Draw()
{
	back.Draw();

	if (player.GetAliveFlg() == true && resultFlg == false)
	{
		player.Draw();
		if (player.GetScore() < goalscore)
		{
			switch (stageNum)
			{
			case 1:
				phoenix.Draw();
				break;
			case 2:
				phoenix.Draw();
				evil.Draw();
				break;
			case 3:
				phoenix.Draw();
				evil.Draw();
				ghost.Draw();
				break;
			default:
				break;
			}
		}
		if (player.GetScore() >= goalscore)
		{
			boss.Draw();
		}
	}
	else
	{
		result.Draw(stageNum, resultFlg);
	}

	if (player.GetAliveFlg() == true && resultFlg == false)
	{
		life.Draw();
		debuff.Draw();

		if (player.GetScore() < goalscore)
		{
			score.Draw();

			//スコア表示
			for (int i = 0;i < scoremaxDirit;++i)
			{
				Math::Rectangle rc = { 9 * m_scoredigits[i],0,9,9 };

				float posX = 400;

				//表示(サイズ5倍)
				Math::Matrix TransMat;
				Math::Matrix ScaleMat;
				Math::Matrix Mat;
				TransMat = Math::Matrix::CreateTranslation(posX + (i * 45), 260, 0);
				ScaleMat = Math::Matrix::CreateScale(5, 5, 1);
				Mat = ScaleMat * TransMat;
				SHADER.m_spriteShader.SetMatrix(Mat);

				SHADER.m_spriteShader.DrawTex(&m_scoreTex, rc);
			}

			for (int i = 0;i < goalscoremaxDirit;++i)
			{
				Math::Rectangle rc = { 9 * m_goalscoredigits[i],0,9,9 };

				float posX = 400;

				//表示(サイズ5倍)
				Math::Matrix TransMat;
				Math::Matrix ScaleMat;
				Math::Matrix Mat;
				TransMat = Math::Matrix::CreateTranslation(posX + (i * 45), 320, 0);
				ScaleMat = Math::Matrix::CreateScale(5, 5, 1);
				Mat = ScaleMat * TransMat;
				SHADER.m_spriteShader.SetMatrix(Mat);

				SHADER.m_spriteShader.DrawTex(&m_scoreTex, rc);
			}
		}
	}
}

void GameScene::Release()
{
	player.Release();
	phoenix.Release();
	evil.Release();
	ghost.Release();
	boss.Release();
	result.Release();
	score.Release();
	back.Release();
	debuff.Relaese();
	m_scoreTex.Release();
}
