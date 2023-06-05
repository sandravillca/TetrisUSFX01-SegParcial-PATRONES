// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueGeneral.h"

// Sets default values
ABloqueGeneral::ABloqueGeneral()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>("Block Mesh");
	RootComponent = BlockMesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockFinder(TEXT("StaticMesh'/Game/Mesh/block.block'"));

	if (BlockFinder.Succeeded())
	{
		BlockMesh->SetStaticMesh(BlockFinder.Object);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("La malla no fue encontrada"));
	}
}

// Called when the game starts or when spawned
void ABloqueGeneral::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloqueGeneral::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABloqueGeneral::SetTamanoBloque(FString myTamanoBloque)
{
	TamanoBloque = myTamanoBloque;
}

void ABloqueGeneral::SetColorBloque(FString myColorBloque)
{
	ColorBloque = myColorBloque;
}

void ABloqueGeneral::SetMaterial(FString myMaterial)
{
	Material = myMaterial;
}

void ABloqueGeneral::BloqueCaracteristicas()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s"), *TamanoBloque));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("%s"), *ColorBloque));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("%s"), *Material));
}

