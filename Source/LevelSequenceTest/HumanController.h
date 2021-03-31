// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/LevelSequence/Public/LevelSequence.h"
#include "Runtime/LevelSequence/Public/LevelSequencePlayer.h"
#include "HumanController.generated.h"

UCLASS()
class LEVELSEQUENCETEST_API AHumanController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHumanController();

	UPROPERTY(EditAnywhere, Category = "attributes")
	AActor* BoxMesh1;
	UPROPERTY(EditAnywhere, Category = "attributes")
	AActor* BoxMesh2;

	void PlayAnimation1();

	void PlayAnimation2();

	UPROPERTY()
	class ULevelSequencePlayer* SequencePlayer;

	UPROPERTY()
	class ULevelSequencePlayer* SequencePlayer1;

	// Sequence Assets
	UPROPERTY(EditAnywhere)
	class ULevelSequence* SequenceAsset;

	// Sequence Assets
	UPROPERTY(EditAnywhere)
	class ULevelSequence* SequenceAsset1;
	
	ALevelSequenceActor* SequenceActor;

	ALevelSequenceActor* SequenceActor1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//void RebindActorToBindingByName(AActor* ActorToRebind, ALevelSequenceActor* LevelSequenceActor, const FString& BindingName);

};
