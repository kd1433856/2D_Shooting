#pragma once

class GameScene;

class PlayerEnemy
{
public:

	PlayerEnemy() {}
	~PlayerEnemy() {}

	void PhoenixHit();
	void EvilHit();
	void GhostHit();
	void BossHit();

	void SetOwner(GameScene* owner) { m_owner = owner; }

private:

	GameScene* m_owner;

};