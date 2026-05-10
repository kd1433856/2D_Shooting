#pragma once

struct Score
{
	Math::Vector2 m_pos;
	Math::Vector2 m_scale;
	Math::Matrix transMat;
	Math::Matrix scaleMat;
	Math::Matrix Mat;
};

class ScoreDraw
{
public:

	ScoreDraw() {}
	~ScoreDraw() {}

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	KdTexture m_scoreTex;
	static const int scoreNum = 9;
	Score score[scoreNum];

};