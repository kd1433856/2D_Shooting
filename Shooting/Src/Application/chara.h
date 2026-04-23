#pragma once

struct Chara
{
	Math::Vector2 pos;
	Math::Vector2 move;
	Math::Vector2 scale;
	Math::Matrix Mat;
	Math::Matrix TransMat;
	Math::Matrix ScaleMat;
	float alpha = 1.0f;
	float AnimCnt = 0.0f;
	bool aliveFlg = true;
};

class Player
{
public:

	Player() {}
	~Player() {}

	void Init();
	void Update();
	void Draw();
	void Release();

	void BoxInit();
	void BoxUpdate();
	void BoxDraw();

	void FunnelInit();
	void FunnelUpdate();
	void FunnelDraw();

	void StunInit();
	void StunUpdate();
	void StunDraw();

	void BulletInit();
	void BulletUpdate();
	void BulletDraw();

private:

	KdTexture CharaTex;
	KdTexture BoxTex;
	KdTexture FunnelTex;
	KdTexture StunTex;
	KdTexture BulletTex;

	Chara player;
	Chara box;
	Chara funnel;
	Chara stun;
	static const int BulletNum = 10;
	Chara bullet[BulletNum];

	float m_deg;
	bool starFlg;
	bool rotateFlg;	//‰ñ“]
	bool stopFlg;	//’âŽ~

	float movespeed;

	float stunAnimY;
};