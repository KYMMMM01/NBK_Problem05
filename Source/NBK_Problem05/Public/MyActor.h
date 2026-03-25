// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class NBK_PROBLEM05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(float Distance); //이동
	void Turn(float Angle); //회전

private:
	float TravelDistance = 0.f;
	
	int32 Count = 0; //몇 번째인지
	float Time = 0.f; //경과 시간
	float t = 1.0f; //몇 초마다 실행할지
};
