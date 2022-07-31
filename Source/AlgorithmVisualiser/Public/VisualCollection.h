// © 2022 Will Masek

#pragma once

// Includes
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VisualCollection.generated.h"

// Forward declarations
class UVisualElement;

UCLASS()
class ALGORITHMVISUALISER_API AVisualCollection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVisualCollection();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Properties
	UPROPERTY(EditAnywhere)
	uint8 CollectionSize;

private:
	TArray<UVisualElement*> CollectionArray;

	float ElementSpacing = 0.0f;
	bool ShouldUpdate = true;
};
