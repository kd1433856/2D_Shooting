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

private:

	KdTexture CharaTex;
	KdTexture BoxTex;
	KdTexture FunnelTex;

	Chara player;
	Chara box;
	Chara funnel;

	float m_deg;
	bool starFlg;
	bool rotateFlg;	//‰ñ“]
	bool stopFlg;	//’âŽ~

	float RGB_r;
	float RGB_g;
	float RGB_b;
	float RGB_Down;

	float movespeed;

	bool sutanFlg;
	bool GardFlg;
};