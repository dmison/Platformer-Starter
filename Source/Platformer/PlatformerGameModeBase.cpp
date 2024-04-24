// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerGameModeBase.h"

void APlatformerGameModeBase::BeginPlay(){
  Super::BeginPlay();

  // 1. When the game starts, initialise the SpawnTransform to the PlayerStart actor location
  AActor *PlayerStart = FindPlayerStart(GetWorld()->GetFirstPlayerController());
  SpawnTransform = PlayerStart->GetTransform();

  // Debugging - print the spawn location to the Output Log
  FString Location = FString::Printf(
    TEXT("%f, %f, %f"), 
    SpawnTransform.GetLocation().X, 
    SpawnTransform.GetLocation().Y, 
    SpawnTransform.GetLocation().Z
  );
  UE_LOG(LogTemp, Warning, TEXT("Spawn Location: %s"), *Location);
  // Bind to this new player character events
  BindToPlayerEvents();

}

void APlatformerGameModeBase::BindToPlayerEvents(){
  APawn *PlayerCharacter = GetWorld()->GetFirstPlayerController()->GetPawn();
  PlayerCharacter->OnDestroyed.AddDynamic(
    this, 
    &APlatformerGameModeBase::OnPlayerDestroyed
  );
}

void APlatformerGameModeBase::OnPlayerDestroyed(AActor *DestroyedActor){

  UE_LOG(LogTemp, Warning, TEXT("Game Mode - Player Destroyed! Respawning..."));

  // Respawn the player at the "SpawnTransform" location
  RestartPlayerAtTransform(GetWorld()->GetFirstPlayerController(), SpawnTransform);
  BindToPlayerEvents();

}
