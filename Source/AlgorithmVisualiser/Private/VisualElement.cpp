// © 2022 Will Masek

// This file's header
#include "VisualElement.h"

void UVisualElement::InitialiseElement(UStaticMesh* Mesh, float Scale)
{
	// Set the actual mesh
	if (Mesh)
	{
		SetStaticMesh(Mesh);
	}

	// Get a random float for the element value
	ElementValue = FMath::RandRange(0.5f, 3.0f);

	// Use the width and value to set the scale of the component
	SetWorldScale3D(FVector(Scale, Scale, ElementValue));
}