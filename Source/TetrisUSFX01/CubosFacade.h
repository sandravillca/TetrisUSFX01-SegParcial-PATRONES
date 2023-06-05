// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CuboGeneralFacade.h"
#include "CubosFacade.generated.h"

UCLASS()
class TETRISUSFX01_API ACubosFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubosFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The Crew list
	TArray<ACuboGeneralFacade*> CubosFacade;
	//The Tasks to execute
	UPROPERTY()
		TArray<FString> Acciones;

private:
	//Execute the tasks for a specific Crew
	void RealizarAcciones(TArray<ACuboGeneralFacade*> myCubosFacade, TArray<FString> myAcciones);

public:

	//Execute the Reveille tasks
	void Saltar();
	//Execute the PlanOfTheDay tasks
	void Detenerse();
	//Execute the Taps tasks
	void Desaparecer();

};
