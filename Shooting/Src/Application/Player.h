#pragma once

class GameScene;

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

	void SlowInit();
	void SlowUpdate();
	void SlowDraw();

	void SilenceInit();
	void SilenceUpdate();
	void SilenceDraw();

	void IceInit();
	void IceUpdate();
	void IceDraw();

	void BleedInit();
	void BleedUpdate();
	void BleedDraw();

	void CharmInit();
	void CharmUpdate();
	void CharmDraw();

	void BulletInit();
	void BulletUpdate();
	void BulletDraw();

	void FunnelBulletInit();
	void FunnelBulletUpdate();
	void FunnelBulletDraw();

	void PlayerPhoenixHit();
	void PlayerEvilHit();
	void PlayerGhostHit();
	void PlayerBossHit();
	void PlayerBossIceBulletHit();
	void PlayerBossArrowHit();
	void PlayerBossRainHit();
	void BulletHit(int b);
	void FBulletHit(int b);
	void SetScore();

	void SetPos(Math::Vector2 pos) { player.pos = pos; }
	void SetScale(Math::Vector2 scale) { player.scale = scale * 1.5; }
	void SetHp(int a_hp) { Hp = a_hp; }

	Math::Vector2 GetPos() { return player.pos; }
	Math::Vector2 GetScale() { return player.scale; }
	Math::Vector2 GetFuturePos() { return player.pos + player.move; }
	float  GetRadiusX() { return 22.0f * fabs(player.scale.x); }
	float  GetRadiusY() { return 20.0f * fabs(player.scale.y); }
	int GetHp() { return Hp; }
	bool GetAliveFlg();
	bool GetGard();
	unsigned long GetScore() { return m_score; }

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

	bool GetCharmFlg();

	void SetOwner(GameScene* owner) { m_owner = owner; }

private:

	GameScene* m_owner;

	KdTexture CharaTex;
	KdTexture BoxTex;
	KdTexture FunnelTex;
	KdTexture StunTex;
	KdTexture BulletTex;
	KdTexture IceTex;
	KdTexture SlowTex;
	KdTexture SilenceTex;
	KdTexture BleedTex;
	KdTexture CharmTex;

	Chara player;
	Chara box;
	Chara funnel;
	Chara stun;
	static const int BulletNum = 30;
	Chara bullet[BulletNum];
	static const int FunnelBulletNum = 30;
	Chara fbullet[FunnelBulletNum];
	Math::Matrix funnelRoteto;
	float funneldeg[FunnelBulletNum];
	Chara ice;
	Chara slow;
	Chara silence;
	Chara bleed;
	Chara charm;

	float m_deg;
	bool starFlg;
	bool rotateFlg;	//‰ñ“]
	bool stopFlg;	//’âŽ~

	float shotWait;
	float funnelWait;
	float stunWait;

	float movespeed;

	float stunAnimY;

	float iceWait;
	float iceAnimY;

	float slowWait;
	float slowAnimY;
	float slowmove;

	float silenceWait;
	float silenceAnimY;

	float bleedWait;
	float bleedAnimY;

	float charmWait;
	float charmAnimY;

	int Hp;
	bool HpDownFlg;
	float HpDownTime;

	unsigned long m_score = 0;

};