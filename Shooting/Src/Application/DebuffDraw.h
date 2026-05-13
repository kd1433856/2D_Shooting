#pragma once

struct Debuff
{
	KdTexture m_Tex;
	Math::Vector2 m_pos;
	Math::Vector2 m_scale;
	Math::Matrix m_Mat;
	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;
	float AnimCnt;
	float AnimY;
	bool aliveFlg;
};

class DebuffDraw
{
public:

	DebuffDraw() {}
	~DebuffDraw() {}

	void Init();
	void Update();
	void Draw();
	void Relaese();

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

	void SetStunFlg(bool Flg) { stun.aliveFlg = Flg; }
	void SetSlowFlg(bool Flg) { slow.aliveFlg = Flg; }
	void SetSilenceFlg(bool Flg) { silence.aliveFlg = Flg; }
	void SetIceFlg(bool Flg) { ice.aliveFlg = Flg; }
	void SetBleedFlg(bool Flg) { bleed.aliveFlg = Flg; }
	void SetCharmFlg(bool Flg) { charm.aliveFlg = Flg; }

private:

	Debuff stun;
	Debuff slow;
	Debuff silence;
	Debuff ice;
	Debuff bleed;
	Debuff charm;

	static const int BoxNum = 6;
	Debuff box[BoxNum];

};