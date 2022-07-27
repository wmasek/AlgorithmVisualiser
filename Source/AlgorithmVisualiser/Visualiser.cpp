// Fill out your copyright notice in the Description page of Project Settings.


#include "Visualiser.h"

// Sets default values
AVisualiser::AVisualiser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a scene component to use as our root comp
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));	
	
	// Create as many static mesh components as we need
	for (uint8 i = 0; i < NumOfCubes; ++i)
	{
		int32 CompIndex = CubeArray.Add(CreateDefaultSubobject<UStaticMeshComponent>(*(FString::Printf(TEXT("BoxComp_%u"), i))));	
	}
}

// Called when the game starts or when spawned
void AVisualiser::BeginPlay()
{
	Super::BeginPlay();

	// Find the mesh we want to use
	UStaticMesh* meshToUse = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")));

	if (IsValid(meshToUse))
	{
		// Create an offset to use with each cube
		float cubeYOffset = 0;

		for (uint8 i = 0; i < NumOfCubes; ++i)
		{
			// Check we have a valid component
			if (CubeArray[i])
			{
				// Set the mesh we want to use
				CubeArray[i]->SetStaticMesh(meshToUse);

				// Attach each cube to the root
				CubeArray[i]->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

				// Set the world location
				CubeArray[i]->SetWorldLocation(FVector(0.0f, cubeYOffset, 0.0f));

				// Set a random scale
				CubeArray[i]->SetWorldScale3D(FVector(1.0f, 1.0f, FMath::RandRange(1.0f, 3.0f)));

				// Increase offset for the next cube
				cubeYOffset -= 150.0f;
			}
		}
	}
}

// Called every frame
void AVisualiser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (static uint8 pass = 0; pass < NumOfCubes; ++pass)
	{
		for (static uint8 i = 0; i < NumOfCubes - 1; ++i)
		{
			float currentScale = CubeArray[i]->GetComponentScale().Z;
			float nextScale = CubeArray[i + 1]->GetComponentScale().Z;

			// Check if one is bigger than the other
			if (currentScale > nextScale)
			{
				auto temp = CubeArray[i]->GetComponentLocation();

				CubeArray[i]->SetWorldLocation(CubeArray[i + 1]->GetComponentLocation());

				CubeArray[i + 1]->SetWorldLocation(temp);

				CubeArray.Swap(i, i + 1);

				UpdateTimer = 0.0f;
			}
		}
	}	
}

