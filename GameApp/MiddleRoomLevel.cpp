#include "PreCompile.h"
#include "MiddleRoomLevel.h"
#include "Player.h"
#include "UI_HpBar.h"
#include "FlyBug.h"
#include "BitMap.h"
#include "ViewMap.h"
#include <GameEngine\PostFade.h>
#include <GameEngine/CameraComponent.h>
#include <GameEngine/GameEngineTransform.h>
#include <GameEngine/CameraActor.h>
#include <GameEngine/GameEngineGUI.h>
#include <GameEngine/GameEngineRenderWindow.h>

MiddleRoomLevel::MiddleRoomLevel() // default constructer 디폴트 생성자
{

}

MiddleRoomLevel::~MiddleRoomLevel() // default destructer 디폴트 소멸자
{

}

void MiddleRoomLevel::LevelStart()
{

	GetMainCamera()->SetProjectionMode(ProjectionMode::Orthographic);
	GetMainCameraActor()->GetTransform()->SetLocalPosition(float4(0.0f, 0.0f, -100.0f));

	FadeEffect = AddPostProcessCameraMergeNext<PostFade>();
	FadeEffect->SetTarget(GameEngineDevice::GetBackBufferTarget());

	Reverse = false;

	{
		BitMapActor = CreateActor<BitMap>();
		BitMapActor->Progress = MapProgress::MIDDLEROOM;
	}

	{
		ViewMap* Player = CreateActor<ViewMap>();
	}

	{
		PlayerActor = CreateActor<Player>();
		PlayerActor->PlayerDirection = LeftRight::RIGHT;
		PlayerActor->GetTransform()->SetLocalPosition({ 9600.0f,-2850.0f });
		GetMainCameraActor()->GetTransform()->SetWorldPosition(PlayerActor->GetTransform()->GetLocalPosition());
	}

	{
		FlyBug* Actor = CreateActor<FlyBug>();
		Actor->Direction = LeftRight::LEFT;
		Actor->GetTransform()->SetWorldPosition(float4(10000.0f, -2900.0f, 0.0f));
	}

	{
		UI_HpBar* Actor = CreateActor<UI_HpBar>();
		Actor->GetTransform()->SetWorldPosition(float4(0.0f, 0.0f, 0.0f));
	}

}

void MiddleRoomLevel::LevelUpdate(float _DeltaTime)
{
	//프리카메라 상태 온오프
	if (true == GameEngineInput::GetInst().Down("FreeCameraOn"))
	{
		GetMainCameraActor()->FreeCameraModeSwitch();
	}

	if (true == GetMainCameraActor()->IsFreeCameraMode())
	{
		return;
	}


	if (true == GameEngineInput::GetInst().Down("DebugOn"))
	{
		if (false == IsDebugCheck())
		{
			DebugOn();
		}
		else
		{
			DebugOff();
		}

	}

	PlayerPos = PlayerActor->GetTransform()->GetLocalPosition();

	if (PlayerPos.y < -2760.0f)
	{
		if (PlayerPos.x < 10250.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ 10250.0f, -2760.0f, PlayerPos.z });
		}
		else if (PlayerPos.x >= 10250.0f && PlayerPos.x <= 10300.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ PlayerPos.x, -2760.0f, PlayerPos.z });
		}
		else if (PlayerPos.x >= 10300.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ 10300.0f, -2760.0f, PlayerPos.z });
		}
	}
	

	if (PlayerPos.y >= -2760.0f && PlayerPos.y <= -1600.0f )
	{
		if (PlayerPos.x < 10250.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ 10250.0f, PlayerPos.y, PlayerPos.z });
		}
		else if (PlayerPos.x >= 10250.0f && PlayerPos.x <= 10300.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ PlayerPos.x, PlayerPos.y, PlayerPos.z });
		}
		else if (PlayerPos.x >= 10300.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ 10300.0f, PlayerPos.y, PlayerPos.z });
		}
	}


	if (PlayerPos.y > -1600.0f)
	{
		if (PlayerPos.x < 10250.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ 10250.0f, -1600.0f, PlayerPos.z });
		}
		else if (PlayerPos.x >= 10250.0f && PlayerPos.x <= 10300.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ PlayerPos.x, -1600.0f, PlayerPos.z });
		}
		else if (PlayerPos.x >= 10300.0f)
		{
			GetMainCameraActor()->GetTransform()->SetLocalPosition({ 10300.0f, -1600.0f, PlayerPos.z });
		}
	}


	static bool Check = false;

	if (false == Check && nullptr != GameEngineGUI::GetInst()->FindGUIWindow("RenderWindow"))
	{
		GameEngineRenderWindow* Window = GameEngineGUI::GetInst()->FindGUIWindowConvert<GameEngineRenderWindow>("RenderWindow");
		float4 Size = {128, 72};
		Window->PushRenderTarget("메인 카메라 타겟", GetMainCamera()->GetCameraRenderTarget(), Size * 3);
		Window->PushRenderTarget("UI 카메라 타겟", GetUICamera()->GetCameraRenderTarget(), Size * 3);
		//Window->PushRenderTarget("PostEffectFade", PlayerActor->FadeEffect->GetResult(), Size * 3);
		Check = true;
	}

	if (true == GameEngineInput::GetInst().Down("LevelControl"))
	{
		GameEngineGUIWindow* Window = GameEngineGUI::GetInst()->FindGUIWindow("LevelControlWindow");

		Window->OnOffChange();
	}

}

void MiddleRoomLevel::LevelChangeEndEvent(GameEngineLevel* _NextLevel)
{
	GameEngineLevel::PrevMap = "MiddleRoom";
}

void MiddleRoomLevel::LevelChangeStartEvent(GameEngineLevel* _PrevLevel)
{
	FadeOn();

	Player::MainPlayer = PlayerActor;

	{
		BitMapActor->Progress = MapProgress::MIDDLEROOM;
	}

	if (GameEngineLevel::PrevMap == "BenchRoom")
	{
		Reverse = false;
	}

	if (Reverse == false)
	{
		PlayerActor->PlayerDirection = LeftRight::RIGHT;
		PlayerActor->GetTransform()->SetLocalPosition({ 9600.0f,-2850.0f });
		GetMainCameraActor()->GetTransform()->SetWorldPosition(PlayerActor->GetTransform()->GetLocalPosition());
		Reverse = true;
	}
	else
	{
		PlayerActor->PlayerDirection = LeftRight::RIGHT;
		PlayerActor->GetTransform()->SetLocalPosition({ 9600.0f,-1550.0f });
		GetMainCameraActor()->GetTransform()->SetWorldPosition(PlayerActor->GetTransform()->GetLocalPosition());
	}
}

void MiddleRoomLevel::FadeOn()
{
	FadeEffect->SetData(0.5f, FadeOption::LIGHT);
}

void MiddleRoomLevel::FadeOff()
{
	FadeEffect->SetData(0.5f, FadeOption::DARK);
}
