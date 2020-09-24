// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrayActor.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AArrayActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrayActor();

protected:

	UPROPERTY()
	TArray<FVector> VecArray;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
