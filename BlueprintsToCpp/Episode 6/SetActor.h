// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SetActor.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API ASetActor : public AActor
{
    GENERATED_BODY()
	
    public:	
    // Sets default values for this actor's properties
    ASetActor();

    protected:

    UPROPERTY()
    TSet<FVector> VecSet;
	
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;


};
