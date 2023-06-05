// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EstructuraBloque.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEstructuraBloque : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TETRISUSFX01_API IEstructuraBloque
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetTamanoBloque(FString TamanoBloque) = 0;
	virtual void SetColorBloque(FString ColorBloque) = 0;
	virtual void SetMaterial(FString Material) = 0;
};
