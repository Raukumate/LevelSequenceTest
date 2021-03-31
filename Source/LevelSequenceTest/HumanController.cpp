// Fill out your copyright notice in the Description page of Project Settings.


#include "HumanController.h"
#include "Runtime/LevelSequence/Public/LevelSequence.h"
#include "Runtime/LevelSequence/Public/LevelSequencePlayer.h"
#include "LevelSequenceActor.h"

// Sets default values
AHumanController::AHumanController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHumanController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHumanController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHumanController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &AHumanController::PlayAnimation1);
	PlayerInputComponent->BindAction("RightClick", IE_Pressed, this, &AHumanController::PlayAnimation2);
}

void AHumanController::PlayAnimation1()
{
	if (SequenceAsset && SequencePlayer == nullptr)
		SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), SequenceAsset, FMovieSceneSequencePlaybackSettings(), OUT SequenceActor1);

	ULevelSequence* LevelSequence = SequenceActor1->GetSequence();
	TArray<FMovieSceneBinding> Bindings = LevelSequence->GetMovieScene()->GetBindings();
	FMovieSceneBinding MovieSceneBinding = Bindings[0];
	FMovieSceneObjectBindingID BindingId = FMovieSceneObjectBindingID(MovieSceneBinding.GetObjectGuid(), MovieSceneSequenceID::Root);
	SequenceActor1->SetBinding(BindingId, TArray<AActor*>{ BoxMesh1 });

	//Sequence Play
	if (SequencePlayer)
	{
		SequencePlayer->Play();
	}
}


void AHumanController::PlayAnimation2()
{
	if (SequenceAsset1 && SequencePlayer1 == nullptr)
		SequencePlayer1 = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), SequenceAsset1, FMovieSceneSequencePlaybackSettings(), OUT SequenceActor);

	ULevelSequence* LevelSequence1 = SequenceActor->GetSequence();
	TArray<FMovieSceneBinding> Bindings = LevelSequence1->GetMovieScene()->GetBindings();
	FMovieSceneBinding MovieSceneBinding = Bindings[0];
	FMovieSceneObjectBindingID BindingId = FMovieSceneObjectBindingID(MovieSceneBinding.GetObjectGuid(), MovieSceneSequenceID::Root);
	SequenceActor->SetBinding(BindingId, TArray<AActor*>{ BoxMesh2 });

	//Sequence Play
	if (SequencePlayer1)
	{
		SequencePlayer1->Play();
	}
}

//void AHumanController::RebindActorToBindingByName(
//	AActor* ActorToRebind,
//	ALevelSequenceActor* LevelSequenceActor,
//	const FString& BindingName
//)
//{
//	ULevelSequence* LevelSequence = LevelSequenceActor->GetSequence();
//	TArray<FMovieSceneBinding> Bindings = LevelSequence->GetMovieScene()->GetBindings();
//	int NumBindings = Bindings.Num();
//	for (int i = 0; i < NumBindings; i++)
//	{
//		FMovieSceneBinding MovieSceneBinding = Bindings[i];
//		if (!MovieSceneBinding.GetName().Equals(BindingName))
//		{
//			continue;
//		}
//
//		FMovieSceneObjectBindingID BindingId = FMovieSceneObjectBindingID(MovieSceneBinding.GetObjectGuid(), MovieSceneSequenceID::Root);
//		LevelSequenceActor->SetBinding(BindingId, TArray<AActor*>{ ActorToRebind });
//
//		return;
//	}
//	UE_LOG(LogTemp, Warning, TEXT("Could not find a Binding by the name of %s to bind this actor"), *BindingName);
//}