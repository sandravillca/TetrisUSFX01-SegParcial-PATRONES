// Fill out your copyright notice in the Description page of Project Settings.


#include "OBloqueObecede.h"
#include "OInformador.h"
#include "BloqueGeneral.h"
#include "OPublicador.h"


// Sets default values
AOBloqueObecede::AOBloqueObecede()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOBloqueObecede::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOBloqueObecede::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOBloqueObecede::Destroyed()
{
	Super::Destroyed();

	//Log Error if its Clock Tower is NULL
	if (!Informador) {
		UE_LOG(LogTemp, Error, TEXT("Destroyed():ClockTower is NULL, make sure it's initialized.")); return;
	}
	//Unsubscribe from the Clock Tower if it's destroyed
	Informador->Desuscribirse(this);
}

void AOBloqueObecede::Actualizar(AOPublicador* Publicador)
{
	//Execute the routine
	Cambios();

}

void AOBloqueObecede::Cambios()
{
	//Log Error if its Clock Tower is NULL
	if (!Informador) {
		UE_LOG(LogTemp, Error, TEXT("Morph():ClockTower is NULL, make sure it's initialized.")); return;
	}
	//Get the current time of the Clock Tower
	FString Estado = Informador->GetEstado();

	if (!Estado.Compare("Estado1"))
	{
		//Execute the Morning routine
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Observer: Estamos en el estado %s"), *Estado));
	}
	else if (!Estado.Compare("Estado2"))
	{
		//Execute the Midday routine
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Observer: Estamos en el estado %s"), *Estado));
		ABloqueGeneral* BloqueGeneral = GetWorld()->SpawnActor<ABloqueGeneral>(FVector(0.0f, -90.0f, 30.0f), FRotator(0.0f,50.0f,0.0f));   //FRotator::ZeroRotator

	}
	else if (!Estado.Compare("Estado3"))
	{
		//Execute the Evening routine
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Observer: Estamos en el estado %s"), *Estado));
	}

}

void AOBloqueObecede::DefinirInformador(AOInformador* myInformador)
{
	//Log Error if the passed Clock Tower is NULL
	if (!myInformador) {
		UE_LOG(LogTemp, Error, TEXT("SetClockTower(): myClockTower is NULL, make sure it's initialized.")); return;
	}
	//Set the Clock Tower and Subscribe to that
	Informador = myInformador;
	Informador->Suscribirse(this);
}


