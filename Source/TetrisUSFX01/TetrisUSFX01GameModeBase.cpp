// Copyright Epic Games, Inc. All Rights Reserved.


#include "TetrisUSFX01GameModeBase.h"
#include "Board.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

#include "EscenarioShop_1.h"
#include "EscenarioShop_2.h"

#include "CuboGeneralFacade.h"
#include "CubosFacade.h"

#include "OBloqueObecede.h"
#include "OInformador.h"

#include "EngineUtils.h"

ATetrisUSFX01GameModeBase::ATetrisUSFX01GameModeBase() {
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    DefaultPawnClass = ABoard::StaticClass();
    siguientePosicionZ = 0;
}

void ATetrisUSFX01GameModeBase::BeginPlay()
{
    // Call the parent class version of this function
    Super::BeginPlay();
    // Displays a red message on the screen for 10 seconds
    //GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Block"));
    // Spawn an instance of the AMyFirstActor class at the
    //default location.
    /*FTransform SpawnLocation;
    SpawnedActor = GetWorld()->SpawnActor<ABlock>(ABlock::StaticClass(), SpawnLocation);
    SpawnedActor->SetActorRelativeLocation(FVector(0.0, 0.0, 0.0));

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Piece"));
    SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
    SpawnedPiece->SetActorRelativeLocation(FVector(0.0, 100.0, 0.0));
    SpawnedPiece->SpawnBlocks();*/

    for (TActorIterator<ACameraActor> it(GetWorld()); it; ++it)
    {
        UE_LOG(LogTemp, Warning, TEXT("Find camera: %s"), *(it->GetFName().ToString()));
        if (it->GetFName() == TEXT("BoardCamera"))
        {
            APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
            PC->SetViewTargetWithBlend(*it, 0.5);
            break;
        }
    }

    //PATRON SINGLETON ------------------------------------------------------------------------

    //for (int i = 0; i <= 2; i++)
    //{
    //	ABoard* Aparecio = GetWorld()-> SpawnActor<ABoard>(ABoard::StaticClass());
    //	if (Aparecio)
    //	{
    //		//If the Spawn succeeds, set the Spawned inventory to the local one and log the success string
    //		Board = Aparecio;
    //		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s El Board esta apareciendo"),*Board->GetName()));
    //	}
    //}
    //-------------------------------------------------------------------------------------------


    //PATRÓN FACADE -----------------------------------------------------------------------------------
    //Create the Ship Facade Actor
    ACubosFacade* CubosFacade = GetWorld()->SpawnActor<ACubosFacade>(ACubosFacade::StaticClass());
     
    //Execute the needed tasks
    //CubosFacade->Saltar();
    CubosFacade->Desaparecer();
    //CubosFacade->Detenerse();

    //------------------------------------------------------------------------------------------------

    //PATRON FACTORY----------------------------------------------------------------------------------

    //Haciendo Spawn de los generadores de escenarios
    AEscenarioShop* EscenarioShop_1 = GetWorld() -> SpawnActor<AEscenarioShop_1>(AEscenarioShop_1::StaticClass());
    AEscenarioShop* EscenarioShop_2 = GetWorld()->SpawnActor<AEscenarioShop_2>(AEscenarioShop_2::StaticClass());


    //Definiendo los escenarios
    AEscenario* Escenario = EscenarioShop_1->OrdenarEscenario("Escenario_3");
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("El escenario es %s"),*Escenario->GetNombreEscenario()));

    //-------------------------------------------------------------------------------------------------

    //PATRON OBSERVER ----------------------------------------------------------------------------------
    //Spawn the Clock Tower
    AOInformador* Informador = GetWorld()->SpawnActor<AOInformador>(AOInformador::StaticClass());

    //Spawn the first Subscriber and set its Clock Tower
    AOBloqueObecede* BloqueObedece = GetWorld()->SpawnActor<AOBloqueObecede>(AOBloqueObecede::StaticClass());
    BloqueObedece->DefinirInformador(Informador);

    //Change the time of the Clock Tower, so the Subscribers can execute their own routine
    Informador->DefinirEstado("Estado2");
    //Informador->DefinirEstado("Estado1");
    //Informador->DefinirEstado("Estado3");

    //--------------------------------------------------------------------------------------------------
}

// Called every frame
void ATetrisUSFX01GameModeBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   /* FTransform SpawnLocation;

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawning un Piece"));
    SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
    SpawnedPiece->SetActorRelativeLocation(FVector(0.0, 100.0, 0.0));
    SpawnedPiece->SpawnBlocks();*/ 

}


void ATetrisUSFX01GameModeBase::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
   {
      // Displays a red message on the screen for 10 seconds
      GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Block destruido"));
      SpawnedActor->Destroy();
   }
}
