// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOver.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UGameOver::NativeConstruct()
{
	if(MainMenuBtn)
	{
		MainMenuBtn->OnClicked.AddDynamic(this,&UGameOver::OnMainMenuClick);
	}

	if(RestartBtn)
	{
		RestartBtn->OnClicked.AddDynamic(this,&UGameOver::OnRestartClick);
	}
}

void UGameOver::OnMainMenuClick()
{
	UWorld* World = GetWorld();

	if(World)
	{
		UGameplayStatics::OpenLevel(World,TEXT("MainMenu"));
	}
}

void UGameOver::OnRestartClick()
{
	UWorld* World = GetWorld();

	if(World)
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World,TEXT("RestartLevel"));
	}
}
