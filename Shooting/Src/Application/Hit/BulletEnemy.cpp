#include "BulletEnemy.h"
#include"../GameScene.h"

void BulletEnemy::PBulletPhoenix()
{
	Player* player = m_owner->GetPlayer();
	Phoenix* phoenix = m_owner->GetPhoenix();

	for (int e = 0; e < phoenix->GetNum(); ++e)
	{
		for (int b = 0;b < player->GetBulletNum();++b)
		{
			Math::Vector2 hitpos = player->GetBulletPos(b) - phoenix->GetPos(e);

			if (hitpos.Length() < 30)
			{
				if(phoenix->GetAliveFlg(e)==true)
				{
					if (player->GetBulletFlg(b) == true)
					{
						player->BulletHit(b);
						break;
					}
				}
			}
		}
	}
}

void BulletEnemy::FBulletPhoenix()
{
	Player* player = m_owner->GetPlayer();
	Phoenix* phoenix = m_owner->GetPhoenix();

	for (int e = 0; e < phoenix->GetNum(); ++e)
	{
		for (int b = 0;b < player->GetFBulletNum();++b)
		{
			Math::Vector2 hitpos = player->GetFBulletPos(b) - phoenix->GetPos(e);

			if (hitpos.Length() < 30)
			{
				if (phoenix->GetAliveFlg(e) == true)
				{
					if (player->GetFBulletFlg(b) == true)
					{
						phoenix->B_PhoenixHit(e);
						player->FBulletHit(b);
						player->SetScore();
						break;
					}
				}
			}
		}
	}
}

void BulletEnemy::PBulletEvil()
{
	Player* player = m_owner->GetPlayer();
	Evil* evil = m_owner->GetEvil();

	for (int e = 0; e < evil->GetNum(); ++e)
	{
		for (int b = 0;b < player->GetBulletNum();++b)
		{
			Math::Vector2 hitpos = player->GetBulletPos(b) - evil->GetPos(e);

			if (hitpos.Length() < 60)
			{
				if (evil->GetAliveFlg(e) == true)
				{
					if (player->GetBulletFlg(b) == true)
					{
						evil->B_EvilHit(e);
						player->BulletHit(b);
						player->SetScore();
						break;
					}
				}
			}
		}
	}
}

void BulletEnemy::FBulletEvil()
{
	Player* player = m_owner->GetPlayer();
	Evil* evil = m_owner->GetEvil();

	for (int e = 0; e < evil->GetNum(); ++e)
	{
		for (int b = 0;b < player->GetFBulletNum();++b)
		{
			Math::Vector2 hitpos = player->GetFBulletPos(b) - evil->GetPos(e);

			if (hitpos.Length() < 60)
			{
				if (evil->GetAliveFlg(e) == true)
				{
					if (player->GetFBulletFlg(b) == true)
					{
						player->FBulletHit(b);
						break;
					}
				}
			}
		}
	}
}

void BulletEnemy::EvilBulletHit()
{
	Player* player = m_owner->GetPlayer();
	Evil* evil = m_owner->GetEvil();

	for (int e = 0; e < evil->GetNum(); ++e)
	{
		Math::Vector2 hitpos = player->GetPos() - evil->GetBulletPos(e);

		if (hitpos.Length() < 20)
		{
			if (evil->GetBulletFlg(e) == true)
			{
				if (player->GetAliveFlg() == true)
				{
					player->PlayerEvilHit();
					break;
				}
			}
		}
	}
}

void BulletEnemy::PBulletBoss()
{
	Player* player = m_owner->GetPlayer();
	Boss* boss = m_owner->GetBoss();

	for (int b = 0;b < player->GetBulletNum();++b)
	{
		Math::Vector2 hitpos = player->GetBulletPos(b) - boss->GetPos();

		if (hitpos.Length() < 140)
		{
			if (boss->GetAliveFlg() == true)
			{
				if (player->GetBulletFlg(b) == true)
				{
					boss->B_BossHit(player->GetCharmFlg());
					player->BulletHit(b);
					break;
				}
			}
		}
	}
}

void BulletEnemy::FBulletBoss()
{
	Player* player = m_owner->GetPlayer();
	Boss* boss = m_owner->GetBoss();

	for (int b = 0;b < player->GetFBulletNum();++b)
	{
		Math::Vector2 hitpos = player->GetFBulletPos(b) - boss->GetPos();

		if (hitpos.Length() < 140)
		{
			if (boss->GetAliveFlg() == true)
			{
				if (player->GetFBulletFlg(b) == true)
				{
					boss->B_BossHit(player->GetCharmFlg());
					player->FBulletHit(b);
					break;
				}
			}
		}
	}
}

void BulletEnemy::BossBulletHit()
{
	Player* player = m_owner->GetPlayer();
	Boss* boss = m_owner->GetBoss();

	for (int b = 0; b < boss->GetBulletNum(); ++b)
	{
		Math::Vector2 hitpos = player->GetPos() - boss->GetBulletPos(b);

		if (hitpos.Length() < 50)
		{
			if (boss->GetBulletFlg(b) == true)
			{
				if (player->GetAliveFlg() == true)
				{
					player->PlayerBossIceBulletHit();
					break;
				}
			}
		}
	}
}

void BulletEnemy::BossArrowHit()
{
	Player* player = m_owner->GetPlayer();
	Boss* boss = m_owner->GetBoss();

	for (int b = 0; b < boss->GetArrowNum(); ++b)
	{
		Math::Vector2 hitpos = player->GetPos() - boss->GetArrowPos(b);

		if (hitpos.Length() < 50)
		{
			if (boss->GetArrowFlg(b) == true)
			{
				if (player->GetAliveFlg() == true)
				{
					boss->ArrowHit();
					player->PlayerBossArrowHit();
					break;
				}
			}
		}
	}
}

void BulletEnemy::BossRainHit()
{
	Player* player = m_owner->GetPlayer();
	Boss* boss = m_owner->GetBoss();

	for (int b = 0; b < boss->GetRainNum(); ++b)
	{
		Math::Vector2 hitpos = player->GetPos() - boss->GetRainPos(b);

		if (hitpos.Length() < 50)
		{
			if (boss->GetRainFlg(b) == true)
			{
				if (player->GetAliveFlg() == true)
				{
					player->PlayerBossRainHit();
					break;
				}
			}
		}
	}
}
