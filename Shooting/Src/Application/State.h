#pragma once

enum SceneTag
{
	Title,
	Tutorial,
	Game,
};

class State
{
public:

	State() {}
	virtual ~State() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;

	void SetKeyFlg(bool a_KeyFlg) { KeyFlg = a_KeyFlg; }
	SceneTag GetTag() { return m_tag; }
protected:

	bool KeyFlg;
	SceneTag m_tag;
};
