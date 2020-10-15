// Fill out your copyright notice in the Description page of Project Settings.


#include "ConeActor.h"

#include "Components/SplineComponent.h"

// Sets default values
AConeActor::AConeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	ConeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	Scene->SetupAttachment(GetRootComponent());
	ConeMesh->SetupAttachment(Scene);

	Speed = 50;
	Max = 200;

	bIsUp = true;
	bIsInitialized = false;

	
}

void AConeActor::DisplayKeyword()
{
	UnitKeywords |= static_cast<uint8>(EUnitKeyword::Running);

	UnitKeywords &= ~static_cast<uint8>(EUnitKeyword::Activated);

	if(UnitKeywords & static_cast<uint8>(EUnitKeyword::Activated))
	{
		UE_LOG(LogTemp,Warning,TEXT("Cone is Activated"));
	}
	
	if(UnitKeywords & static_cast<uint8>(EUnitKeyword::Running))
	{
		UE_LOG(LogTemp,Warning,TEXT("Cone is Running"));
	}	
}

void AConeActor::DisplayBarrierType()
{
	
	FString EnumName;
	UEnum::GetValueAsString(BarrierType,EnumName);
	UE_LOG(LogTemp,Warning,TEXT("BarrierType is %s"),*EnumName);

	UEnum::GetValueAsString(BarrierTypeStd,EnumName);
	UE_LOG(LogTemp,Warning,TEXT("BarrierTypeStd is %s"),*EnumName);

	FText DisplayText;
	UEnum::GetDisplayValueAsText(BarrierType,DisplayText);
	UE_LOG(LogTemp,Warning,TEXT("BarrierType DisplayText is %s"),*DisplayText.ToString());

	UEnum::GetDisplayValueAsText(BarrierTypeStd,DisplayText);
	UE_LOG(LogTemp,Warning,TEXT("BarrierTypeStd DisplayText is %s"),*DisplayText.ToString());	
}

void AConeActor::TestFunc(const int32 InSpeed)
{
	UE_LOG(LogTemp,Warning,TEXT("Test Func Called with value %d"),InSpeed);
}

bool AConeActor::TestInputOutput(FVector& Location)
{
	Location.Z = 3;
	return true;
}

int32 AConeActor::TestPureFunc() const
{
	return 25;
}

void AConeActor::Explode_Implementation()
{
	this->Destroy();
}

// Called when the game starts or when spawned
void AConeActor::BeginPlay()
{
	Super::BeginPlay();

	TestImplementableFunc(76);
	const FVector Location = GetActorLocation();

	CurrentZ   = Location.Z;
	MinHeight  = Location.Z;
	MaxHeight  = Location.Z + Max;
	bIsUp 	   = true;
	bIsInitialized = true;

}

// Called every frame
void AConeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float Val = DeltaTime * Speed;

	if(bIsUp)
	{
		CurrentZ = CurrentZ + Val;
	}
	else
	{
		CurrentZ = CurrentZ - Val;
	}

	FVector Location = GetActorLocation();
	Location.Z = CurrentZ;

	SetActorLocation(Location);

	if(CurrentZ > MaxHeight)
	{
		bIsUp = false;
		Explode();
	}
	else if(CurrentZ < MinHeight)
	{
		bIsUp = true;
	}
	
}

