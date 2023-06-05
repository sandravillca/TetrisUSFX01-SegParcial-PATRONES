// Fill out your copyright notice in the Description page of Project Settings.


#include "SEstrategiaBasica.h"

// Sets default values
ASEstrategiaBasica::ASEstrategiaBasica()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASEstrategiaBasica::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASEstrategiaBasica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

std::pair<bool, bool> ASEstrategiaBasica::PosicionarPieza(APiece* piece, bool flagMov, bool flagInicFun)
{
    if (piece) {

        auto Location = FVector(0, 0, 0);

        if (flagInicFun == true) {
            Location = FVector(0.0, 5, 175);
            piece->SetActorLocation(Location);
            flagInicFun = false;
        }
        flagMov = true;

    }
    return std::make_pair(flagMov, flagInicFun);

}

