// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboAleatorioFacade.h"

ACuboAleatorioFacade::ACuboAleatorioFacade()
{
    PrimaryActorTick.bCanEverTick = true;

}

void ACuboAleatorioFacade::BeginPlay()
{
    Super::BeginPlay();

}

void ACuboAleatorioFacade::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ACuboAleatorioFacade::Tarea()
{
    //Print Duty string
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Analizando la Tarea actual"), *NombreCubo()));
}

FString ACuboAleatorioFacade::NombreCubo()
{
    return "Cubo aleatorio";
}
