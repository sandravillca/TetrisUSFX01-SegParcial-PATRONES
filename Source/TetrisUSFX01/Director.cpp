// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"

// Sets default values
ADirector::ADirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirector::ConstruirBloque()
{
	//Creates the buildings
	ConstructorBloque->ContruirTamanoBloque();
	ConstructorBloque->ConstruirColorBloque();
	ConstructorBloque->ConstruirMaterial();
}

void ADirector::SetConstructorBloque(AActor* Constructor)
{
	ConstructorBloque = Cast<IConstructorBloque>(Constructor);

}

ABloqueGeneral* ADirector::GetBloqueGeneral()
{
	if (ConstructorBloque)
	{
		//Returns the Lodging of the Builder
		return ConstructorBloque->GetBloqueGeneral();
	}

	return nullptr;
}

