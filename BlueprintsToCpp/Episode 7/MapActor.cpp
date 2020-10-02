// Fill out your copyright notice in the Description page of Project Settings.


#include "MapActor.h"

#include "ConeActor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMapActor::AMapActor()
{
}

// Called when the game starts or when spawned
void AMapActor::BeginPlay()
{
	Super::BeginPlay();

	// ADD / APPEND
	//-------------------------------------------------------------------

	TMap<int32,FVector> Map;
	Map.Add(1,FVector::ZeroVector);
	Map.Add(2,FVector::OneVector);

	VecMap.Append(Map);

	// NUM ELEMENTS / GET
	//-------------------------------------------------------------------
	
	const int32 NumElements = VecMap.Num();

	// Get by Key
	const FVector& Element = VecMap[1];

	// KEYS / VALUES
	//-------------------------------------------------------------------
	
	TArray<int32> MapKeys;
	int32 NumKeys =	VecMap.GetKeys(MapKeys);

	TArray<FVector> MapValues;
	VecMap.GenerateValueArray(MapValues);
	
	
	// FIND / CONTAINS
	//-------------------------------------------------------------------

	// Contains
	const int32 Key = 1;

	if(VecMap.Contains(Key))
	{
		//....
	}
	
	// Find  
	
	const FVector* VecPtr = VecMap.Find(Key);
	
	if(VecPtr != nullptr)
	{
		int32 IntVal = VecPtr->X;
		
		const FVector& VecRef = *VecPtr;
		IntVal = VecRef.X;
	}

	
	// REMOVE / CLEAR
	//-------------------------------------------------------------------

	VecMap.Remove(Key);
	VecMap.Empty();

	
	// ITERATION
	//-------------------------------------------------------------------
	
	// standard for loop only possible with array
	
	TArray<int32> KeysFromMap;
	const int32 Num = VecMap.GetKeys(KeysFromMap);
	
	for(int32 i=0; i<Num; i++)
	{
		const int32 MapKey = KeysFromMap[i];
		const FVector& Vec = VecMap[MapKey];
		float Val = Vec.X;
	}
	

	// range-based for each loop 1
	for(const TPair<int32,FVector>& Kvp : VecMap)
	{
		const int32 MapKey = Kvp.Key;
		const FVector& Vec = Kvp.Value;
	}

	// range-based for each loop 1
	for(const auto& Kvp : VecMap)
	{
		const int32 MapKey = Kvp.Key;
		const FVector& Vec = Kvp.Value;
	}

	// for with iterator 1

	for(auto It = VecMap.CreateIterator(); It; ++It)
	{
		int32 MapKey = It.Key();
		FVector& Vec = It.Value();
		
	}

	for(auto It = VecMap.CreateConstIterator(); It; ++It)
	{
		const int32 MapKey = It.Key();
		const FVector& Vec = It.Value();
	}


	// TIP OF THE DAY
	//---------------------------------------------------------

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AConeActor::StaticClass(),Actors);

	TMap<int32,AConeActor*> ConeActorMap;
	
	const int32 NumActors = Actors.Num(); 

	for(int i=0; i<NumActors;i++)
	{
		AConeActor* ConeActor = Cast<AConeActor>(Actors[i]);

		if(ConeActor)
		{
			ConeActorMap.Add(i,ConeActor);
		}
	}
	 
	//AConeActor** ConeActorPtr = ConeActorMap.Find(Key);
	//AConeActor* ConeActor = *ConeActorPtr;
	
	AConeActor* ConeActor = *ConeActorMap.Find(Key);;

	if(ConeActor)
	{
		ConeActor->TestFunc(2);
	}
	 
	
	
	
}
