#include "PlayerEnemy.h"
#include"../GameScene.h"

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
					player->PlayerPhoenixHit();
				}
				else if (phoenixBottom < nextTop && nextBottom < phoenixBottom)
				{
					player->PlayerPhoenixHit();
				}
			}
			//プレイヤーとブロックが横で重なっているか
			if (playerTop > phoenixBottom && playerBottom < phoenixTop)
			{
				if (nextLeft < phoenixRight && nextRight > phoenixRight)
				{
					player->PlayerPhoenixHit();
				}
				else if (phoenixLeft < nextRight && nextLeft < phoenixLeft)
				{
					player->PlayerPhoenixHit();
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
					player->PlayerEvilHit();
				}
				else if (evilBottom < nextTop && nextBottom < evilBottom)
				{
					player->PlayerEvilHit();
				}
			}
			//プレイヤーとブロックが横で重なっているか
			if (playerTop > evilBottom && playerBottom < evilTop)
			{
				if (nextLeft < evilRight && nextRight > evilRight)
				{
					player->PlayerEvilHit();
				}
				else if (evilLeft < nextRight && nextLeft < evilLeft)
				{
					player->PlayerEvilHit();
				}
			}
		}
	}
}

void PlayerEnemy::GhostHit()
{
	Player* player = m_owner->GetPlayer();
	Ghost* ghost = m_owner->GetGhost();

	const float playerRight = player->GetPos().x + player->GetRadiusX();
	const float playerLeft = player->GetPos().x - player->GetRadiusX();
	const float playerTop = player->GetPos().y + player->GetRadiusY();
	const float playerBottom = player->GetPos().y - player->GetRadiusY();

	const float nextRight = player->GetFuturePos().x + player->GetRadiusX();
	const float nextLeft = player->GetFuturePos().x - player->GetRadiusX();
	const float nextTop = player->GetFuturePos().y + player->GetRadiusY();
	const float nextBottom = player->GetFuturePos().y - player->GetRadiusY();

	for (int e = 0; e < ghost->GetNum(); e++)
	{
		const float ghostRight = ghost->GetPos(e).x + ghost->GetRadius(e);
		const float ghostLeft = ghost->GetPos(e).x - ghost->GetRadius(e);
		const float ghostTop = ghost->GetPos(e).y + ghost->GetRadius(e);
		const float ghostBottom = ghost->GetPos(e).y - ghost->GetRadius(e);

		if (ghost->GetAliveFlg(e) == true)
		{
			//プレイヤーとブロックが縦で重なっているか
			if (playerRight > ghostLeft && playerLeft < ghostRight)
			{
				if (nextBottom<ghostTop && nextTop>ghostTop)
				{
					player->PlayerGhostHit();
				}
				else if (ghostBottom < nextTop && nextBottom < ghostBottom)
				{
					player->PlayerGhostHit();
				}
			}
			//プレイヤーとブロックが横で重なっているか
			if (playerTop > ghostBottom && playerBottom < ghostTop)
			{
				if (nextLeft < ghostRight && nextRight > ghostRight)
				{
					player->PlayerGhostHit();
				}
				else if (ghostLeft < nextRight && nextLeft < ghostLeft)
				{
					player->PlayerGhostHit();
				}
			}
		}
	}
}

void PlayerEnemy::BossHit()
{
	Player* player = m_owner->GetPlayer();
	Boss* boss = m_owner->GetBoss();

	const float playerRight = player->GetPos().x + player->GetRadiusX();
	const float playerLeft = player->GetPos().x - player->GetRadiusX();
	const float playerTop = player->GetPos().y + player->GetRadiusY();
	const float playerBottom = player->GetPos().y - player->GetRadiusY();

	const float nextRight = player->GetFuturePos().x + player->GetRadiusX();
	const float nextLeft = player->GetFuturePos().x - player->GetRadiusX();
	const float nextTop = player->GetFuturePos().y + player->GetRadiusY();
	const float nextBottom = player->GetFuturePos().y - player->GetRadiusY();

	const float bossRight = boss->GetPos().x + boss->GetRadius();
	const float bossLeft = boss->GetPos().x - boss->GetRadius();
	const float bossTop = boss->GetPos().y + boss->GetRadius();
	const float bossBottom = boss->GetPos().y - boss->GetRadius();

	if (boss->GetAliveFlg() == true)
	{
		//プレイヤーとブロックが縦で重なっているか
		if (playerRight > bossLeft && playerLeft < bossRight)
		{
			if (nextBottom<bossTop && nextTop>bossTop)
			{
				player->PlayerBossHit();
			}
			else if (bossBottom < nextTop && nextBottom < bossBottom)
			{
				player->PlayerBossHit();
			}
		}
		//プレイヤーとブロックが横で重なっているか
		if (playerTop > bossBottom && playerBottom < bossTop)
		{
			if (nextLeft < bossRight && nextRight > bossRight)
			{
				player->PlayerBossHit();
			}
			else if (bossLeft < nextRight && nextLeft < bossLeft)
			{
				player->PlayerBossHit();
			}
		}
	}
}
