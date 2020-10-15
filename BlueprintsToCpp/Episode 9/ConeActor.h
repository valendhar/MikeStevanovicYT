// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



#include "TestEnums.h"
#include "GameFramework/Actor.h"
#include "ConeActor.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AConeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConeActor();

public:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category="ConeActor")
	uint8 bIsUp:1;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category="ConeActor")
	uint8 bIsInitialized:1;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Components")
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* ConeMesh;

		
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category="ConeActor")
	float MinHeight;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category="ConeActor")
	float MaxHeight;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ConeActor")
	float Max;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category="ConeActor")
	float CurrentZ;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="ConeActor", meta=(DisplayName="Cone Speed", Tooltip="The speed of the cone",ClampMin="20",ClampMax="100"))
	float Speed;


	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	TEnumAsByte<EBarrierTypeStd> BarrierTypeStd = EBT_Impassable;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
	EBarrierType BarrierType = EBarrierType::Impassable;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = "EUnitKeyword"))
	uint8 UnitKeywords = static_cast<uint8>(EUnitKeyword::Activated);

	UFUNCTION(BlueprintCallable)
	void DisplayKeyword();	

	UFUNCTION(BlueprintCallable)
    void DisplayBarrierType();
	
	UFUNCTION(BlueprintCallable,Category="Cone Functions")
	void TestFunc(const int32 InSpeed);

	UFUNCTION(BlueprintCallable,Category="Cone Functions")
	bool TestInputOutput(UPARAM(ref) FVector& Location);
	
	UFUNCTION(BlueprintCallable,Category="Cone Functions",meta=(HideSelfPin="true"))
	int32 TestPureFunc() const;

	UFUNCTION(BlueprintImplementableEvent,Category="Cone Functions")
	bool TestImplementableFunc(int32 Val);

	UFUNCTION(BlueprintNativeEvent,Category="Cone Functions")
	void Explode();
	void Explode_Implementation();
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
