#include "PreCompile.h"
#include "UserGame.h"
#include <GameEngine\EngineVertex.h>
#include "UserGame_Resources_Shader.h"


void TextureLoading(GameEngineDirectory Dir)
{
	//std::vector<GameEngineFile> AllFile = Dir.GetAllFile();
	//
	//for (size_t i = 0; i < AllFile.size(); i++)
	//{
	//	GameEngineTextureManager::GetInst().Load(AllFile[i].GetFullPath());
	//	// Sleep(10);
	//}
	//
	//--UserGame::LoadingFolder;
}

void UserGame::ResourcesLoad()
{
	{
		GameEngineDirectory SoundDir;
		SoundDir.MoveParent("LGH_HollowKnight");
		SoundDir.MoveChild("Resources");
		SoundDir.MoveChild("Sound");
		SoundDir.MoveChild("BackGround");

		std::vector<GameEngineFile> AllFile = SoundDir.GetAllFile("mp3");

		for (size_t i = 0; i < AllFile.size(); i++)
		{
			GameEngineSoundManager::GetInst().Load(AllFile[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory SoundDir;
		SoundDir.MoveParent("LGH_HollowKnight");
		SoundDir.MoveChild("Resources");
		SoundDir.MoveChild("Sound");
		SoundDir.MoveChild("Monster");

		std::vector<GameEngineFile> AllFile = SoundDir.GetAllFile("wav");

		for (size_t i = 0; i < AllFile.size(); i++)
		{
			GameEngineSoundManager::GetInst().Load(AllFile[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory SoundDir;
		SoundDir.MoveParent("LGH_HollowKnight");
		SoundDir.MoveChild("Resources");
		SoundDir.MoveChild("Sound");
		SoundDir.MoveChild("Player");

		std::vector<GameEngineFile> AllFile = SoundDir.GetAllFile("wav");

		for (size_t i = 0; i < AllFile.size(); i++)
		{
			GameEngineSoundManager::GetInst().Load(AllFile[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("Monster");

		std::vector<GameEngineFile> AllFile = TextureDir.GetAllFile();

		for (size_t i = 0; i < AllFile.size(); i++)
		{
			GameEngineTextureManager::GetInst().Load(AllFile[i].GetFullPath());
		}

		GameEngineTexture* Texture = GameEngineTextureManager::GetInst().Find("FlyBug.png");
		Texture->Cut(5, 5);
		Texture = GameEngineTextureManager::GetInst().Find("CrawlBug.png");
		Texture->Cut(5, 3);

		Texture = GameEngineTextureManager::GetInst().Find("MiddleBoss.png");
		Texture->Cut(10, 8);

		Texture = GameEngineTextureManager::GetInst().Find("JumpBug.png");
		Texture->Cut(5, 8);

		Texture = GameEngineTextureManager::GetInst().Find("DashBug.png");
		Texture->Cut(5, 7);

		Texture = GameEngineTextureManager::GetInst().Find("FinalBoss.png");
		Texture->Cut(10, 11);

		Texture = GameEngineTextureManager::GetInst().Find("FinalBoss_2.png");
		Texture->Cut(10, 2);
	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("Monster");

		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("BossGroundWave"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("BossDropAttack"));
	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("UI");

		std::vector<GameEngineFile> AllFile = TextureDir.GetAllFile();

		for (size_t i = 0; i < AllFile.size(); i++)
		{
			GameEngineTextureManager::GetInst().Load(AllFile[i].GetFullPath());
		}

	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("UI");

		
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("HealthIdle"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("HealthBreak"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("HealthEmpty"));

	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("Knight");

		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("Idle"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("Run"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("Slash"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("SlashEffect"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("UpSlash"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("UpSlashEffect"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("DownSlash"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("DownSlashEffect"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("IdleToRun"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("RunToIdle"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("Jump"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("Airborne"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("Damage"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("DeathDamage"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("Death"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("DeathHead"));
	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("Map");


		std::vector<GameEngineFile> AllFile = TextureDir.GetAllFile();

		for (size_t i = 0; i < AllFile.size(); i++)
		{
			GameEngineTextureManager::GetInst().Load(AllFile[i].GetFullPath());
		}


		GameEngineTexture* Texture = GameEngineTextureManager::GetInst().Find("fog.png");
		Texture->Cut(5, 4);

		Texture = GameEngineTextureManager::GetInst().Find("Door.png");
		Texture->Cut(6, 2);
	
	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("Map");
		TextureDir.MoveChild("CollapseFloorPiece");

		std::vector<GameEngineFile> AllFile = TextureDir.GetAllFile();

		for (size_t i = 0; i < AllFile.size(); i++)
		{
			GameEngineTextureManager::GetInst().Load(AllFile[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("TitleScreen");

		std::vector<GameEngineFile> AllFile = TextureDir.GetAllFile();

		for (size_t i = 0; i < AllFile.size(); i++)
		{
			GameEngineTextureManager::GetInst().Load(AllFile[i].GetFullPath());
		}
		

		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("TitleBackGround"));
	}

	{
		GameEngineDirectory TextureDir;
		TextureDir.MoveParent("LGH_HollowKnight");
		TextureDir.MoveChild("Resources");
		TextureDir.MoveChild("Image");
		TextureDir.MoveChild("Effect");

		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("DamageEffect"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("StunEffect"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("AttackEffect"));
		GameEngineFolderTextureManager::GetInst().Load(TextureDir.PathToPlusFileName("MonsterStunEffect"));
	
	}



	AppShaderLoad();
}
