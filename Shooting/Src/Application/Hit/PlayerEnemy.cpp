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

		if (phoenix->GetAliveFlg(e) == true)
		{
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
}

void PlayerEnemy::EvilHit()
{
	Player* player = m_owner->GetPlayer();
	Evil* evil = m_owner->GetEvil();

	const float playerRight = player->GetPos().x + player->GetRadiusX();
	const float playerLeft = player->GetPos().x - player->GetRadiusX();
	const float playerTop = player->GetPos().y + player->GetRadiusY();
	const float playerBottom = player->GetPos().y - player->GetRadiusY();

	const float nextRight = player->GetFuturePos().x + player->GetRadiusX();
	const float nextLeft = player->GetFuturePos().x - player->GetRadiusX();
	const float nextTop = player->GetFuturePos().y + player->GetRadiusY();
	const float nextBottom = player->GetFuturePos().y - player->GetRadiusY();

	for (int e = 0; e < evil->GetNum(); e++)
	{
		const float evilRight = evil->GetPos(e).x + evil->GetRadius(e);
		const float evilLeft = evil->GetPos(e).x - evil->GetRadius(e);
		const float evilTop = evil->GetPos(e).y + evil->GetRadius(e);
		const float evilBottom = evil->GetPos(e).y - evil->GetRadius(e);

		if (evil->GetAliveFlg(e) == true)
		{
			//プレイヤーとブロックが縦で重なっているか
			if (playerRight > evilLeft && playerLeft < evilRight)
			{
				if (nextBottom<evilTop && nextTop>evilTop)
				{
					player->PlayerEnemyHit();
				}
				else if (evilBottom < nextTop && nextBottom < evilBottom)
				{
					player->PlayerEnemyHit();
				}
			}
			//プレイヤーとブロックが横で重なっているか
			if (playerTop > evilBottom && playerBottom < evilTop)
			{
				if (nextLeft < evilRight && nextRight > evilRight)
				{
					player->PlayerEnemyHit();
				}
				else if (evilLeft < nextRight && nextLeft < evilLeft)
				{
					player->PlayerEnemyHit();
				}
			}
		}
	}
}
