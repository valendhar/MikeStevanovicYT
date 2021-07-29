// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinItem.generated.h"

UCLASS()
class ENDLESSRUNNER_API ACoinItem : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class UStaticMeshComponent* CoinMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class USphereComponent* SphereCollider;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class URotatingMovementComponent* RotatingMovement;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
	class USoundBase* OverlapSound;
	
	// Sets default values for this actor's properties
	ACoinItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
