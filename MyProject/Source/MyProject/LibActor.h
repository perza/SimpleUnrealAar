// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#ifdef USE_ANDROID_JNI
#include "jni.h"
#endif


#include "LibActor.generated.h"

UCLASS()
class MYPROJECT_API ALibActor : public AActor
{
	GENERATED_BODY()
	
public:	

#ifdef USE_ANDROID_JNI
	jclass globalMyClass;
#endif

	// Sets default values for this actor's properties
	ALibActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CreateLibInstance();
	
};
