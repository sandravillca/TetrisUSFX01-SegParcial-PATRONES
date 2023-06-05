// Fill out your copyright notice in the Description page of Project Settings.


#include "OInformador.h"

AOInformador::AOInformador()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AOInformador::BeginPlay()
{
	Super::BeginPlay();

}

void AOInformador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOInformador::EstadoCambiado()
{
	//When the time has changed, this Clock Tower (that is a Publisher) notifies to all the subscribers that the time has changed
	NotificarSuscriptores();
}

void AOInformador::DefinirEstado(FString myEstado)
{
	//Set the time using the passed parameter and warn that it's changed
	Estado = myEstado;
	EstadoCambiado();
}
