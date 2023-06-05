// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OSuscriptor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UOSuscriptor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TETRISUSFX01_API IOSuscriptor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//The pure virtual functions of the Subscriber
	virtual void Actualizar(class AOPublicador* Publicador) = 0;    //El Suscriptor tiene acceso al Publicador mediante sus funcio
};
