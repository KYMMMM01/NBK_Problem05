// Fill out your copyright notice in the Description page of Project Settings.
#include "Engine/Engine.h"
#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	//시작위치
	SetActorLocation(FVector(0, 50, 0));

	//로그 출력
	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White,
			FString::Printf(TEXT("시작 위치: %s"), *GetActorLocation().ToString()));
	}
	
	////10번 반복
	//for (int32 i = 0; i < 10; i++)
	//{
	//	int32 Random = FMath::RandRange(0, 1); //0 또는 1 랜덤 반환
	//	if (Random == 0) //0이면 Move 1이면 Turn
	//		Move(100.f);
	//	else
	//		Turn(45.f);
	//}
}

//일정 시간마다 Move/Turn 실행 총 10번
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Count >= 10)
		return;

	Time += DeltaTime;

	if (Time >= t) 
	{
		Time = 0.f; 

		if (FMath::RandRange(0, 1) == 0)
			Move(200.f);
		else
			Turn(45.f);

		Count++;

	}

}

void AMyActor::Move(float Distance)
{
	FVector Location = GetActorLocation();

	//랜덤 이동 구현
	int32 rnum = FMath::RandRange(1, 4);
	if (rnum == 1) 
	{
		Location += FVector(Distance, 0, 0);
	}
	else if (rnum == 2)
	{
		Location -= FVector(Distance, 0, 0);
	}
	else if (rnum == 3)
	{
		Location += FVector(0, Distance, 0);
	}
	else
	{
		Location -= FVector(0, Distance, 0);
	}

	
	SetActorLocation(Location); //Location값 반영하여 위치 변경

	//로그 출력
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue,
			FString::Printf(TEXT("이동 후 위치: %s"), *GetActorLocation().ToString()));

	}
}

void AMyActor::Turn(float Angle)
{
	FRotator Rotation = GetActorRotation();

	Rotation.Yaw += Angle;
	
	SetActorRotation(Rotation);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green,
			FString::Printf(TEXT("회전 후 각도: %s"), *GetActorRotation().ToString()));

	}
}
