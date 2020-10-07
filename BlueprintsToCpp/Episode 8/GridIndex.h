// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GridIndex.generated.h"

USTRUCT(BlueprintType)
struct FGridIndex
{
    GENERATED_BODY()

    FORCEINLINE FGridIndex();

    explicit FGridIndex(int32 InValue);
    
    explicit FORCEINLINE FGridIndex(int32 InX, int32 InY);

    UPROPERTY(BlueprintReadWrite)
    int32 X = 0;

    UPROPERTY(BlueprintReadWrite)
    int32 Y = 0;

    bool operator==(const FGridIndex& V) const;
    bool operator!=(const FGridIndex& V) const;

    bool Equals(const FGridIndex& V, float Tolerance=KINDA_SMALL_NUMBER) const;

    bool AllComponentsEqual(float Tolerance=KINDA_SMALL_NUMBER) const;
};

FORCEINLINE FGridIndex::FGridIndex()
{   
}

FORCEINLINE FGridIndex::FGridIndex(const int32 InValue) : X(InValue), Y(InValue)
{   
}

FORCEINLINE FGridIndex::FGridIndex(const int32 InX, const int32 InY) : X(InX), Y(InY)
{   
}

FORCEINLINE bool FGridIndex::operator==(const FGridIndex& V) const
{
    return X == V.X && Y == V.Y;
}

FORCEINLINE bool FGridIndex::operator!=(const FGridIndex& V) const
{
    return X != V.X || Y != V.Y;
}

FORCEINLINE bool FGridIndex::Equals(const FGridIndex& V, float Tolerance) const
{
    return FMath::Abs(X-V.X) <= Tolerance && FMath::Abs(Y-V.Y) <= Tolerance;
}

FORCEINLINE bool FGridIndex::AllComponentsEqual(float Tolerance) const
{
    return FMath::Abs(X - Y) <= Tolerance;
}

FORCEINLINE uint32 GetTypeHash(const FGridIndex& b)
{
    return FCrc::MemCrc_DEPRECATED(&b, sizeof(FGridIndex));
}