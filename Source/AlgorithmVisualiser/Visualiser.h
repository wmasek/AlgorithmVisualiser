// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Visualiser.generated.h"

UCLASS()
class ALGORITHMVISUALISER_API AVisualiser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVisualiser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int NumOfCubes = 10;

	UPROPERTY(EditAnywhere)
	TArray<UStaticMeshComponent*> CubeArray;

	float UpdateTimer = 0.0f;
};
