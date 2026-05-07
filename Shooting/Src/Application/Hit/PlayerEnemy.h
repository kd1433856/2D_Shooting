#pragma once

class Scene;

class PlayerEnemy
{
public:

	PlayerEnemy() {}
	~PlayerEnemy() {}

	void PhoenixHit();
	void EvilHit();

	void SetOwner(Scene* owner) { m_owner = owner; }

private:

	Scene* m_owner;

};