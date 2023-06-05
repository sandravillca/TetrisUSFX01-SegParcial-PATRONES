// Fill out your copyright notice in the Description page of Project Settings.


#include "CuboGeneralFacade.h"

// Sets default values
ACuboGeneralFacade::ACuboGeneralFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>("Block Mesh");
	RootComponent = BlockMesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockFinder(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));    //StaticMesh'/Game/Mesh/block.block'    //StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'

	if (BlockFinder.Succeeded())
	{

		BlockMesh->SetStaticMesh(BlockFinder.Object);
		BlockMesh->SetRelativeLocation(FVector(0.0f, -150.0f, 40.0f));
		BlockMesh->SetRelativeRotation(FRotator(0.0f, 50.0f, 10.0f));
		BlockMesh->SetWorldScale3D(FVector(0.3f, 0.3f, 0.3f));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("La malla no fue encontrada"));
	}

	//Material1 = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/Mesh/Material_3.Material_3'")));//Haciendo cast al material
	//Material2 = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("Material'/Game/Mesh/Material_6.Material_6'")));

}

// Called when the game starts or when spawned
void ACuboGeneralFacade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACuboGeneralFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACuboGeneralFacade::Paralisis()
{
	// Print lights out string
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Facade: El cubo se detiene"), *NombreCubo()));

}

void ACuboGeneralFacade::Propulsion()
{
	// Print lights out string
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Facade: El cubo se prepara para saltar"), *NombreCubo()));
	
	//Mesh->SetMaterial(0, Material2);
}


void ACuboGeneralFacade::Camuflaje()
{
	// Print lights out string
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Facade: El cubo se camufla"), *NombreCubo()));

	//Mesh->SetMaterial(0, Material1);

}

void ACuboGeneralFacade::Accion(const FString& Accion)
{
	//Checks which task must be executed
	if (Accion.Equals("Camuflarse"))
	{
		//Camuflaje();
	}
	else if (Accion.Equals("Cambiarmaterial"))
	{
		Camuflaje();
	}
	else if (Accion.Equals("Saltar"))
	{
		Propulsion();
	}
	else if (Accion.Equals("Tarea"))
	{
		Tarea();
	}
	else if (Accion.Equals("Tomarpropulsion"))
	{
		Propulsion();
	}
	else if (Accion.Equals("Detenerse"))
	{
		Paralisis();
	}
	else
	{
		//In case the passed Task doesn't exist
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Tarea sin definir"));
	}
}

void ACuboGeneralFacade::Accion(const TArray<FString>& Acciones)
{
	//Loop the Tasks array and call the Task() function for each of them
	for (const FString& myAccion : Acciones)
	{
		Accion(myAccion);
	}

}
