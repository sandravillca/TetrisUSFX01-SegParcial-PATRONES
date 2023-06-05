// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OPublicador.h"
#include "OInformador.generated.h"

/**
 * 
 */
UCLASS()
class TETRISUSFX01_API AOInformador : public AOPublicador
{
	GENERATED_BODY()
	
public:

	AOInformador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The current time of this Clock Tower
	FString Estado;

public:
	//Called when the time of this Clock Tower has changed
	void EstadoCambiado();

	//Set the time of this Clock Tower
	void DefinirEstado(FString myEstado);
	//Return the time of this Clock Tower

	FORCEINLINE FString GetEstado() { return Estado; };


};
