#pragma once
#include <GameEngineBase/GameEngineObjectNameBase.h>
#include "GameEngineTransform.h"

// 설명 :
class GameEngineComponent;
class GameEngineLevel;
class GameEngineTransform;
class GameEngineTransformComponent;
class GameEngineActor : public GameEngineObjectNameBase
{
	friend GameEngineLevel;

public:

	// constrcuter destructer
	GameEngineActor();
	~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	bool IsFindObject_;
	bool NextLevelMove_;
	bool IsDestroyed_;
	float DeathTime_;

	void MoveNextOn()
	{
		NextLevelMove_ = true;
	}

	GameEngineLevel* GetLevel()
	{
		return Level_;
	}

	template<typename LevelType>
	LevelType* GetLevelConvert()
	{
		return dynamic_cast<LevelType*>(Level_);
	}


	void Release(float _Time = 0.0f)
	{
		if (0.0f >= _Time)
		{
			Death();
		}
		else
		{
			IsDestroyed_ = true;
			DeathTime_ = _Time;
		}
	}

	template<typename ComponentType>
	ComponentType* CreateComponent(int _Order = 0)
	{
		GameEngineComponent* NewComponent = new ComponentType();
		NewComponent->SetParent(this);
		NewComponent->SetOrder(_Order);
		NewComponent->InitComponent(this);
		ComponentList_.push_back(NewComponent);
		NewComponent->Start();
		return dynamic_cast<ComponentType*>(NewComponent);;
	}

	template<typename ComponentType>
	ComponentType* CreateTransformComponent(int _Order = 0)
	{
		// 업캐스팅을 이용해서 컴파일 에러를 낼것이다.
		GameEngineTransformComponent* NewComponent = new ComponentType();
		NewComponent->SetParent(this);
		NewComponent->SetOrder(_Order);
		NewComponent->InitComponent(this);
		NewComponent->AttachTransform(GetTransform());
		TransformComponentList_.push_back(NewComponent);

		NewComponent->Start();
		return dynamic_cast<ComponentType*>(NewComponent);;
	}

	template<typename ComponentType>
	ComponentType* CreateTransformComponent(GameEngineTransform* _Transform, int _Order = 0)
	{
		// 업캐스팅을 이용해서 컴파일 에러를 낼것이다.
		GameEngineTransformComponent* NewComponent = new ComponentType();
		NewComponent->SetParent(this);
		NewComponent->SetOrder(_Order);
		NewComponent->InitComponent(this);
		if (nullptr == _Transform)
		{
			GameEngineDebug::MsgBoxError("트랜스폼을 세팅안 해줬습니다.");
		}
		NewComponent->AttachTransform(_Transform);
		TransformComponentList_.push_back(NewComponent);

		NewComponent->Start();
		return dynamic_cast<ComponentType*>(NewComponent);;
	}

protected:
	virtual void Start() {}
	virtual void Update(float _DeltaTime) {}
	virtual void ReleaseEvent() {}
	virtual void LevelChangeEndEvent(GameEngineLevel* _NextLevel) {}
	virtual void LevelChangeStartEvent(GameEngineLevel* _PrevLevel) {}


	// 트랜스폼을 변화시킨다는걸 기본적으로 생각할겁니다.

////////////////////////

public:
	GameEngineTransform* GetTransform()
	{
		return &Transform_;
	}

private:
	GameEngineTransform Transform_;
	GameEngineLevel* Level_;

	// Status
	std::list<GameEngineComponent*> ComponentList_;

	std::list<GameEngineTransformComponent*> TransformComponentList_;

	void SetLevel(GameEngineLevel* Level);

	void UpdateComponent(float _DeltaTime);

	void ComponentRelease();

	void ReleaseUpdate(float _DeltaTime);
};

