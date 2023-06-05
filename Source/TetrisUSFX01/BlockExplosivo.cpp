// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockExplosivo.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"

void ABlockExplosivo::BeginPlay()
{
	// Spawn the Lodging Actors
	BloqueGeneral = GetWorld()->SpawnActor<ABloqueGeneral>(ABloqueGeneral::StaticClass());

	//Attach it to the Builder (this)
	BloqueGeneral->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	//Material1 = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/Mesh/Material_1.Material_1'")));// Cast to material
	Material1 = LoadObject<UMaterialInterface>(nullptr, TEXT("Material'/Game/Mesh/Material_6.Material_6'"));

	BlockMesh->SetMaterial(1, Material1);

}

void ABlockExplosivo::ContruirTamanoBloque()
{
	//Set the size of the Block
	BloqueGeneral->SetTamanoBloque("El tamano del bloque explosivo");

}

void ABlockExplosivo::ConstruirColorBloque()
{
	BloqueGeneral->SetColorBloque("El color del bloque explosivo");
}

void ABlockExplosivo::ConstruirMaterial()
{
	//BlockMesh->SetMaterial(0, Material1);


	BloqueGeneral->SetMaterial("El Material del bloque explosivo");

	FString NombreMaterial = Material1->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("El material es %s"), *NombreMaterial));

}

ABloqueGeneral* ABlockExplosivo::GetBloqueGeneral()
{
	return BloqueGeneral;
}
