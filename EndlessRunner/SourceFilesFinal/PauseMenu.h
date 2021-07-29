// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API UPauseMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ContinueBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* RestartBtn;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnContinueClick();

	UFUNCTION()
    void OnRestartClick();
};
