// Fill out your copyright notice in the Description page of Project Settings.


#include "ArrayActor.h"

// Sets default values
AArrayActor::AArrayActor()
{
}

// Called when the game starts or when spawned
void AArrayActor::BeginPlay()
{
	Super::BeginPlay();

	// ARRAY ADD Elements / Arrays
	//-------------------------------------------------------------------

	TArray<FVector> Array;
	
	Array.Add(FVector::ZeroVector);

	Array.Insert(FVector::ZeroVector,1);

	VecArray.Append(Array);


	// ARRAY NUM ELEMENTS / GET
	//-------------------------------------------------------------------
	
	const int32 NumElements = VecArray.Num();

	const int32 ArrayLastIndex = VecArray.Num() - 1;

	FVector& Element = VecArray[0];
	
	
	// ARRAY FIND / CONTAINS
	//-------------------------------------------------------------------

	// Contains

	if(VecArray.Contains(FVector::ZeroVector))
	{
		//....
	}
	
	// Find Variant 1
	
	const int32 Idx = VecArray.Find(FVector::ZeroVector);

	if(Idx != INDEX_NONE)
	{
		//....
	}

	// Find Variant 2
	
	int32 Index;
	if(VecArray.Find(FVector::ZeroVector,Index))
	{
		//....
	}

	// ARRAY REMOVE / CLEAR
	//-------------------------------------------------------------------

	VecArray.Remove(FVector::ZeroVector);

	VecArray.RemoveAt(2);

	VecArray.Empty();

	


	// ARRAY ITERATION
	//-------------------------------------------------------------------
	
	// for loop 1
	const int32 Num = VecArray.Num();

	for(int32 i=0; i<Num; i++)
	{
		FVector& Vec = VecArray[i];
		float Val = Vec.X;
	}

	// for loop 2
	const int32 LastIndex = VecArray.Num() - 1;

	for(int32 i=0; i<= LastIndex; i++)
	{
		FVector& Vec = VecArray[i];
		float Val = Vec.X;
	}

	// range-based for each loop 1
	for(FVector& Vec : VecArray)
	{
		float Val = Vec.X;
	}

	// range-based for each loop 1
	for(auto& Vec : VecArray)
	{
		float Val = Vec.X;
	}

	// for with iterator 1

	for(auto It = VecArray.CreateIterator(); It; ++It)
	{
		FVector& Vec = *It;
		float Val = Vec.X;
	}

	for(auto It = VecArray.CreateConstIterator(); It; ++It)
	{
		const FVector& Vec = *It;
		float Val = Vec.X;
	}
}
