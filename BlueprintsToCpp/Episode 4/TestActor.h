// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Width;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Height;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class AConeActor* ConeActor;

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void SetupConeActor();

	UFUNCTION(BlueprintCallable)
	void SetConeActorLocation();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
