#include "BulletEnemy.h"
#include"../Scene.h"

void BulletEnemy::PBulletEnemy()
{
	Player* player = m_owner->GetPlayer();
	Phoenix* phoenix = m_owner->GetPhoenix();

	for (int e = 0; e < phoenix->GetNum(); e++)
	{
		for (int b = 0;b < player->GetBulletNum();b++)
		{
			const float x = phoenix->GetPos(e).x - player->GetBulletPos(b).x + 10;
			const float y = phoenix->GetPos(e).y - player->GetBulletPos(b).y;
			const float z = sqrt(x * x + y * y);
			const float sum = phoenix->GetRadius(e) + player->GetBulletRadiusX(e);

			if (z < sum)
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

void BulletEnemy::FBulletEnemy()
{
	Player* player = m_owner->GetPlayer();
	Phoenix* phoenix = m_owner->GetPhoenix();

	for (int e = 0; e < phoenix->GetNum(); e++)
	{
		for (int b = 0;b < player->GetFBulletNum();b++)
		{
			const float x = phoenix->GetPos(e).x - player->GetFBulletPos(b).x + 10;
			const float y = phoenix->GetPos(e).y - player->GetFBulletPos(b).y;
			const float z = sqrt(x * x + y * y);
			const float sum = phoenix->GetRadius(e) + player->GetFBulletRadius(e);

			if (z < sum)
			{
				if (phoenix->GetAliveFlg(e) == true)
				{
					if (player->GetFBulletFlg(b) == true)
					{
						player->FBulletHit(b);
						phoenix->B_PhoenixHit(e);
						break;
					}
				}
			}
		}
	}
}
