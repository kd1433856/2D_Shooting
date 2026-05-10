#pragma once

class GameScene;

class BulletEnemy
{
public:

	BulletEnemy() {}
	~BulletEnemy() {}

	void PBulletPhoenix();
	void FBulletPhoenix();

	void PBulletEvil();
	void FBulletEvil();

	void EvilBulletHit();

	void PBulletBoss();
	void FBulletBoss();

	void BossBulletHit();
	void BossArrowHit();
	void BossRainHit();

	void SetOwner(GameScene* owner) { m_owner = owner; }

private:

	GameScene* m_owner;

};