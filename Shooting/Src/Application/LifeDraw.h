#pragma once

struct Life
{
	Math::Vector2 m_pos;
	Math::Matrix m_Mat;
	Math::Matrix m_Trans;
	Math::Matrix m_Scale;
};

class LifeDraw
{
public:

	LifeDraw() {}
	~LifeDraw() {}

	void Init();
	void Update();
	void Draw();
	void Release();
	void SetHp(int Hp) { m_Hp = Hp; }

private:

	KdTexture m_lifeTex;
	static const int lifeNum = 3;
	Life life[lifeNum];
	int m_Hp;

};
