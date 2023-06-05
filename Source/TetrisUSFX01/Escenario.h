// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Escenario.generated.h"

UCLASS()
class TETRISUSFX01_API AEscenario : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscenario();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	//The name of this Potion
	FString NombreEscenario;
	//The Gooeyness of this Potion
	FString Estructura;
	//The Blood of this Potion
	FString Posicion;
	//The herbs contained in this Potion
	TArray<FString> Material;


public:
	//Boild this potion
	void Crear();
	//Bubble this potion
	void Disenar();
	//Brew this potion
	virtual void Elaborar();
	//Bottle this potion
	void Finalizar();
	//Return the Potion Name
	FString GetNombreEscenario();

};
