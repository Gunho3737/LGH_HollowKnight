#pragma once
#include <GameEngine/GameEngineActor.h>

// ���� :
class Attack;
class GameEngineImageRenderer;
class Player : public GameEngineActor
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	
protected:
	GameEngineImageRenderer* PlayerImageRenderer;
	GameEngineCollision* PlayerCollision;
	float Speed;

private:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	void Slash();
};

