// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockMadera.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"

void ABlockMadera::BeginPlay()
{
	BloqueGeneral = GetWorld()->SpawnActor<ABloqueGeneral>(ABloqueGeneral::StaticClass());
	//Attach it to the Builder (this)
	BloqueGeneral->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	//NewMaterial2 = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'")));
	NewMaterial2 = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/Material_4.Material_4'"));

	BlockMesh->SetMaterial(1, NewMaterial2);

}

void ABlockMadera::ContruirTamanoBloque()
{
	BloqueGeneral->SetTamanoBloque("El tamano del bloque de Madera");
}

void ABlockMadera::ConstruirColorBloque()
{
	BloqueGeneral->SetColorBloque("El color del bloque de Madera");
}

void ABlockMadera::ConstruirMaterial()
{
	BloqueGeneral->SetMaterial("El material del bloque de Madera");

	FString MaterialName = NewMaterial2->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El material es %s"), *MaterialName));

}

ABloqueGeneral* ABlockMadera::GetBloqueGeneral()
{
	return BloqueGeneral;
}
