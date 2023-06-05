// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSuscriptor.h"
#include "OCambios.h"
#include "OInformador.h"
#include "OBloqueObecede.generated.h"

UCLASS()
class TETRISUSFX01_API AOBloqueObecede : public AActor, public IOSuscriptor, public IOCambios
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOBloqueObecede();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//The Clock Tower of this Subscriber
	UPROPERTY()
		AOInformador* Informador;

	//Called when this Subscriber is destroyed, it will unsubscribe this from theClock Tower
	virtual void Destroyed() override;


public:
	//Called when the Plublisher changed its state, it will execute this Subscriber routine
	virtual void Actualizar(class AOPublicador* Publicador) override;

	//Execute this Subscriber routine
	virtual void Cambios();

	//Set the Clock Tower of this Subscriber
	void DefinirInformador(AOInformador* myInformador);

};
