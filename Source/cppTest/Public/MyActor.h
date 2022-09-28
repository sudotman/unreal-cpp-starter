// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class CPPTEST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		int32 totalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float damageTimeInSeconds;

	//transient - hence non persistent and will be calculated on runtime
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		float damagePerSecond;


	//decleration of all functions we will be using:

	void PostInitProperties();

	//BP exposing
	UFUNCTION(BlueprintCallable, Category="Damage Functions")
	void CalculateValues();


	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

	// Sets default values for this actor's properties
	AMyActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




};
