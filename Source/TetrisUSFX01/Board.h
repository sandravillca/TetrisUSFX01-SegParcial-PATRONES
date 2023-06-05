// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Piece.h"

#include "SEstrategiasInterfaz.h"
#include "SEstrategiaBasica.h"
#include "SEstDeslizarIzquierdo.h"
#include "SEstDeslizarDerecho.h"

#include "Board.generated.h"

UCLASS()
class TETRISUSFX01_API ABoard : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	APiece* CurrentPiece;

	//PATRÓN STRATEGY ----------------------
	bool flagPermitirMovimiento;
	bool flagInicioFuncion;
	int estrategias;
	void CambiarEstrategia();
	
	std::pair<bool, bool>flags;
	ISEstrategiasInterfaz* EstrategiaActual;
	void cambiarEstrategia(AActor* estrategiaPosicion);
	void SetearPosicionInicial();

	ASEstrategiaBasica* EstrategiaBasica;
	ASEstDeslizarIzquierdo* EstDeslizarIzquierda;
	ASEstDeslizarDerecho* EstDeslizarDerecha;
	//-----------------------------------------------

	void Rotate(); 
	void MoveLeft(); 
	void MoveRight();
	void MoveDown(); 
	void NewPiece();
	void CheckLine();
	void MoveDownToEnd();

private:
	enum PieceStatus { PS_NOT_INITED, PS_MOVING, PS_GOT_BOTTOM };
	PieceStatus Status = PS_NOT_INITED;

	const float CoolDown = 0.5f;
	float CoolLeft = 0.5f;
	bool bGameOver = false;

	bool CheckGameOver();

public:
	//PATRON SINGLETON ---------------------------------------------------
	UPROPERTY()
		ABoard* limite;
	//--------------------------------------------------------------------


	//PATRON BUILDER -----------------------------------------------------
	void Builder();

	//The Builder Actor
	UPROPERTY(VisibleAnywhere, Category = "Main")
		class ABlockExplosivo* BlockExplosivo;
	UPROPERTY(VisibleAnywhere, Category = "Main")
		class ABlockExplosivo* BlockExplosivo1;


	UPROPERTY(VisibleAnywhere, Category = "Main")
		class ABlockHielo* BlockHielo;
	UPROPERTY(VisibleAnywhere, Category = "Main")
		class ABlockHielo* BlockHielo1;

	UPROPERTY(VisibleAnywhere, Category = "Main")
		class ABlockMadera* BlockMadera;
	UPROPERTY(VisibleAnywhere, Category = "Main")
		class ABlockMadera* BlockMadera1;

	//The Engineer Actor
	//UPROPERTY(VisibleAnywhere, Category = "Main")
	class ADirector* Director;	

	int contador;
	//------------------------------------------------------------------------------


};

