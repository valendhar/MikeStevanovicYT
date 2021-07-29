// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenu::NativeConstruct()
{
	if(StartBtn)
	{
		StartBtn->OnClicked.AddDynamic(this,&UMainMenu::OnStartClick);
	}

	if(QuitBtn)
	{
		QuitBtn->OnClicked.AddDynamic(this,&UMainMenu::OnQuitClick);
	}
}

void UMainMenu::OnStartClick()
{
	UWorld* World = GetWorld();

	if(World)
	{
		UGameplayStatics::OpenLevel(World,TEXT("MainLevel"));
	}
}

void UMainMenu::OnQuitClick()
{
	UWorld* World = GetWorld();

	if(World)
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World,TEXT("quit"));
	}
}
