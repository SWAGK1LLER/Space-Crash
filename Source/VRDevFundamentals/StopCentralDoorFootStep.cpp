// Fill out your copyright notice in the Description page of Project Settings.


#include "StopCentralDoorFootStep.h"
#include "AIController.h"
#include "AlienController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Components/AudioComponent.h"

EBTNodeResult::Type UStopCentralDoorFootStep::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BBComp = OwnerComp.GetAIOwner()->GetBlackboardComponent();
	AAlienController* Alien = Cast<AAlienController>(BBComp->GetValueAsObject("SelfActor"));
	if (Alien->AudioPlayerFeet->IsPlaying())
	{
		Alien->AudioPlayerFeet->Stop();
		Alien->AudioPlayerBreath->Stop();
	}
	return EBTNodeResult::Succeeded;
}