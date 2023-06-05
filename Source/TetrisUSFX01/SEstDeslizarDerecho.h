// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SEstrategiasInterfaz.h"
#include "SEstDeslizarDerecho.generated.h"

UCLASS()
class TETRISUSFX01_API ASEstDeslizarDerecho : public AActor, public ISEstrategiasInterfaz
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASEstDeslizarDerecho();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual std::pair<bool, bool> PosicionarPieza(APiece* piece, bool flagMov, bool flagInicFun) override;

};
