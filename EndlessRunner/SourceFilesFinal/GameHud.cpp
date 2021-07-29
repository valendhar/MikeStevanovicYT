// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHud.h"



#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UGameHud::NativeConstruct()
{
	if(PauseBtn)
	{
		PauseBtn->OnClicked.AddDynamic(this,&UGameHud::OnPauseClick);
	}

	UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(UGameplayStatics::GetPlayerController(GetWorld(),0),this);
}

void UGameHud::InitializeHUD(AEndlessRunnerGameModeBase* RunGameMode)
{
	if(RunGameMode)
	{
		CoinsCount->SetText(FText::AsNumber(0));
		LivesCount->SetText(FText::AsNumber(RunGameMode->MaxLives));

		RunGameMode->OnCoinsCountChanged.AddDynamic(this, &UGameHud::SetCoinsCount);
		RunGameMode->OnLivesCountChanged.AddDynamic(this, &UGameHud::SetLivesCount);
	}	
}

void UGameHud::SetCoinsCount(const int32 Count)
{
	CoinsCount->SetText(FText::AsNumber(Count));
}

void UGameHud::SetLivesCount(int32 Count)
{
	LivesCount->SetText(FText::AsNumber(Count));
}

void UGameHud::OnPauseClick()
{
	if(IsValid(PauseMenuWidgetClass))
	{
		UGameplayStatics::SetGamePaused(GetWorld(),true);
	
		UUserWidget* Widget = CreateWidget(GetWorld(),PauseMenuWidgetClass);

		if(Widget)
		{
			Widget->AddToViewport();
		}
	}
}



