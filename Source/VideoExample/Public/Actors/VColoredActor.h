// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VTriggerZone.h"
#include "GameFramework/Actor.h"
#include "VColoredActor.generated.h"



UCLASS()
class VIDEOEXAMPLE_API AVColoredActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVColoredActor();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditInstanceOnly, Category = "Trigger Zone")
	TObjectPtr<AVTriggerZone> TriggerZone;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintNativeEvent)
	void ChangeColor(AActor* EnteringActor);
};
