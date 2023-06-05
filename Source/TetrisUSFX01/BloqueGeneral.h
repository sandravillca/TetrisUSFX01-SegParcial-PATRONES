// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstructuraBloque.h"
#include "ConstructorBloque.h"
#include "BloqueGeneral.generated.h"

UCLASS()
class TETRISUSFX01_API ABloqueGeneral : public AActor, public IEstructuraBloque
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloqueGeneral();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//The The Block's size
	FString TamanoBloque;
	//The Block's color
	FString ColorBloque;
	//The Block's Material
	FString Material;

	//Set the size of the Block
	void SetTamanoBloque(FString myTamanoBloque);
	//Set the color of the Block
	void SetColorBloque(FString myColorBloque);
	//Set the material of the Block
	void SetMaterial(FString myMaterial);


	//Logs all the Lodging floors
	void BloqueCaracteristicas();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BlockMesh;


};
