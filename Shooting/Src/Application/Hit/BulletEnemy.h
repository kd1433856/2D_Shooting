#pragma once

class Scene;

class BulletEnemy
{
public:

	BulletEnemy() {}
	~BulletEnemy() {}

	void PBulletEnemy();

	void SetOwner(Scene* owner) { m_owner = owner; }

private:

	Scene* m_owner;

};