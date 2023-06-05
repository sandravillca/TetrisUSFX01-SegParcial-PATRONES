// Fill out your copyright notice in the Description page of Project Settings.


#include "AAdaptadorMovimientoAleatorio_CA.h"

UAAdaptadorMovimientoAleatorio_CA::UAAdaptadorMovimientoAleatorio_CA() :
	Super()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	SetLimitesMovimiento(0.0f, 5.0f, 5.0f);
}


void UAAdaptadorMovimientoAleatorio_CA::SetLimitesMovimiento(float _XMovimiento, float _YMovimiento, float _ZMovimiento)
{
	AnchoMovimiento = _ZMovimiento;
	AltoMovimiento = _YMovimiento;
	ProfundidadMovimiento = _ZMovimiento;
}
