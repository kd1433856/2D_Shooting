#pragma once

struct Chara
{
	Math::Vector2 pos;
	Math::Vector2 move;
	Math::Vector2 scale;
	Math::Matrix Mat;
	Math::Matrix TransMat;
	Math::Matrix ScaleMat;
	float alpha;
	float AnimCnt;
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

private:

	KdTexture CharaTex;
	KdTexture BoxTex;
	KdTexture FunnelTex;
	KdTexture StunTex;

	Chara player;
	Chara box;
	Chara funnel;
	Chara stun;

	float m_deg;
	bool starFlg;
	bool rotateFlg;	//‰ñ“]
	bool stopFlg;	//’âŽ~

	float movespeed;

	bool sutanFlg;
	bool GardFlg;

	float stunAnimY;
};