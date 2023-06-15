// Copyright A.T. Chamillard. All Rights Reserved.


#include "TeddyBearSpawner.h"

#include "Kismet/GameplayStatics.h"

/**
 * Sets default values
*/
ATeddyBearSpawner::ATeddyBearSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * Called when the game starts or when spawned
*/
void ATeddyBearSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	// save Destroyer for efficiency
	TArray<AActor*> TaggedActors;
	UGameplayStatics::GetAllActorsWithTag(
		GetWorld(), "Destroyer", TaggedActors);
	if (TaggedActors.Num() > 0)
	{
		Destroyer = (ADestroyer*)TaggedActors[0];
	}

	StartSpawnTimer();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void ATeddyBearSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/**
 * Spawns a teddy bear
*/
void ATeddyBearSpawner::SpawnTeddyBear()
{
	// randomly pick which teddy bear to spawn
	TSubclassOf<ATeddyBear> SpawnTeddyBear;
	int TeddyBearNumber = FMath::RandRange(0, 2);
	if (TeddyBearNumber == 0)
	{
		SpawnTeddyBear = UGreenTeddyBear;
	}
	else if (TeddyBearNumber == 1)
	{
		SpawnTeddyBear = UPurpleTeddyBear;
	}
	else
	{
		SpawnTeddyBear = UYellowTeddyBear;
	}

	// generate random spawn location
	FVector SpawnLocation{ 0 };
	SpawnLocation.SetComponentForAxis(EAxis::Y,
		FMath::RandRange(MinSpawnY, MaxSpawnY));
	SpawnLocation.SetComponentForAxis(EAxis::Z,
		FMath::RandRange(MinSpawnZ, MaxSpawnZ));

	// change code below to save the
	// spawned teddy bear and call the
	// Destroyer AddTeddyBear function
	// Note: The Destroyer field holds a
	// pointer to the Destroyer Actor
	ATeddyBear* Bear=	GetWorld()->SpawnActor<ATeddyBear>(
				SpawnTeddyBear, SpawnLocation,
				FRotator::ZeroRotator);
	
	Destroyer->AddTeddyBear(Bear);
	

	// start the timer again
	StartSpawnTimer();
}

/**
 * Starts the spawn timer
*/
void ATeddyBearSpawner::StartSpawnTimer()
{
	// start 1 second timer
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this,
		&ATeddyBearSpawner::SpawnTeddyBear,
		1.0f);
}