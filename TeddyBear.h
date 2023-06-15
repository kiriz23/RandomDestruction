// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeddyBear.generated.h"

/**
 * A teddy bear
*/
UCLASS()
class RANDOMDESTRUCTION_API ATeddyBear : public AActor
{
	GENERATED_BODY()
	
public:	
	/**
	 * Sets default values for this actor's properties
	*/
	ATeddyBear();

protected:
	/**
	 * Called when the game starts or when spawned
	*/
	virtual void BeginPlay() override;

public:	
	/**
	 * Called every frame
	 * @param DeltaTime Game time elapsed during last frame modified by the time dilation 
	*/
	virtual void Tick(float DeltaTime) override;

};
