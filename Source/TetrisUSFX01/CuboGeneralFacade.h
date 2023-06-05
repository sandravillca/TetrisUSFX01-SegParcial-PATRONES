// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.h"
#include "CuboGeneralFacade.generated.h"

UCLASS()
class TETRISUSFX01_API ACuboGeneralFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACuboGeneralFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



private:
	//Execute the passed Task
	void Accion(const FString& Accion);   //EJECUTA LA ACCIÓN QUE SE LE PASA

public:

	void Camuflaje();
	//Execute the HeaveOutTriceUp task
	void Paralisis();
	//Execute the LibertyCall task
	void Propulsion();

	//Execute the passed Tasks
	void Accion(const TArray<FString>& Acciones);     //Ejecuta LAS ACCIONES que se le pasa


	//Execute the member duty. It's pure virtual, so it doesn't need an implementation in this class
	virtual void Tarea() PURE_VIRTUAL(ACuboGeneralFacade::Tarea, ;);

	//Return the member Title. It's pure virtual, so it doesn't need an implementation in this class
	virtual FString NombreCubo()PURE_VIRTUAL(ACuboGeneralFacade::NombreCubo, return "";);

	

public:

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BlockMesh;


	//UPROPERTY(EditAnywhere, Category = "Materiales")
	//	class UMaterialInterface* Material1;

	//UPROPERTY(EditAnywhere, Category = "Materiales")
	//	class UMaterialInterface* Material2;

};
