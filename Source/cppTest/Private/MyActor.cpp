// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	totalDamage = 200;
	damageTimeInSeconds = 1.0f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Called after initializing properties (not when changing properties in editor)
void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
	damagePerSecond = totalDamage / damageTimeInSeconds;
}

void AMyActor::CalculateValues() 
{
	damagePerSecond = totalDamage / damageTimeInSeconds;
}

//Called after changing property
//if editor to save extra executable size
#if WITH_EDITOR
void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) 
{
	CalculateValues();

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

