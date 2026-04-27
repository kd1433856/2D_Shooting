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
				player->BulletHit();
				phoenix->B_PhoenixHit();
			}
		}
	}
}
