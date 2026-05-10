#pragma once
#include"State.h"
#include"Back.h"

struct Exp
{
	Math::Vector2 m_pos;
	Math::Vector2 m_scale;
	Math::Matrix transMat;
	Math::Matrix scaleMat;
	Math::Matrix Mat;
};

class TutorialScene :public State
{
public:
	TutorialScene() {}
	~TutorialScene() { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;

	void Exp1Init();
	void Exp1Update();
	void Exp1Draw();

	void Exp2Init();
	void Exp2Update();
	void Exp2Draw();

	void Exp3Init();
	void Exp3Update();
	void Exp3Draw();

	void Exp4Init();
	void Exp4Update();
	void Exp4Draw();

private:

	C_Back back;

	KdTexture m_tex;
	KdTexture m_arrowtex;
	KdTexture m_keytex;
	KdTexture m_headtex;
	KdTexture m_movetex;
	KdTexture m_atkimgtex;
	KdTexture m_boximgtex;
	KdTexture m_starimgtex;
	KdTexture m_atkexptex;
	KdTexture m_boxexptex;
	KdTexture m_starexptex;
	KdTexture m_debufftex;
	KdTexture m_damegetex;
	KdTexture m_stagetex;
	KdTexture m_bosstex;
	KdTexture m_starttex;

	Exp exp;
	Exp head;

	static const int ArrowNum = 2;
	Exp arrow[ArrowNum];

	static const int Key1Num = 4;
	Exp key1[Key1Num];
	Exp keyexp1;

	static const int Key2Num = 3;
	Exp key2[Key2Num];
	static const int KeyExp2Num = 3;
	Exp keyexp2[KeyExp2Num];
	static const int KeyImgNum = 3;
	Exp keyimg[KeyImgNum];

	static const int Exp3Num = 2;
	Exp exp3[Exp3Num];

	static const int Exp4Num = 2;
	Exp exp4[Exp4Num];
	Exp start;

	int expNum;
	bool expFlg;

};