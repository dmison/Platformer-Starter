// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMER_API APlatformerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	protected:
		virtual void BeginPlay() override;
		void BindToPlayerEvents();

	public:
		UFUNCTION()
		void OnPlayerDestroyed(AActor *DestroyedActor);

		FTransform SpawnTransform;
};
