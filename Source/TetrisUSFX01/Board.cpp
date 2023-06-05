// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "EngineUtils.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "BlockExplosivo.h"
#include "BlockHielo.h"
#include "BlockMadera.h"
#include "Director.h"


// Sets default values

ABoard::ABoard()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //PATRON SINGLETON -------------------------------------------------------------------------------------
    
    //Search for existing Instances of this class
    TArray<AActor*> cantidad;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoard::StaticClass(), cantidad);

    if (cantidad.Num() > 1)
    {
        //If exist at least one of them, set the instance with the first found one
        limite = Cast<ABoard>(cantidad[0]);
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Ya existe el board"), *limite->GetName()));
        //Then Destroy this Actor
        Destroy();
    }
    //-----------------------------------------------------------------------------------------------------
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
    for (TActorIterator<APiece> it(GetWorld()); it; ++it)      //Iterador de actores de tipo APiece
    {
        if (it->GetFName() == TEXT("DissmissPieces"))          //Para empezar el tablero debe estar en blanco
        {
            it->Dismiss();
            it->Destroy();
        }
    }

    /*BlockExplosivo = GetWorld()->SpawnActor<ABlockExplosivo>(FVector(50, 100, 50), FRotator(0, 0, 0));
    BlockHielo = GetWorld()->SpawnActor<ABlockHielo>(FVector(50, 100, 70), FRotator(0, 0, 0));
    BlockMadera = GetWorld()->SpawnActor<ABlockMadera>(FVector(50, 100, 90), FRotator(0, 0, 0));

    Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());*/

    contador = 0;  //CONTADOR BUILDER

    EstrategiaBasica = GetWorld()->SpawnActor<ASEstrategiaBasica>(ASEstrategiaBasica::StaticClass());
    EstDeslizarIzquierda = GetWorld()->SpawnActor<ASEstDeslizarIzquierdo>(ASEstDeslizarIzquierdo::StaticClass());
    EstDeslizarDerecha = GetWorld()->SpawnActor<ASEstDeslizarDerecho>(ASEstDeslizarDerecho::StaticClass());

    cambiarEstrategia(EstrategiaBasica);     //Invocando al método cambiarEstrategia()

}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    SetearPosicionInicial();     //Invocando al método, STRATEGY


    if (bGameOver)
    {
        return;
    }

    switch (Status)
    {
    case PS_NOT_INITED:
        NewPiece();
        CoolLeft = CoolDown;
        Status = PS_MOVING;
        break;
    case PS_MOVING:
        CoolLeft -= DeltaTime;
        if (CoolLeft <= 0.0f)
        {
            MoveDown();
        }
        break;
    case PS_GOT_BOTTOM:
        CoolLeft -= DeltaTime;      
        if (CoolLeft <= 0.0f)
        {
            if (CurrentPiece)
            {
                CurrentPiece->Dismiss();
                CurrentPiece->Destroy();
            }
            CurrentPiece = nullptr;
            NewPiece();
            CoolLeft = CoolDown;
            Status = PS_MOVING;
        }
        break;
    default:
        break;
    }
}

// Called to bind functionality to input
void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Rotate", IE_Pressed, this, &ABoard::Rotate);           //con &ABoard::Rotate hace referencia a la función, llama a la funcion
    PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ABoard::MoveLeft);
    PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ABoard::MoveRight);
    PlayerInputComponent->BindAction("MoveDownToEnd", IE_Pressed, this, &ABoard::MoveDownToEnd);
    PlayerInputComponent->BindAction("NewPiece", IE_Pressed, this, &ABoard::NewPiece);
    //PlayerInputComponent->BindAction("CheckLine", IE_Pressed, this, &ABoard::CheckLine);

    PlayerInputComponent->BindAction("Builder", IE_Pressed, this, &ABoard::Builder);  //TECLA B

    PlayerInputComponent->BindAction("cambiarEstrategia", IE_Pressed, this, &ABoard::CambiarEstrategia); //TECLA C

}

//PATRON STRATEGY ----------------------------------------------------------------------------
void ABoard::cambiarEstrategia(AActor* estrategiaPosicion)
{
    EstrategiaActual = Cast<ISEstrategiasInterfaz>(estrategiaPosicion);

    //Log Error if the cast failed if (!BattleStrategy)
    if (!estrategiaPosicion)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("No se pudo hacer casting!")));

    }
}

void ABoard::CambiarEstrategia()       //Sobrecarga de Métodos
{
    estrategias++;
    if (estrategias > 2)
        estrategias = 0;
    switch (estrategias)
    {
    case 0:
        cambiarEstrategia(EstrategiaBasica);
        GEngine->AddOnScreenDebugMessage(1, 15.f, FColor::Green, FString::Printf(TEXT("Se cambio a Estrategia Basica...."), estrategias));
        break;
    case 1:
        cambiarEstrategia(EstDeslizarDerecha);
        GEngine->AddOnScreenDebugMessage(1, 15.f, FColor::Green, FString::Printf(TEXT("Se cambio a Estrategia DeslizarIzquierda...."), estrategias));
        break;
    case 2:
        cambiarEstrategia(EstDeslizarIzquierda);
        GEngine->AddOnScreenDebugMessage(1, 15.f, FColor::Green, FString::Printf(TEXT("Se cambio a Estrategia DeslizarDerecha..."), estrategias));
        break;
    }
}

void ABoard::SetearPosicionInicial()
{
    if (!EstrategiaActual)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("No hay Estrategia!")));
        return;
    }
    flags = EstrategiaActual->PosicionarPieza(CurrentPiece, flagPermitirMovimiento, flagInicioFuncion);
    flagPermitirMovimiento = flags.first;
    flagInicioFuncion = flags.second;
}

//void ABoard::Rotate()
//{
//    if (flagPermitirMovimiento == true) {
//        if (CurrentPiece && Status != PS_GOT_BOTTOM)
//        {
//            CurrentPiece->TestRotate();
//        }
//    }
//}
//
//
//void ABoard::MoveLeft()
//{
//    if (flagPermitirMovimiento == true) {
//        if (CurrentPiece)
//        {
//            CurrentPiece->MoveLeft();
//            if (Status == PS_GOT_BOTTOM)
//            {
//                MoveDownToEnd();
//            }
//        }
//    }
//}
//
//void ABoard::MoveRight()
//{
//    if (flagPermitirMovimiento == true) {
//        if (CurrentPiece)
//        {
//            CurrentPiece->MoveRight();
//            if (Status == PS_GOT_BOTTOM)
//            {
//                MoveDownToEnd();
//            }
//        }
//    }
//}
//
//void ABoard::MoveDown()
//{
//    if (flagPermitirMovimiento == true) {
//        if (CurrentPiece)
//        {
//            if (!CurrentPiece->MoveDown())
//            {
//                Status = PS_GOT_BOTTOM;
//            }
//            CoolLeft = CoolDown;
//        }
//    }
//}
//
//void ABoard::NewPiece()
//{
//    CheckLine();
//    flagPermitirMovimiento = false;
//
//    if (CurrentPiece)
//    {
//        CurrentPiece->Dismiss();
//        CurrentPiece->Destroy();
//    }
//
//    FVector Location(0.0, 5.0, 195.0);
//    FRotator Rotation(0.0, 0.0, 0.0);
//    CurrentPiece = GetWorld()->SpawnActor<APiece>(Location, Rotation);
//    
//    flagInicioFuncion = true;     //VALOR DE INICIO
//
//
//    bGameOver = CheckGameOver();
//    if (bGameOver)
//    {
//        UE_LOG(LogTemp, Warning, TEXT("Game Over!!!!!!!!"));
//    }
//}
//
//void ABoard::CheckLine()                   
//{
//    auto MoveDownFromLine = [this](int z) {
//        FVector Location(0.0f, 0.0f, 5.0 * z + 100.0);
//        FRotator Rotation(0.0f, 0.0f, 0.0f);
//        TArray<struct FOverlapResult> OutOverlaps;
//        FCollisionShape CollisionShape;
//        FVector Extent(4.5f, 49.5f, 95.0 + 4.5 - 5.0 * z);
//        CollisionShape.SetBox(Extent);
//        DrawDebugBox(GetWorld(), Location, Extent, FColor::Purple, false, 1, 0, 1);
//        FCollisionQueryParams Params;
//        FCollisionResponseParams ResponseParam;
//        if (GetWorld()->OverlapMultiByChannel(OutOverlaps,
//            Location, Rotation.Quaternion(), ECollisionChannel::ECC_WorldDynamic,
//            CollisionShape, Params, ResponseParam))
//        {
//            for (auto&& Result : OutOverlaps)
//            {
//                FVector NewLocation = Result.GetActor()->GetActorLocation();
//                NewLocation.Z -= 10.0f;
//                Result.GetActor()->SetActorLocation(NewLocation);
//            }
//        }
//    };
//
//    int z = 0;
//    while (z < 20)                              //INVESTIGAR
//    {
//        FVector Location(0.0f, 0.0f, 10.0f * z + 5.0f);
//        FRotator Rotation(0.0f, 0.0f, 0.0f);
//        TArray<struct FOverlapResult> OutOverlaps;
//        FCollisionShape CollisionShape;
//        CollisionShape.SetBox(FVector(4.0f, 49.0f, 4.0f));
//        //DrawDebugBox(GetWorld(), Location, FVector(4.5f, 49.5f, 4.5f), FColor::Purple, false, 1, 0, 1);
//        FCollisionQueryParams Params;
//        FCollisionResponseParams ResponseParam;
//        bool b = GetWorld()->OverlapMultiByChannel(OutOverlaps,
//            Location, Rotation.Quaternion(), ECollisionChannel::ECC_WorldDynamic,
//            CollisionShape, Params, ResponseParam);
//        if (!b || OutOverlaps.Num() < 10)
//        {
//            ++z;
//            continue;
//        }
//        else // this line is full, remove the line
//        {
//            UE_LOG(LogTemp, Warning, TEXT("Find FULL LINE at z=%d"), z);
//            for (auto&& Result : OutOverlaps)
//            {
//                Result.GetActor()->Destroy();
//            }
//            MoveDownFromLine(z);
//
//            /*if (LineRemoveSoundCue)
//            {
//                UGameplayStatics::PlaySoundAtLocation(GetWorld(), LineRemoveSoundCue, GetActorLocation(), GetActorRotation());
//            }*/
//        }
//    }
//}
//
//void ABoard::MoveDownToEnd()
//{
//    if (flagPermitirMovimiento == true) {
//        if (!CurrentPiece)
//        {
//            return;
//        }
//
//        while (CurrentPiece->MoveDown())
//        {
//        }
//
//        /*if (MoveToEndSoundCue)
//        {
//            UGameplayStatics::PlaySoundAtLocation(GetWorld(), MoveToEndSoundCue, GetActorLocation(), GetActorRotation());
//        }*/
//
//        switch (Status)
//        {
//        case PS_MOVING:
//            Status = PS_GOT_BOTTOM;
//            CoolLeft = CoolDown;
//            break;
//        case PS_GOT_BOTTOM:
//            break;
//        default:
//            UE_LOG(LogTemp, Warning, TEXT("Wrong status for MoveDownToEnd"));
//            break;
//        }
//    }
//}
//
//bool ABoard::CheckGameOver()
//{
//    if (!CurrentPiece)
//    {
//        UE_LOG(LogTemp, Warning, TEXT("NoPieces"));
//        return true;
//    }
//
//    return CurrentPiece->CheckWillCollision([](FVector OldVector) { return OldVector; });
//}

//-----------------------------------------------------------------------------------------------------


void ABoard::Rotate()
{
    if (CurrentPiece && Status != PS_GOT_BOTTOM)
    {
        CurrentPiece->TestRotate();       //Pregunta si la pieza actual puede rotar
    }
}

void ABoard::MoveLeft()
{
    if (CurrentPiece)
    {
        CurrentPiece->MoveLeft();
        if (Status == PS_GOT_BOTTOM)
        {
            MoveDownToEnd();
        }
    }
}

void ABoard::MoveRight()
{
    if (CurrentPiece)
    {
        CurrentPiece->MoveRight();
        if (Status == PS_GOT_BOTTOM)
        {
            MoveDownToEnd();
        }
    }
}

void ABoard::MoveDown()
{
    if (CurrentPiece)
    {
        if (!CurrentPiece->MoveDown())
        {
            Status = PS_GOT_BOTTOM;
        }
        CoolLeft = CoolDown;
    }
}

void ABoard::NewPiece()
{
    CheckLine();
    if (CurrentPiece)
    {
        CurrentPiece->Dismiss();
        CurrentPiece->Destroy();
    }

    FVector Location(0.0, 5.0, 195.0);
    FRotator Rotation(0.0, 0.0, 0.0);
    CurrentPiece = GetWorld()->SpawnActor<APiece>(Location, Rotation);
    bGameOver = CheckGameOver();
    if (bGameOver)
    {
        UE_LOG(LogTemp, Warning, TEXT("Game Over!!!!!!!!"));
        /*if (GameOverSoundCue)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameOverSoundCue, GetActorLocation(), GetActorRotation());
        }*/
    }
}

void ABoard::CheckLine()                   
{
    auto MoveDownFromLine = [this](int z) {
        FVector Location(0.0f, 0.0f, 5.0 * z + 100.0);
        FRotator Rotation(0.0f, 0.0f, 0.0f);
        TArray<struct FOverlapResult> OutOverlaps;
        FCollisionShape CollisionShape;
        FVector Extent(4.5f, 49.5f, 95.0 + 4.5 - 5.0 * z);
        CollisionShape.SetBox(Extent);
        DrawDebugBox(GetWorld(), Location, Extent, FColor::Purple, false, 1, 0, 1);
        FCollisionQueryParams Params;
        FCollisionResponseParams ResponseParam;
        if (GetWorld()->OverlapMultiByChannel(OutOverlaps,
            Location, Rotation.Quaternion(), ECollisionChannel::ECC_WorldDynamic,
            CollisionShape, Params, ResponseParam))
        {
            for (auto&& Result : OutOverlaps)
            {
                FVector NewLocation = Result.GetActor()->GetActorLocation();
                NewLocation.Z -= 10.0f;
                Result.GetActor()->SetActorLocation(NewLocation);
            }
        }
    };

    int z = 0;
    while (z < 20)                              //INVESTIGAR
    {
        FVector Location(0.0f, 0.0f, 10.0f * z + 5.0f);
        FRotator Rotation(0.0f, 0.0f, 0.0f);
        TArray<struct FOverlapResult> OutOverlaps;
        FCollisionShape CollisionShape;
        CollisionShape.SetBox(FVector(4.0f, 49.0f, 4.0f));
        //DrawDebugBox(GetWorld(), Location, FVector(4.5f, 49.5f, 4.5f), FColor::Purple, false, 1, 0, 1);
        FCollisionQueryParams Params;
        FCollisionResponseParams ResponseParam;
        bool b = GetWorld()->OverlapMultiByChannel(OutOverlaps,
            Location, Rotation.Quaternion(), ECollisionChannel::ECC_WorldDynamic,
            CollisionShape, Params, ResponseParam);
        if (!b || OutOverlaps.Num() < 10)
        {
            ++z;
            continue;
        }
        else // this line is full, remove the line
        {
            UE_LOG(LogTemp, Warning, TEXT("Find FULL LINE at z=%d"), z);
            for (auto&& Result : OutOverlaps)
            {
                Result.GetActor()->Destroy();
            }
            MoveDownFromLine(z);

            /*if (LineRemoveSoundCue)
            {
                UGameplayStatics::PlaySoundAtLocation(GetWorld(), LineRemoveSoundCue, GetActorLocation(), GetActorRotation());
            }*/
        }
    }
}

void ABoard::MoveDownToEnd()
{
    if (!CurrentPiece)
    {
        return;
    }

    while (CurrentPiece->MoveDown())
    {
    }

    /*if (MoveToEndSoundCue)
    {
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), MoveToEndSoundCue, GetActorLocation(), GetActorRotation());
    }*/

    switch (Status)
    {
    case PS_MOVING:
        Status = PS_GOT_BOTTOM;
        CoolLeft = CoolDown;
        break;
    case PS_GOT_BOTTOM:
        break;
    default:
        UE_LOG(LogTemp, Warning, TEXT("Wrong status for MoveDownToEnd"));
        break;
    }
}

bool ABoard::CheckGameOver()
{
    if (!CurrentPiece)
    {
        UE_LOG(LogTemp, Warning, TEXT("NoPieces"));
        return true;
    }

    return CurrentPiece->CheckWillCollision([](FVector OldVector) { return OldVector; });
}



//PATRON DE DISENO BUILDER --------------------------------------------------------------------
void ABoard::Builder()
{
    contador = contador + 1;

    if (contador == 1)
    {
        BlockExplosivo = GetWorld()->SpawnActor<ABlockExplosivo>(FVector(0, -45, 60), FRotator(0, 0, 0));
        BlockExplosivo1 = GetWorld()->SpawnActor<ABlockExplosivo>(FVector(0, 45, 60), FRotator(0, 0, 0));
        Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());

        Director->SetConstructorBloque(BlockExplosivo);
        Director->SetConstructorBloque(BlockExplosivo1);
        Director->ConstruirBloque();

        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i El contador"), contador));
        ABloqueGeneral* BloqueGeneral = Director->GetBloqueGeneral();
        BloqueGeneral->BloqueCaracteristicas();

    }
    else if (contador == 2) {
        BlockHielo = GetWorld()->SpawnActor<ABlockHielo>(FVector(0, -45, 70), FRotator(0, 0, 0));
        BlockHielo1 = GetWorld()->SpawnActor<ABlockHielo>(FVector(0, 45, 70), FRotator(0, 0, 0));
        Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());

        Director->SetConstructorBloque(BlockHielo);
        Director->SetConstructorBloque(BlockHielo1);
        Director->ConstruirBloque();


        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i El contador"), contador));
        ABloqueGeneral* BloqueGeneral = Director->GetBloqueGeneral();
        BloqueGeneral->BloqueCaracteristicas();
        //contador = 0;

    }
    else if (contador == 3) {
        BlockMadera = GetWorld()->SpawnActor<ABlockMadera>(FVector(0, 0, 120), FRotator(0, 0, 0));
        BlockMadera1 = GetWorld()->SpawnActor<ABlockMadera>(FVector(0, 0, 130), FRotator(0, 0, 0));

        Director = GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());

        Director->SetConstructorBloque(BlockMadera);
        Director->SetConstructorBloque(BlockMadera1);
        Director->ConstruirBloque();


        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i El contador"), contador));
        ABloqueGeneral* BloqueGeneral = Director->GetBloqueGeneral();
        BloqueGeneral->BloqueCaracteristicas();
        contador = 0;

    }
}
//------------------------------------------------------------------------------------------------------

