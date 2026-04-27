#include "PlayerEnemy.h"
#include"../Scene.h"

void PlayerEnemy::PhoenixHit()
{
	Player* player = m_owner->GetPlayer();
	Phoenix* phoenix = m_owner->GetPhoenix();

	const float playerRight = player->GetPos().x + player->GetRadiusX();
	const float playerLeft = player->GetPos().x - player->GetRadiusX();
	const float playerTop = player->GetPos().y + player->GetRadiusY();
	const float playerBottom = player->GetPos().y - player->GetRadiusY();

	const float nextRight = player->GetFuturePos().x + player->GetRadiusX();
	const float nextLeft = player->GetFuturePos().x - player->GetRadiusX();
	const float nextTop = player->GetFuturePos().y + player->GetRadiusY();
	const float nextBottom = player->GetFuturePos().y - player->GetRadiusY();

	for (int e = 0; e < phoenix->GetNum(); e++)
	{
		const float phoenixRight = phoenix->GetPos(e).x + phoenix->GetRadius(e);
		const float phoenixLeft = phoenix->GetPos(e).x - phoenix->GetRadius(e);
		const float phoenixTop = phoenix->GetPos(e).y + phoenix->GetRadius(e);
		const float phoenixBottom = phoenix->GetPos(e).y - phoenix->GetRadius(e);

		//プレイヤーとブロックが縦で重なっているか
		if (playerRight > phoenixLeft && playerLeft < phoenixRight)
		{
			if (nextBottom<phoenixTop && nextTop>phoenixTop)
			{
				player->PlayerEnemyHit();
			}
			else if (phoenixBottom < nextTop && nextBottom < phoenixBottom)
			{
				player->PlayerEnemyHit();
			}
		}
		//プレイヤーとブロックが横で重なっているか
		if (playerTop > phoenixBottom && playerBottom < phoenixTop)
		{
			if (nextLeft < phoenixRight && nextRight > phoenixRight)
			{
				player->PlayerEnemyHit();
			}
			else if (phoenixLeft < nextRight && nextLeft < phoenixLeft)
			{
				player->PlayerEnemyHit();
			}
		}
	}
}
