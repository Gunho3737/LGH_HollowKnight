#include "PreCompile.h"
#include "UI_HpBar.h"
#include "GameEngine/GameEngineUIRenderer.h"

UI_HpBar::UI_HpBar()
{
}

UI_HpBar::~UI_HpBar()
{
}

void UI_HpBar::Start()
{
	GameEngineUIRenderer* UIRenderer = CreateTransformComponent<GameEngineUIRenderer>(GetTransform());
	UIRenderer->SetImage("hpbar.png");
	UIRenderer->GetTransform()->SetLocalScaling({ 100.0f, 100.0f, 1.0f });
	UIRenderer->GetTransform()->SetLocalPosition({ 0.0f, 360.0f - 50.0f, 0.0f });
}

void  UI_HpBar::Update(float _DeltaTime)
{
	
}