// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "VTriggerZone.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorEnterZone, AActor*, Actor);

UCLASS()
class VIDEOEXAMPLE_API AVTriggerZone : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AVTriggerZone();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Delegates
	UPROPERTY(BlueprintAssignable)
	FOnActorEnterZone OnActorEnterZone;


	// other
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Trigger Zone")
	TObjectPtr<UBoxComponent> TriggerZone;
};
