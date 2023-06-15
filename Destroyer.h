// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "TeddyBear.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destroyer.generated.h"

/**
 * The destroyer
*/
UCLASS()
class RANDOMDESTRUCTION_API ADestroyer : public AActor
{
	GENERATED_BODY()
	
private:
	// declare your TArray here
	UPROPERTY()
		TArray<ATeddyBear*> TeddyBears;

	/**
	 * Destroys a random teddy bear in the TArray
	*/
	void DestroyTeddyBear();

	/**
	 * Starts the destroy timer
	*/
	void StartDestroyTimer();

public:
	/**
	 * Adds the given teddy bear to the TArray
	*/
	void AddTeddyBear(ATeddyBear* TeddyBear);

public:	
	/**
	 * Sets default values for this actor's properties
	*/
	ADestroyer();

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
