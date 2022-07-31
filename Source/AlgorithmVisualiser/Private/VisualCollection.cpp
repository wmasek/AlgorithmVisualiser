// � 2022 Will Masek

// This file's header
#include "VisualCollection.h"

// Includes
#include "VisualElement.h"

// Constants
const float MaxSceneWidth = 1500.0f;

// Sets default values
AVisualCollection::AVisualCollection() : CollectionSize(30)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a scene component to use as our root comp
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// Create as many static mesh components as we need
	for (uint8 i = 0; i < CollectionSize; ++i)
	{
		CollectionArray.Add(CreateDefaultSubobject<UVisualElement>(*(FString::Printf(TEXT("Element_%u"), i))));
		CollectionArray[i]->SetupAttachment(RootComponent);
	}
}

// Called when the game starts or when spawned
void AVisualCollection::BeginPlay()
{
	Super::BeginPlay();
	
	float sizePerElement = (MaxSceneWidth / CollectionSize);
	ElementSpacing = sizePerElement;
	sizePerElement *= 0.009f;

	// Get the mesh to use for the elements
	UStaticMesh* meshToUse = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")));

	for (uint8 i = 0; i < CollectionSize; ++i)
	{
		CollectionArray[i]->InitialiseElement(meshToUse, sizePerElement);
	}
}

// Called every frame
void AVisualCollection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Scale each one
	if (ShouldUpdate)
	{
		// Starting position for an offset is half the scene width minus half the spacing width
		float yOffset = (MaxSceneWidth * 0.5f) - (ElementSpacing * 0.5f);

		// Loop over each element in the collection placing them in order of their index
		for (uint8 i = 0; i < CollectionSize; ++i)
		{
			CollectionArray[i]->SetWorldLocation(FVector(0.0f, yOffset, 0.0f));

			yOffset -= ElementSpacing;

			if (i == CollectionSize - 1)
			{
				ShouldUpdate = false;
			}
		}
	}
	
}

