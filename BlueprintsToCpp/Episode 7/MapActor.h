// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapActor.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AMapActor : public AActor
{
    GENERATED_BODY()
	
    public:	
    // Sets default values for this actor's properties
    AMapActor();

    protected:

    UPROPERTY()
    TMap<int32,FVector> VecMap;
	
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;


};
