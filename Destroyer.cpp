// Copyright A.T. Chamillard. All Rights Reserved.


#include "Destroyer.h"
#include "TimerManager.h"
#include "TeddyBear.h"

/**
 * Sets default values
*/
ADestroyer::ADestroyer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * Called when the game starts or when spawned
*/
void ADestroyer::BeginPlay()
{
	Super::BeginPlay();

	StartDestroyTimer();
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void ADestroyer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
 * Adds the given teddy bear to the TArray
*/
void ADestroyer::AddTeddyBear(ATeddyBear* TeddyBear)
{
	// add code here to add the given
	// teddy bear to the TArray
	if (TeddyBear != nullptr) {
		TeddyBears.Add(TeddyBear);
	}

}

/**
 * Destroys a random teddy bear in the TArray
*/
void ADestroyer::DestroyTeddyBear()
{
	// make sure TArray isn't empty
	if (TeddyBears.Num() > 0) {
		// add code here to randomly pick a teddy 
		// bear index, save the teddy bear at that
		// index, remove the teddy bear from the
		// TArray, and destroy it
		int destroyIndex = FMath::RandRange(0, TeddyBears.Num() - 1);
		ATeddyBear* TeddyBearToDesroy = TeddyBears[destroyIndex];
		TeddyBears.Remove(TeddyBearToDesroy);
		TeddyBearToDesroy->Destroy();
	// restart the destroy timer
		StartDestroyTimer();
	}
}

/**
 * Starts the destroy timer
*/
void ADestroyer::StartDestroyTimer()
{
	// start 2 second timer
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ADestroyer::DestroyTeddyBear,2.0f);
}