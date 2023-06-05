// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockHielo.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"

void ABlockHielo::BeginPlay()
{
	BloqueGeneral = GetWorld()->SpawnActor<ABloqueGeneral>(ABloqueGeneral::StaticClass());
	//Attach it to the Builder (this)
	BloqueGeneral->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	//NewMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/Mesh/Material_0.Material_0'")));
	NewMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/Material_7.Material_7'"));

	BlockMesh->SetMaterial(1, NewMaterial);

}

void ABlockHielo::ContruirTamanoBloque()
{
	BloqueGeneral->SetTamanoBloque("El tamano del bloque de Hielo");

}

void ABlockHielo::ConstruirColorBloque()
{
	BloqueGeneral->SetColorBloque("El color del bloque de Hielo");
}

void ABlockHielo::ConstruirMaterial()
{
	BloqueGeneral->SetMaterial("El material del bloque de Hielo");

	FString MaterialName = NewMaterial->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El material es %s"), *MaterialName));
}

ABloqueGeneral* ABlockHielo::GetBloqueGeneral()
{
	return BloqueGeneral;
}
