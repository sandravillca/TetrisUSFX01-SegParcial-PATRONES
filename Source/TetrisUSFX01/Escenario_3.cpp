// Fill out your copyright notice in the Description page of Project Settings.


#include "Escenario_3.h"

void AEscenario_3::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	NombreEscenario = "Escenario 3";
	Estructura = "Estructura espacial";
	Posicion = "Tercera";
	//Add the herbs
	Material.Add("Cobre");
	Material.Add("Bronce");
	Material.Add("Oro");
	Material.Add("Platino");

}

void AEscenario_3::Elaborar()
{
	//Log the brewing type
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Elaborando escenario 3"));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Soy el escenario 3"));
}
