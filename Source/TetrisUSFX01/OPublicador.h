// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSuscriptor.h"
#include "OPublicador.generated.h"

UCLASS()
class TETRISUSFX01_API AOPublicador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOPublicador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The Subscribers of this Publisher
	UPROPERTY()
		TArray<AActor*> Suscriptores = TArray<AActor*>();


public:
	//Add the pased Subscriber to the list
	virtual void Suscribirse(AActor* Suscriptor);
	//Remove the passed Subscriber from the list
	virtual void Desuscribirse(AActor* SuscriptorAquitar);
	//Notify all the Subscribers that something has changed
	virtual void NotificarSuscriptores();
};
