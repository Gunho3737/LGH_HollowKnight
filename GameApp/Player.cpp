#include "PreCompile.h"
#include "GameEngine/GameEngineRenderer.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}



void Player::Start()
{
	// 정말 세팅해줘야할게 많은 녀석입니다.
	// 랜더러로서 뭐든지 다 그릴수있는 가능성을 가지고 있는 녀석.
	{
		GameEngineRenderer* Renderer = CreateTransformComponent<GameEngineRenderer>(GetTransform());
		Renderer->SetRenderingPipeLine("ColorRendering");
		Renderer->GetTransform()->SetLocalScaling({ 100.0f, 100.0f, 1.0f });
	}

	{
		GameEngineRenderer* Renderer = CreateTransformComponent<GameEngineRenderer>(GetTransform());
		Renderer->SetRenderingPipeLine("ColorRendering");
		Renderer->GetTransform()->SetLocalScaling({ 100.0f, 100.0f, 1.0f });
		Renderer->GetTransform()->SetLocalPosition({ 0.0f, 150.0f, 0.0f });
	}


}

void Player::Update(float _DeltaTime)
{

}