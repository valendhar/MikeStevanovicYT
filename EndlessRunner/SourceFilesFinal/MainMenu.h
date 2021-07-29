// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* StartBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* QuitBtn;

	virtual void NativeConstruct() override;

	UFUNCTION()
    void OnStartClick();

	UFUNCTION()
    void OnQuitClick();
};
