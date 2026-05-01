#pragma once

class Scene;

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
	bool aliveFlg;
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

	void FunnelBulletInit();
	void FunnelBulletUpdate();
	void FunnelBulletDraw();

	void PlayerEnemyHit();
	void BulletHit(int b);
	void FBulletHit(int b);

	void SetPos(Math::Vector2 pos) { player.pos = pos; }
	void SetScale(Math::Vector2 scale) { player.scale = scale * 1.5; }

	Math::Vector2 GetPos() { return player.pos; }
	Math::Vector2 GetScale() { return player.scale; }
	Math::Vector2 GetFuturePos() { return player.pos + player.move; }
	float  GetRadiusX() { return 22.0f * fabs(player.scale.x); }
	float  GetRadiusY() { return 20.0f * fabs(player.scale.y); }
	bool GetGard();

	Math::Vector2 GetBulletPos(int b) { return bullet[b].pos; }
	Math::Vector2 GetBulletScale(int b) { return bullet[b].scale; }
	float  GetBulletRadiusX(int b) { return 8.0f * fabs(bullet[b].scale.x); }
	float  GetBulletRadiusY(int b) { return 4.0f * fabs(bullet[b].scale.y); }
	int GetBulletNum() { return BulletNum; }
	bool GetBulletFlg(int b);

	Math::Vector2 GetFBulletPos(int b) { return fbullet[b].pos; }
	Math::Vector2 GetFBulletScale(int b) { return fbullet[b].scale; }
	float  GetFBulletRadius(int b) { return 16.0f * fabs(fbullet[b].scale.x); }
	int GetFBulletNum() { return FunnelBulletNum; }
	bool GetFBulletFlg(int b);

	void SetOwner(Scene* owner) { m_owner = owner; }

private:

	Scene* m_owner;

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
	static const int FunnelBulletNum = 10;
	Chara fbullet[FunnelBulletNum];
	Math::Matrix funnelRoteto;
	float funneldeg[FunnelBulletNum];

	float m_deg;
	bool starFlg;
	bool rotateFlg;	//‰ñ“]
	bool stopFlg;	//’âŽ~

	float shotWait;
	float funnelWait;
	float stunWait;

	float movespeed;

	float stunAnimY;
};