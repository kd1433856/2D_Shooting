#pragma once

struct MOJI
{
	Math::Vector2 m_pos;
	Math::Vector2 m_scale;
	Math::Matrix m_Mat;
	Math::Matrix m_TransMat;
	Math::Matrix m_SacleMat;
};

class ResultScene
{
public:

	ResultScene() {}
	~ResultScene() {}

	void Init();
	void Update(int stagePos, bool result);
	void Draw(int stagePos,bool result);
	void Release();

private:

	KdTexture m_mojiTex;
	KdTexture m_numTex;
	KdTexture m_titleTex;

	static const int stageNum = 5;
	MOJI stage[stageNum];

	MOJI number;

	static const int clearNum = 9;
	MOJI clear[clearNum];

	static const int gameoverNum = 8;
	MOJI game[gameoverNum];

	MOJI title;

};