// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "ConeActor.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATestActor::SetConeActorLocation()
{
	if(ConeActor == nullptr)
	{
		return;
	}

	// Locals used several times
	const FVector ActorLocation 	= GetActorLocation();
	const FVector ConeActorLocation = ConeActor->GetActorLocation();
	const float WidthHeight 		= Width * Height;

	// Vector 1
	const float Val 				= WidthHeight + ConeActor->Speed;
	const float AbsVal 				= FMath::Abs(Val);
	const FVector Vec1 				= ActorLocation * AbsVal;

	// Vector 2
	const int32 RoundVal 			= FMath::RoundToInt(WidthHeight);
	const int32 FloorVal			= FMath::FloorToInt(ConeActorLocation.X);
	const int32 RoundFloorVal		= RoundVal + ((FloorVal + 1) % FloorVal);
	const FVector Vec2 				= ActorLocation * RoundFloorVal;

	// Vector 3
	FVector Vec3;
	Vec3.X 							= WidthHeight * ConeActor->Speed;
	Vec3.Y 							= WidthHeight / ConeActor->Speed;
	Vec3.Z 							= FMath::Clamp(ActorLocation.Z,10.0f,20.0f);

	// Vector 4
	FRotator Delta 					= ConeActor->GetActorRotation() - GetActorRotation();  //UKismetMathLibrary::NormalizedDeltaRotator()
	Delta.Normalize();  

	const FVector RightVec 			= UKismetMathLibrary::GetRightVector(Delta);
	const FVector ForwardVec 		= UKismetMathLibrary::GetForwardVector(Delta);
	const FVector Vec4 				= UKismetMathLibrary::VLerp(RightVec,ForwardVec,0.1f);	// Lerp (Vector)
	
	// Set ActorLocation
	const FVector Location = Vec1 + Vec2 + Vec3 + Vec4;

	ConeActor->SetActorLocation(Location);
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

