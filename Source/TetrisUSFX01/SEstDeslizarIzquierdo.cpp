// Fill out your copyright notice in the Description page of Project Settings.


#include "SEstDeslizarIzquierdo.h"

// Sets default values
ASEstDeslizarIzquierdo::ASEstDeslizarIzquierdo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASEstDeslizarIzquierdo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASEstDeslizarIzquierdo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

std::pair<bool, bool> ASEstDeslizarIzquierdo::PosicionarPieza(APiece* piece, bool flagMov, bool flagInicFun)
{
    if (piece) {

        auto Location = FVector(0, 0, 0);

        if (flagInicFun == true) {
            Location = FVector(0.0, -200, 300);
            piece->SetActorLocation(Location);
            flagInicFun = false;
        }

        FVector MoverLocalizacionY(0.0, 5, 0);
        FVector MoverLocalizacionZ(0.0, 0, -1);
        auto locActor = piece->GetActorLocation();
        float auxY = locActor.Y;
        float auxZ = locActor.Z;

        if (auxY < 5.0f && flagMov == false) {
            auto nuevaLocY = piece->GetActorLocation() + MoverLocalizacionY;
            piece->SetActorLocation(nuevaLocY);
        }
        if (auxZ > 175.0f && flagMov == false) {
            auto nuevaLocZ = piece->GetActorLocation() + MoverLocalizacionZ;
            piece->SetActorLocation(nuevaLocZ);
        }
        if (auxY >= 5.0f && auxZ <= 175.0f) {
            flagMov = true;
        }

    }
    return std::make_pair(flagMov, flagInicFun);

}

