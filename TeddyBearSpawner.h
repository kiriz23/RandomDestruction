// Copyright A.T. Chamillard. All Rights Reserved.

#pragma once

#include "Destroyer.h"
#include "TeddyBear.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeddyBearSpawner.generated.h"

/**
 * The teddy bear spawner
*/
UCLASS()
class RANDOMDESTRUCTION_API ATeddyBearSpawner : public AActor
{
	GENERATED_BODY()
	
private:
	ADestroyer* Destroyer;

	// spawn location support
	const float MinSpawnY{ -200 };
	const float MaxSpawnY{ 200 };
	const float MinSpawnZ{ 0 };
	const float MaxSpawnZ{ 100 };

	/**
	 * Starts the spawn timer
	*/
	void StartSpawnTimer();

public:
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "TeddyBear"),
		Category = TeddyBearBlueprints)
		TSubclassOf<ATeddyBear> UGreenTeddyBear;
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "TeddyBear"),
		Category = TeddyBearBlueprints)
		TSubclassOf<ATeddyBear> UPurpleTeddyBear;
	UPROPERTY(EditAnywhere,
		meta = (MetaClass = "TeddyBear"),
		Category = TeddyBearBlueprints)
		TSubclassOf<ATeddyBear> UYellowTeddyBear;

	/**
	 * Spawns a teddy bear
	*/
	UFUNCTION()
		void SpawnTeddyBear();
public:	
	/**
	 * Sets default values for this actor's properties
	*/
	ATeddyBearSpawner();

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
