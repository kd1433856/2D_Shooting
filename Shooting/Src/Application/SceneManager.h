#pragma once
#include"State.h"
#include"TitleScene.h"
#include"TutorialScene.h"
#include"GameScene.h"

class C_SceneManager
{
public:

	static C_SceneManager& GetInstance()
	{
		static C_SceneManager instance;
		return instance;
	}

	void ChangeState(State* newState)
	{
		delete currentState;
		currentState = newState;
	}

	void Init()
	{
		currentState->Init();
	}
	void Update()
	{
		currentState->Update();
	}

	void Draw()
	{
		currentState->Draw();
	}

	void Release()
	{
		currentState->Release();
	}

private:

	C_SceneManager() {}
	State* currentState = nullptr;
};

#define SCENEMANAGER C_SceneManager::GetInstance()

