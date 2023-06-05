// Fill out your copyright notice in the Description page of Project Settings.


#include "CubosFacade.h"
#include "CuboGeneralFacade.h"
#include "CuboAleatorioFacade.h"
#include "CuboRapidoFacade.h"

// Sets default values
ACubosFacade::ACubosFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACubosFacade::BeginPlay()
{
	Super::BeginPlay();

	//Initialize the lists
	CubosFacade = TArray<ACuboGeneralFacade*>();  //INICIALIZA ARRAY VACÍO
	Acciones = TArray<FString>();                 //INICIALIZA ARRAY VACÍO

	//Spawn the members
	ACuboAleatorioFacade* CuboAleatorio = GetWorld()->SpawnActor<ACuboAleatorioFacade>(ACuboAleatorioFacade::StaticClass());
	ACuboRapidoFacade* CuboRapido = GetWorld()->SpawnActor<ACuboRapidoFacade>(ACuboRapidoFacade::StaticClass());


	//Add the member to the crew
	CubosFacade.Add(CuboAleatorio);
	CubosFacade.Add(CuboRapido);
}

// Called every frame
void ACubosFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubosFacade::Saltar()
{
	//Empty the task list
	Acciones.Empty();

	//Add the tasks to execute
	Acciones.Add("Tomarpropulsion");
	Acciones.Add("Saltar");
	//Execute the tasks
	RealizarAcciones(CubosFacade, Acciones);

}

void ACubosFacade::Detenerse()
{
	//Empty the task list
	Acciones.Empty();

	//Add the tasks to execute
	Acciones.Add("Detenerse");
	Acciones.Add("Tarea");
	//Execute the tasks
	RealizarAcciones(CubosFacade, Acciones);
}

void ACubosFacade::Desaparecer()
{
	//Empty the task list
	Acciones.Empty();
	//Add the tasks to execute
	Acciones.Add("Cambiarmaterial");
	//Execute the tasks
	RealizarAcciones(CubosFacade, Acciones);
}

void ACubosFacade::RealizarAcciones(TArray<ACuboGeneralFacade*> myCubosFacade, TArray<FString> myAcciones)
{
	//Execute the passed tasks for each crew member
	for (ACuboGeneralFacade* Cubo : myCubosFacade)
	{
		//Execute the task
		Cubo->Accion(myAcciones);                //Método de CuboGeneralFacade
	}
}
