#pragma once
#include <GameEngine/GameEngineLevel.h>

// ���� :
class Player;
class MiddleRoomLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	MiddleRoomLevel();
	~MiddleRoomLevel();

	// delete Function
	MiddleRoomLevel(const MiddleRoomLevel& _Other) = delete;
	MiddleRoomLevel(MiddleRoomLevel&& _Other) noexcept = delete;
	MiddleRoomLevel& operator=(const MiddleRoomLevel& _Other) = delete;
	MiddleRoomLevel& operator=(MiddleRoomLevel&& _Other) noexcept = delete;

protected:
	Player* PlayerActor;
	float4 PlayerPos;

private:
	void LevelStart() override;
	void LevelUpdate(float _DeltaTime) override;
	void LevelChangeEndEvent() override;
	void LevelChangeStartEvent() override;

};

