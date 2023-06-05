// Fill out your copyright notice in the Description page of Project Settings.


#include "Escenario_1.h"

void AEscenario_1::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	NombreEscenario = "Escenario 1";
	Estructura = "Solida";
	Posicion = "Principal";
	//Add the herbs
	Material.Add("Hierro");

}

void AEscenario_1::Elaborar()
{
	//Log the brewing type
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Elaborando el escenario"));

}
