// Copyright Epic Games, Inc. All Rights Reserved.


#include "EndlessRunnerGameModeBase.h"

#include "FloorTile.h"
#include "GameHud.h"
#include "Blueprint/UserWidget.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"

void AEndlessRunnerGameModeBase::BeginPlay()
{
	UGameplayStatics::GetPlayerController(GetWorld(),0)->bShowMouseCursor = true;

	GameHud = Cast<UGameHud>(CreateWidget(GetWorld(),GameHudClass));
	check(GameHud);

	GameHud->InitializeHUD(this);
	GameHud->AddToViewport();

	NumberOfLives = MaxLives;
		
	CreateInitialFloorTiles();
}

void AEndlessRunnerGameModeBase::CreateInitialFloorTiles()
{
	AFloorTile* Tile = AddFloorTile(false);

	if(Tile)
	{
		LaneSwitchValues.Add(Tile->LeftLane->GetComponentLocation().Y);
		LaneSwitchValues.Add(Tile->CenterLane->GetComponentLocation().Y);
		LaneSwitchValues.Add(Tile->RightLane->GetComponentLocation().Y);
	}

	/*for(float Val : LaneSwitchValues)
	{
		UE_LOG(LogTemp,Warning,TEXT("LANE VALUE: %f"),Val);
	}*/

	AddFloorTile(false);
	AddFloorTile(false);
	
	for(int i=0;i<NumInitialFloorTiles;i++)
	{
		AddFloorTile(true);
	}	
}

AFloorTile* AEndlessRunnerGameModeBase::AddFloorTile(bool bSpawnItems)
{
	UWorld* World = GetWorld();

	if(World)
	{
		AFloorTile* Tile = World->SpawnActor<AFloorTile>(FloorTileClass,NextSpawnPoint);

		if(Tile)
		{
			FloorTiles.Add(Tile);
			
			if(bSpawnItems)
			{
				Tile->SpawnItems();
			}
			
			NextSpawnPoint = Tile->GetAttachTransform();		
		}

		return Tile;
	}

	return nullptr;
}



void AEndlessRunnerGameModeBase::AddCoin()
{
	TotalCoins += 1;

	OnCoinsCountChanged.Broadcast(TotalCoins);
}

void AEndlessRunnerGameModeBase::PlayerDied()
{
	NumberOfLives -= 1;
	OnLivesCountChanged.Broadcast(NumberOfLives);

	if(NumberOfLives > 0)
	{
		// Iterate all FloorTiles and call DestroyFloorTile
		for(auto Tile : FloorTiles)
		{
			Tile->DestroyFloorTile();
		}
		
		// Empty our array
		FloorTiles.Empty();
		
		// set NextSpawnPoint to initial value
		NextSpawnPoint = FTransform();
		
		// Create out Initial floor tiles
		CreateInitialFloorTiles();
		
		// Broadcast level reset event
		OnLevelReset.Broadcast();
	}
	else
	{
		GameOver();
	}
}

void AEndlessRunnerGameModeBase::GameOver()
{
	if(IsValid(GameOverScreenClass))
	{
		UUserWidget* Widget = CreateWidget(GetWorld(),GameOverScreenClass);

		if(Widget)
		{
			Widget->AddToViewport();
		}
	}
}

void AEndlessRunnerGameModeBase::AddCoins(int32 NumCoins)
{
	TotalCoins += NumCoins;

	OnCoinsCountChanged.Broadcast(TotalCoins);
}

void AEndlessRunnerGameModeBase::RemoveTile(AFloorTile* Tile)
{
	if(FloorTiles.Contains(Tile))
	{
		FloorTiles.Remove(Tile);
	}
}


