// © 2022 Will Masek

// This file's header
#include "VisualElement.h"

const float MinElementHeight = 0.1f;
const float MaxElementHeight = 5.0f;

void UVisualElement::InitialiseElement(UStaticMesh* Mesh, float Scale)
{
	// Set the actual mesh
	if (Mesh)
	{
		SetStaticMesh(Mesh);
	}

	// Get a random float for the element value
	ElementValue = FMath::RandRange(MinElementHeight, MaxElementHeight);

	// Use the width and value to set the scale of the component
	SetWorldScale3D(FVector(Scale, Scale, ElementValue));
}