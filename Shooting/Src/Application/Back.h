#pragma once

struct Back
{
	KdTexture m_Tex;
	Math::Matrix m_Scale;
	Math::Matrix m_Trans_1;
	Math::Matrix m_Trans_2;
	Math::Matrix m_Mat_1;
	Math::Matrix m_Mat_2;
};

class C_Back
{
public:

	C_Back() {}
	~C_Back() {}

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	Back b1;
	Back b2;
	Back b3;
	Back b4;
	int BackX;

};