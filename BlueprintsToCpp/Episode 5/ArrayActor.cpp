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



	// ARRAY ITERATION
	//-------------------------------------------------------------------
	
	// for loop 1
	const int32 Num = VecArray.Num();

	for(int32 i=0; i<Num; i++)
	{	
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

	// ARRAY FIND / CONTAINS
	//-------------------------------------------------------------------
	
	// Find Variant 2
	
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

	// Contains

	if(VecArray.Contains(FVector::ZeroVector))
	{
		
	}


	// ARRAY REMOVE / CLEAR
	//-------------------------------------------------------------------

	VecArray.Remove(FVector::ZeroVector);

	VecArray.RemoveAt(2);

	VecArray.Empty();
	
}
