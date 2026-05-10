#pragma once

class Boss
{
public:

	Boss() {}
	~Boss() {}

	void Init();
	void Action(int stage);
	void Update();
	void Draw();
	void Release();

	void BulletRepop(int b);
	void ArrowRepop(int a);
	void B_BossHit(bool charm);
	void BulletHit(int b);
	void ArrowHit();

	void BulletInit();
	void BulletUpdate();
	void BulletDraw();

	void ArrowInit();
	void ArrowUpdate();
	void ArrowDraw();

	void RainInit();
	void RainUpdate();
	void RainDraw();

	Math::Vector2 GetPos() { return m_pos; }
	Math::Vector2 GetScale() { return m_scale; }
	float  GetRadius() { return 16.0f * fabs(m_scale.x); }
	bool GetAliveFlg();
	bool GetResultFlg();

	void SetHp(int a_hp) { BossHp = a_hp; }

	Math::Vector2 GetBulletPos(int b) { return m_buPos[b]; }
	int GetBulletNum() { return BulletNum; }
	bool GetBulletFlg(int b);

	Math::Vector2 GetArrowPos(int a) { return m_arPos[a]; }
	int GetArrowNum() { return ArrowNum; }
	bool GetArrowFlg(int a);

	Math::Vector2 GetRainPos(int r) { return m_raPos[r]; }
	int GetRainNum() { return RainNum; }
	bool GetRainFlg(int r);

private:

	KdTexture BossTex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Matrix Mat;
	Math::Matrix ScaleMat;
	Math::Matrix TransMat;
	bool aliveFlg;
	float AnimCnt;
	float m_alpha;
	int ShotRandom;
	int BossHp;
	bool BossHpDownFlg;
	float BossHpDownTime;

	bool ShotFlg;

	KdTexture m_BulletTex;

	static const int BulletNum = 20;
	Math::Vector2 m_buPos[BulletNum];
	Math::Vector2 m_buMove[BulletNum];
	Math::Vector2 m_buScale[BulletNum];
	Math::Matrix m_buMat[BulletNum];
	Math::Matrix m_buScaleMat[BulletNum];
	Math::Matrix m_buTransMat[BulletNum];
	bool m_buAliveFlg[BulletNum];
	float m_buAnimCnt[BulletNum];
	int m_buAnimY[BulletNum];
	float m_buAlpha[BulletNum];

	int ShotArrowRandom;
	bool ShotArrowFlg;

	KdTexture m_ArrowTex;

	static const int ArrowNum = 15;
	Math::Vector2 m_arPos[ArrowNum];
	Math::Vector2 m_arMove[ArrowNum];
	Math::Vector2 m_arScale[ArrowNum];
	Math::Matrix m_arMat[ArrowNum];
	Math::Matrix m_arScaleMat[ArrowNum];
	Math::Matrix m_arTransMat[ArrowNum];
	bool m_arAliveFlg[ArrowNum];

	bool BossHpHealFlg;
	int HealCoolTime;

	KdTexture m_RainTex;

	static const int RainNum = 15;
	Math::Vector2 m_raPos[RainNum];
	Math::Vector2 m_raMove[RainNum];
	Math::Vector2 m_raScale[RainNum];
	Math::Matrix m_raMat[RainNum];
	Math::Matrix m_raScaleMat[RainNum];
	Math::Matrix m_raTransMat[RainNum];
	bool m_raAliveFlg[RainNum];
	float m_raAnimCnt[RainNum];
	float m_raAlpha[RainNum];

	int ShotRainRandom;
	bool ShotRainFlg;

	bool resultFlg;

	KdTexture m_HpTex;
	Math::Vector2 m_hpPos;
	Math::Vector2 m_hpScale;
	Math::Matrix m_hpScaleMat;
	Math::Matrix m_hpTransMat;
	Math::Matrix m_hpMat;

	KdTexture m_BoxTex;
	Math::Vector2 m_boxPos;
	Math::Vector2 m_boxScale;
	Math::Matrix m_boxScaleMat;
	Math::Matrix m_boxTransMat;
	Math::Matrix m_boxMat;

};
