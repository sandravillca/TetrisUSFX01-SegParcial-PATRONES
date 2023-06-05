// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Piece.h"
#include <utility>
#include "SEstrategiasInterfaz.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USEstrategiasInterfaz : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TETRISUSFX01_API ISEstrategiasInterfaz
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual std::pair<bool, bool> PosicionarPieza(APiece* piece, bool flagMov, bool flagInicFun) = 0;
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.


};
