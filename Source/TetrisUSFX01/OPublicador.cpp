// Fill out your copyright notice in the Description page of Project Settings.


#include "OPublicador.h"

// Sets default values
AOPublicador::AOPublicador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOPublicador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOPublicador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOPublicador::Suscribirse(AActor* Suscriptor)
{
	//Add the passed Subscriber
	Suscriptores.Add(Suscriptor);
}

void AOPublicador::Desuscribirse(AActor* SuscriptorAquitar)
{
	//Remove the passed Subscriber
	Suscriptores.Remove(SuscriptorAquitar);

}

void AOPublicador::NotificarSuscriptores()
{
	//Loop for each Subscriber
	for (AActor* Actor : Suscriptores)
	{
		//Cast each of them to a concrete Subscriber
		IOSuscriptor* Sub = Cast<IOSuscriptor>(Actor);
		if (Sub)
		{
			//Notify each of them that something has changed, so they can execute their own routine
			Sub->Actualizar(this);
		}
	}
}

