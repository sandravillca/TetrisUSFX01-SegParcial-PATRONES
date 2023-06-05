// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboRapidoFacade.h"

ACuboRapidoFacade::ACuboRapidoFacade()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ACuboRapidoFacade::BeginPlay()
{
    Super::BeginPlay();
}

void ACuboRapidoFacade::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}


void ACuboRapidoFacade::Tarea()
{
    //Print Duty string
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Analizando la Tarea Actual"), *NombreCubo()));
}

FString ACuboRapidoFacade::NombreCubo()
{
    return "Cubo Rapido";
}
