// Copyright A.T. Chamillard. All Rights Reserved.


#include "TeddyBear.h"

/**
 * Sets default values
*/
ATeddyBear::ATeddyBear()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/**
 * Called when the game starts or when spawned
*/
void ATeddyBear::BeginPlay()
{
	Super::BeginPlay();
	
}

/**
 * Called every frame
 * @param DeltaTime Game time elapsed during last frame modified by the time dilation
*/
void ATeddyBear::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

