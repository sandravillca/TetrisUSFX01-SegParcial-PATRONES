// Fill out your copyright notice in the Description page of Project Settings.


#include "EscenarioShop_1.h"
#include "Escenario_1.h"
#include "Escenario_2.h"
#include "Escenario_3.h"




AEscenario* AEscenarioShop_1::Confeccionar(FString EscenarioSKU)
{
	//Select which potion to spawn depending on the passed string
	if (EscenarioSKU.Equals("Escenario_1")) {
		return GetWorld()->SpawnActor<AEscenario_1>(AEscenario_1::StaticClass());
	}
	else if (EscenarioSKU.Equals("Escenario_2")) {
		return GetWorld()->SpawnActor<AEscenario_2>(AEscenario_2::StaticClass());
	}
	else if (EscenarioSKU.Equals("Escenario_3")) {
		return GetWorld()->SpawnActor<AEscenario_3>(AEscenario_3::StaticClass());
	}
	else return nullptr; //Return null if the string isn't valid

}
