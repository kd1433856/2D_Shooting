#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	player.Draw();
	player.FunnelDraw();
	player.BoxDraw();
	player.StunDraw();
	player.BulletDraw();
}

void Scene::Update()
{
	player.Update();
	player.BoxUpdate();
	player.FunnelUpdate();
	player.BulletUpdate();
}

void Scene::Init()
{
	player.Init();
	player.BoxInit();
	player.FunnelInit();
	player.StunInit();
	player.BulletInit();
}

void Scene::Release()
{
	
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
