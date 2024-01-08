// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/VTriggerZone.h"

AVTriggerZone::AVTriggerZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &AVTriggerZone::OnOverlapBegin);
}

void AVTriggerZone::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (OnActorEnterZone.IsBound())
	{
		OnActorEnterZone.Clear();
	}
	TriggerZone->OnComponentBeginOverlap.RemoveDynamic(this, &AVTriggerZone::OnOverlapBegin);
	Super::EndPlay(EndPlayReason);
}

// Called when the game starts or when spawned
void AVTriggerZone::BeginPlay()
{
	Super::BeginPlay();
}

void AVTriggerZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OnActorEnterZone.IsBound()) return;
	
	OnActorEnterZone.Broadcast(OtherActor);
}

