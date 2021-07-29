// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class ENDLESSRUNNER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	class UStaticMeshComponent* StaticMesh;
		
	// Sets default values for this actor's properties
	AObstacle();

	UFUNCTION()
	void OnObstacleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	

};
