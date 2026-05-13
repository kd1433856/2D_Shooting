#include "DebuffDraw.h"

void DebuffDraw::Init()
{
	StunInit();
	SlowInit();
	SilenceInit();
	IceInit();
	BleedInit();
	CharmInit();
}

void DebuffDraw::Update()
{
	if (stun.aliveFlg == true)
	{
		StunUpdate();
	}
	if (slow.aliveFlg == true)
	{
		SlowUpdate();
	}
	if (silence.aliveFlg == true)
	{
		SilenceUpdate();
	}
	if (ice.aliveFlg == true)
	{
		IceUpdate();
	}
	if (bleed.aliveFlg == true)
	{
		BleedUpdate();
	}
	if (charm.aliveFlg == true)
	{
		CharmUpdate();
	}
}

void DebuffDraw::Draw()
{
	if (stun.aliveFlg == true)
	{
		StunDraw();
	}
	if (slow.aliveFlg == true)
	{
		SlowDraw();
	}
	if (silence.aliveFlg == true)
	{
		SilenceDraw();
	}
	if (ice.aliveFlg == true)
	{
		IceDraw();
	}
	if (bleed.aliveFlg == true)
	{
		BleedDraw();
	}
	if (charm.aliveFlg == true)
	{
		CharmDraw();
	}
}

void DebuffDraw::Relaese()
{
	stun.m_Tex.Release();
}

void DebuffDraw::StunInit()
{
	stun.m_pos = { -600,220 };
	stun.m_scale = { 1.7,1.7 };
	stun.AnimCnt = 0.0f;
	stun.AnimY = 0;
	stun.aliveFlg = false;

	stun.m_Tex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/StunEffect/Spritesheets/StunEffect_Sheet_64x64.png");

	box[0].m_pos = { -600,250 };
	box[0].m_scale = { 1.1,1.1 };

	box[0].m_Tex.Load("Texture/Box.png");
}

void DebuffDraw::StunUpdate()
{
	stun.AnimCnt += 0.15f;
	if (stun.AnimCnt > 4)
	{
		stun.AnimCnt = 0;
		stun.AnimY += 1;
		if (stun.AnimY > 4)
		{
			stun.AnimY = 0;
		}
	}

	stun.m_TransMat = Math::Matrix::CreateTranslation(stun.m_pos.x, stun.m_pos.y, 0);
	stun.m_ScaleMat = Math::Matrix::CreateScale(stun.m_scale.x, stun.m_scale.y, 1);
	stun.m_Mat = stun.m_ScaleMat * stun.m_TransMat;

	box[0].m_TransMat = Math::Matrix::CreateTranslation(box[0].m_pos.x, box[0].m_pos.y, 0);
	box[0].m_ScaleMat = Math::Matrix::CreateScale(box[0].m_scale.x, box[0].m_scale.y, 1);
	box[0].m_Mat = box[0].m_ScaleMat * box[0].m_TransMat;
}

void DebuffDraw::StunDraw()
{
	SHADER.m_spriteShader.SetMatrix(box[0].m_Mat);
	SHADER.m_spriteShader.DrawTex(&box[0].m_Tex, Math::Rectangle{0,0,64,64}, 1.0f);

	SHADER.m_spriteShader.SetMatrix(stun.m_Mat);
	SHADER.m_spriteShader.DrawTex(&stun.m_Tex, Math::Rectangle{ 64 * (int)stun.AnimCnt,64 * (int)stun.AnimY,64,64 }, 1.0f);
}

void DebuffDraw::SlowInit()
{
	slow.m_pos = { -530,250 };
	slow.m_scale = { 1.7,1.7 };
	slow.AnimCnt = 0.0f;
	slow.AnimY = 0;
	slow.aliveFlg = false;

	slow.m_Tex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/SlowEffect/Spritesheets/SlowEffect_Sheet_64x64.png");

	box[1].m_pos = { -530,250 };
	box[1].m_scale = { 1.1,1.1 };

	box[1].m_Tex.Load("Texture/Box.png");
}

void DebuffDraw::SlowUpdate()
{
	slow.AnimCnt += 0.15f;
	if (slow.AnimCnt > 4)
	{
		slow.AnimCnt = 0;
		slow.AnimY += 1;
		if (slow.AnimY > 4)
		{
			slow.AnimY = 0;
		}
	}

	slow.m_TransMat = Math::Matrix::CreateTranslation(slow.m_pos.x, slow.m_pos.y, 0);
	slow.m_ScaleMat = Math::Matrix::CreateScale(slow.m_scale.x, slow.m_scale.y, 1);
	slow.m_Mat = slow.m_ScaleMat * slow.m_TransMat;

	box[1].m_TransMat = Math::Matrix::CreateTranslation(box[1].m_pos.x, box[1].m_pos.y, 0);
	box[1].m_ScaleMat = Math::Matrix::CreateScale(box[1].m_scale.x, box[1].m_scale.y, 1);
	box[1].m_Mat = box[1].m_ScaleMat * box[1].m_TransMat;
}

void DebuffDraw::SlowDraw()
{
	SHADER.m_spriteShader.SetMatrix(box[1].m_Mat);
	SHADER.m_spriteShader.DrawTex(&box[1].m_Tex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(slow.m_Mat);
	SHADER.m_spriteShader.DrawTex(&slow.m_Tex, Math::Rectangle{ 64 * (int)slow.AnimCnt,64 * (int)slow.AnimY,64,64 }, 1.0f);
}

void DebuffDraw::SilenceInit()
{
	silence.m_pos = { -460,250 };
	silence.m_scale = { 1.6,1.6 };
	silence.AnimCnt = 0.0f;
	silence.AnimY = 0;
	silence.aliveFlg = false;

	silence.m_Tex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/SilenceEffect/Spritesheets/SilenceEffect_Sheet_64x64.png");

	box[2].m_pos = { -460,250 };
	box[2].m_scale = { 1.1,1.1 };

	box[2].m_Tex.Load("Texture/Box.png");
}

void DebuffDraw::SilenceUpdate()
{
	silence.AnimCnt += 0.15f;
	if (silence.AnimCnt > 4)
	{
		silence.AnimCnt = 0;
		silence.AnimY += 1;
		if (silence.AnimY > 4)
		{
			silence.AnimY = 0;
		}
	}

	silence.m_TransMat = Math::Matrix::CreateTranslation(silence.m_pos.x, silence.m_pos.y, 0);
	silence.m_ScaleMat = Math::Matrix::CreateScale(silence.m_scale.x, silence.m_scale.y, 1);
	silence.m_Mat = silence.m_ScaleMat * silence.m_TransMat;

	box[2].m_TransMat = Math::Matrix::CreateTranslation(box[2].m_pos.x, box[2].m_pos.y, 0);
	box[2].m_ScaleMat = Math::Matrix::CreateScale(box[2].m_scale.x, box[2].m_scale.y, 1);
	box[2].m_Mat = box[2].m_ScaleMat * box[2].m_TransMat;
}

void DebuffDraw::SilenceDraw()
{
	SHADER.m_spriteShader.SetMatrix(box[2].m_Mat);
	SHADER.m_spriteShader.DrawTex(&box[2].m_Tex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(silence.m_Mat);
	SHADER.m_spriteShader.DrawTex(&silence.m_Tex, Math::Rectangle{ 64 * (int)silence.AnimCnt,64 * (int)silence.AnimY,64,64 }, 1.0f);
}

void DebuffDraw::IceInit()
{
	ice.m_pos = { -600,180 };
	ice.m_scale = { 1.7,1.7 };
	ice.AnimCnt = 0.0f;
	ice.AnimY = 0;
	ice.aliveFlg = false;

	ice.m_Tex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/FreezeEffect/Spritesheets/FreezeEffect_Sheet_64x64.png");

	box[3].m_pos = { -600,180 };
	box[3].m_scale = { 1.1,1.1 };

	box[3].m_Tex.Load("Texture/Box.png");
}

void DebuffDraw::IceUpdate()
{
	ice.AnimCnt += 0.15f;
	if (ice.AnimCnt > 4)
	{
		ice.AnimCnt = 0;
		ice.AnimY += 1;
		if (ice.AnimY > 4)
		{
			ice.AnimY = 0;
		}
	}

	ice.m_TransMat = Math::Matrix::CreateTranslation(ice.m_pos.x, ice.m_pos.y, 0);
	ice.m_ScaleMat = Math::Matrix::CreateScale(ice.m_scale.x, ice.m_scale.y, 1);
	ice.m_Mat = ice.m_ScaleMat * ice.m_TransMat;

	box[3].m_TransMat = Math::Matrix::CreateTranslation(box[3].m_pos.x, box[3].m_pos.y, 0);
	box[3].m_ScaleMat = Math::Matrix::CreateScale(box[3].m_scale.x, box[3].m_scale.y, 1);
	box[3].m_Mat = box[3].m_ScaleMat * box[3].m_TransMat;
}

void DebuffDraw::IceDraw()
{
	SHADER.m_spriteShader.SetMatrix(box[3].m_Mat);
	SHADER.m_spriteShader.DrawTex(&box[3].m_Tex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(ice.m_Mat);
	SHADER.m_spriteShader.DrawTex(&ice.m_Tex, Math::Rectangle{ 64 * (int)ice.AnimCnt,64 * (int)ice.AnimY,64,64 }, 1.0f);
}

void DebuffDraw::BleedInit()
{
	bleed.m_pos = { -530,190 };
	bleed.m_scale = { 1.4,1.4 };
	bleed.AnimCnt = 0.0f;
	bleed.AnimY = 0;
	bleed.aliveFlg = false;

	bleed.m_Tex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/BleedEffect/Spritesheets/BleedEffect_Sheet_64x64.png");

	box[4].m_pos = { -530,180 };
	box[4].m_scale = { 1.1,1.1 };

	box[4].m_Tex.Load("Texture/Box.png");
}

void DebuffDraw::BleedUpdate()
{
	bleed.AnimCnt += 0.15f;
	if (bleed.AnimCnt > 4)
	{
		bleed.AnimCnt = 0;
		bleed.AnimY += 1;
		if (bleed.AnimY > 4)
		{
			bleed.AnimY = 0;
		}
	}

	bleed.m_TransMat = Math::Matrix::CreateTranslation(bleed.m_pos.x, bleed.m_pos.y, 0);
	bleed.m_ScaleMat = Math::Matrix::CreateScale(bleed.m_scale.x, bleed.m_scale.y, 1);
	bleed.m_Mat = bleed.m_ScaleMat * bleed.m_TransMat;

	box[4].m_TransMat = Math::Matrix::CreateTranslation(box[4].m_pos.x, box[4].m_pos.y, 0);
	box[4].m_ScaleMat = Math::Matrix::CreateScale(box[4].m_scale.x, box[4].m_scale.y, 1);
	box[4].m_Mat = box[4].m_ScaleMat * box[4].m_TransMat;
}

void DebuffDraw::BleedDraw()
{
	SHADER.m_spriteShader.SetMatrix(box[4].m_Mat);
	SHADER.m_spriteShader.DrawTex(&box[4].m_Tex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(bleed.m_Mat);
	SHADER.m_spriteShader.DrawTex(&bleed.m_Tex, Math::Rectangle{ 64 * (int)bleed.AnimCnt,64 * (int)bleed.AnimY,64,64 }, 1.0f);
}

void DebuffDraw::CharmInit()
{
	charm.m_pos = { -460,160 };
	charm.m_scale = { 1.7,1.7 };
	charm.AnimCnt = 0.0f;
	charm.AnimY = 0;
	charm.aliveFlg = false;

	charm.m_Tex.Load("Texture/Vivid_Motion_23_ Universal_Status_Effects/CharmEffect/Spritesheets/CharmEffect_Sheet_64x64.png");

	box[5].m_pos = { -460,180 };
	box[5].m_scale = { 1.1,1.1 };

	box[5].m_Tex.Load("Texture/Box.png");
}

void DebuffDraw::CharmUpdate()
{
	charm.AnimCnt += 0.15f;
	if (charm.AnimCnt > 4)
	{
		charm.AnimCnt = 0;
		charm.AnimY += 1;
		if (charm.AnimY > 4)
		{
			charm.AnimY = 0;
		}
	}

	charm.m_TransMat = Math::Matrix::CreateTranslation(charm.m_pos.x, charm.m_pos.y, 0);
	charm.m_ScaleMat = Math::Matrix::CreateScale(charm.m_scale.x, charm.m_scale.y, 1);
	charm.m_Mat = charm.m_ScaleMat * charm.m_TransMat;

	box[5].m_TransMat = Math::Matrix::CreateTranslation(box[5].m_pos.x, box[5].m_pos.y, 0);
	box[5].m_ScaleMat = Math::Matrix::CreateScale(box[5].m_scale.x, box[5].m_scale.y, 1);
	box[5].m_Mat = box[5].m_ScaleMat * box[5].m_TransMat;
}

void DebuffDraw::CharmDraw()
{
	SHADER.m_spriteShader.SetMatrix(box[5].m_Mat);
	SHADER.m_spriteShader.DrawTex(&box[5].m_Tex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(charm.m_Mat);
	SHADER.m_spriteShader.DrawTex(&charm.m_Tex, Math::Rectangle{ 64 * (int)charm.AnimCnt,64 * (int)charm.AnimY,64,64 }, 1.0f);
}
