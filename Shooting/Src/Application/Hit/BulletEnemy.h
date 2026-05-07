#pragma once

class Scene;

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

	void SetOwner(Scene* owner) { m_owner = owner; }

private:

	Scene* m_owner;

};