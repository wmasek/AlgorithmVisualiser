// © 2022 Will Masek

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "VisualElement.generated.h"

/**
 * 
 */
UCLASS()
class ALGORITHMVISUALISER_API UVisualElement : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void InitialiseElement(UStaticMesh* Mesh, float Scale);

	float GetElementValue() { return ElementValue; }

private:
	float ElementValue;
};
