#include "BulletEnemy.h"
#include"../Scene.h"

void BulletEnemy::PBulletPhoenix()
{
	Player* player = m_owner->GetPlayer();
	Phoenix* phoenix = m_owner->GetPhoenix();

	for (int e = 0; e < phoenix->GetNum(); e++)
	{
		for (int b = 0;b < player->GetBulletNum();b++)
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

	for (int e = 0; e < phoenix->GetNum(); e++)
	{
		for (int b = 0;b < player->GetFBulletNum();b++)
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

	for (int e = 0; e < evil->GetNum(); e++)
	{
		for (int b = 0;b < player->GetBulletNum();b++)
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

	for (int e = 0; e < evil->GetNum(); e++)
	{
		for (int b = 0;b < player->GetFBulletNum();b++)
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

	for (int e = 0; e < evil->GetNum(); e++)
	{
		Math::Vector2 hitpos = player->GetPos() - evil->GetBulletPos(e);

		if (hitpos.Length() < 20)
		{
			if (evil->GetBulletFlg(e) == true)
			{
				if (player->GetAliveFlg() == true)
				{
					player->PlayerEnemyHit();
					break;
				}
			}
		}
	}
}
