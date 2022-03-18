#pragma once
#include <GameEngine/GameEngineActor.h>

// ���� :
class FlyBug : public GameEngineActor
{
public:
	// constrcuter destructer
	FlyBug();
	~FlyBug();

	// delete Function
	FlyBug(const FlyBug& _Other) = delete;
	FlyBug(FlyBug&& _Other) noexcept = delete;
	FlyBug& operator=(const FlyBug& _Other) = delete;
	FlyBug& operator=(FlyBug&& _Other) noexcept = delete;

	GameEngineImageRenderer* PlayerImageRenderer;
	GameEngineCollision* Collision;

protected:
	//�ݹ��Լ��� �Լ�, ��ɿ� ���缭 �̸�������
	void TestStartCallBack();
	void Die();

	int HP = 3;


private:
	void Start() override;
	void Update(float _DeltaTime) override;
};
