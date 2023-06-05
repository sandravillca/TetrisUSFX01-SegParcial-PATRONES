// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMovimientoAleatorio_CA.h"
#include "AMovimientoAleatorio.h"
#include "AAdaptadorMovimientoAleatorio_CA.generated.h"

/**
 * 
 */
UCLASS()
class TETRISUSFX01_API UAAdaptadorMovimientoAleatorio_CA : public UAMovimientoAleatorio_CA, public IAMovimientoAleatorio
{
	GENERATED_BODY()
	
public:
	UAAdaptadorMovimientoAleatorio_CA();

	void SetLimitesMovimiento(float _XMovimiento, float _YMovimiento, float _ZMovimiento);

};
