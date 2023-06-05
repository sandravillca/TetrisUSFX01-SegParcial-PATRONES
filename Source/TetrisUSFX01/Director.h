// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstructorBloque.h"
#include "Director.generated.h"

UCLASS()
class TETRISUSFX01_API ADirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	IConstructorBloque* ConstructorBloque;

	//Creates the buildings
	void ConstruirBloque();
	//Set the Builder Actor
	void SetConstructorBloque(AActor* Constructor);
	//Get the Lodging of the Builder
	class ABloqueGeneral* GetBloqueGeneral();

};
