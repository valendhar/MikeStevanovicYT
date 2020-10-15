// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TestEnums.generated.h"

UENUM(BlueprintType, Category="GameRules")
enum EBarrierTypeStd 
{
    EBT_BarrierNone     UMETA(DisplayName = "No Barrier"),
    EBT_ModerateBarrier	UMETA(DisplayName = "Moderate Barrier"),
    EBT_Difficult       UMETA(DisplayName = "Difficult Barrier"), 
    EBT_VeryDifficult  	UMETA(DisplayName = "Very Difficult Barrier"),
    EBT_Impassable    	UMETA(DisplayName = "Impassable Barrier")
};


UENUM(BlueprintType, Category="GameRules")
enum class EBarrierType : uint8
{
    BarrierNone     UMETA(DisplayName = "No Barrier"),
    ModerateBarrier	UMETA(DisplayName = "Moderate Barrier"),
    Difficult       UMETA(DisplayName = "Difficult Barrier"), 
    VeryDifficult  	UMETA(DisplayName = "Very Difficult Barrier"),
    Impassable    	UMETA(DisplayName = "Impassable Barrier")
};

UENUM(BlueprintType, Meta = (Bitflags))
enum class EUnitKeyword : uint8
{
    None         = 0  UMETA(Hidden),
    Activated    = 1  UMETA(DisplayName = "Activated"),
    Stopped      = 2  UMETA(DisplayName = "Stopped"),
    Prone        = 4  UMETA(DisplayName = "Prone"),
    Running      = 8  UMETA(DisplayName = "Running")
};