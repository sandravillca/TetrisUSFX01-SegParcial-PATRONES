// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscenarioShop.h"
#include "EscenarioShop_1.generated.h"

/**
 * 
 */
UCLASS()
class TETRISUSFX01_API AEscenarioShop_1 : public AEscenarioShop
{
	GENERATED_BODY()
	
public:
	//Concoct the selected potion
	virtual AEscenario* Confeccionar(FString EscenarioSKU) override;

};
