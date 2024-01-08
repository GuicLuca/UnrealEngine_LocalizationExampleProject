// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/VColoredActor.h"


// Sets default values
AVColoredActor::AVColoredActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AVColoredActor::BeginPlay()
{
	Super::BeginPlay();
	if (!IsValid(TriggerZone)) return;

	TriggerZone->OnActorEnterZone.AddDynamic(this, &AVColoredActor::ChangeColor);
}

void AVColoredActor::ChangeColor_Implementation(AActor* EnteringActor)
{
	// this function will be overridden in blueprint
}

void AVColoredActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (!IsValid(TriggerZone)) return;

	TriggerZone->OnActorEnterZone.RemoveDynamic(this, &AVColoredActor::ChangeColor);
	
	Super::EndPlay(EndPlayReason);
}



