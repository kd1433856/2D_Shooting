#pragma once
#include"main.h"
#include"State.h"
#include"Back.h"

class TitleScene :public State
{
public:
	TitleScene() {}
	~TitleScene() { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;

private:

	KdTexture PlayerTex;

	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Matrix m_Mat;
	Math::Matrix m_TransMat;
	Math::Matrix m_ScaleMat;
	float AnimCnt;

	KdTexture TitleTex;

	Math::Matrix TitleScale;
	Math::Matrix TitleTrans;
	Math::Matrix TitleMat;

	KdTexture PressTex;

	Math::Matrix PressScale;
	Math::Matrix PressTrans;
	Math::Matrix PressMat;

	C_Back back;

};