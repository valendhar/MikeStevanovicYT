// Fill out your copyright notice in the Description page of Project Settings.


#include "SetActor.h"

#include "Kismet/BlueprintSetLibrary.h"

// Sets default values
ASetActor::ASetActor()
{
}

// Called when the game starts or when spawned
void ASetActor::BeginPlay()
{
	Super::BeginPlay();

	// ADD Elements / Arrays
	//-------------------------------------------------------------------

	TSet<FVector> Set;
	Set.Add(FVector::ZeroVector);
	Set.Add(FVector::OneVector);

	// Next will not be added	
	Set.Add(FVector::ZeroVector);

	VecSet.Append(Set);

	TArray<FVector> VecArray;
	VecArray.Add(FVector(2,2,2));

	VecSet.Append(VecArray);
	
	// NUM ELEMENTS / GET
	//-------------------------------------------------------------------
	
	const int32 NumElements = VecSet.Num();

	// NOT POSSIBLE
	//const FVector& Element = VecSet[0];

	TArray<FVector> SetArray = VecSet.Array();
	const FVector& Element = SetArray[0];
	
	// FIND / CONTAINS
	//-------------------------------------------------------------------

	// Contains

	if(VecSet.Contains(FVector::ZeroVector))
	{
		//....
	}
	
	// Find  
	
	const FVector* VecPtr = VecSet.Find(FVector::ZeroVector);
	
	if(VecPtr)
	{
		int32 IntVal = VecPtr->X;
		
		const FVector& VecRef = *VecPtr;
		IntVal = VecRef.X;
	}

	// REMOVE / CLEAR
	//-------------------------------------------------------------------

	VecSet.Remove(FVector::ZeroVector);

	
	VecSet.Empty();

	
	// ITERATION
	//-------------------------------------------------------------------
	
	// standard for loop only possible with array
	
	const TArray<FVector> ArrayFromSet = VecSet.Array();
	const int32 Num = ArrayFromSet.Num();

	for(int32 i=0; i<Num; i++)
	{
		const FVector& Vec = ArrayFromSet[i];
		float Val = Vec.X;
	}
	

	// range-based for each loop 1
	for(FVector& Vec : VecSet)
	{
		float Val = Vec.X;
	}

	// range-based for each loop 1
	for(auto& Vec : VecSet)
	{
		float Val = Vec.X;
	}

	// for with iterator 1

	for(auto It = VecSet.CreateIterator(); It; ++It)
	{
		FVector& Vec = *It;
		float Val = Vec.X;
	}

	for(auto It = VecSet.CreateConstIterator(); It; ++It)
	{
		const FVector& Vec = *It;
		float Val = Vec.X;
	}

	
	
	
}
