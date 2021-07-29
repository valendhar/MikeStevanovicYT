// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"

#include "Blueprint/UserWidget.h"

void AMainMenuGameMode::BeginPlay()
{
	if(IsValid(MainMenuWidgetClass))
	{
		UUserWidget* Widget = CreateWidget(GetWorld(),MainMenuWidgetClass);

		if(Widget)
		{
			Widget->AddToViewport();
		}
	}
}
