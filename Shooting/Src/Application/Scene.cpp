#include "main.h"
#include "Scene.h"
#include"SceneManager.h"

void Scene::Draw2D()
{
	SCENEMANAGER.Draw();
}

void Scene::Update()
{
	SCENEMANAGER.Update();
}

void Scene::Init()
{
	SCENEMANAGER.ChangeState(new TitleScene());
	SCENEMANAGER.Init();
}

void Scene::Release()
{
	SCENEMANAGER.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
