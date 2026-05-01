#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	player.Draw();
	phoenix.Draw();
	evil.Draw();
}

void Scene::Update()
{
	player.Update();
	phoenix.Action();
	phoenix.Update();
	evil.Action();
	evil.Update();
	if (player.GetGard() == false)
	{
		pe_hit.PhoenixHit();
	}
	be_hit.PBulletEnemy();
	be_hit.FBulletEnemy();
}

void Scene::Init()
{
	pe_hit.SetOwner(this);
	be_hit.SetOwner(this);
	player.SetOwner(this);
	srand(time(0));
	player.Init();
	phoenix.Init();
	evil.Init();
}

void Scene::Release()
{
	player.Release();
	phoenix.Release();
	evil.Release();
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
