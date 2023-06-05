// Fill out your copyright notice in the Description page of Project Settings.


#include "Escenario.h"

// Sets default values
AEscenario::AEscenario()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscenario::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscenario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AEscenario::Crear()
{
	//Log the Boil procedure
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Creando %s de la clase Escenario"), *GetNombreEscenario()));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Creando materiales"));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, ("Definiendo posiciones"));
}

void AEscenario::Disenar()
{
	//Log the Bubble procedure
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Construyendo por 3 dias"));

}

void AEscenario::Elaborar()
{
	//Log the Brew procedure
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Elaborando escenario"));
}

void AEscenario::Finalizar()
{
	//Log the Bottle procedure
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Finalizando Escenario"));
}

FString AEscenario::GetNombreEscenario()
{

	return NombreEscenario;
}

