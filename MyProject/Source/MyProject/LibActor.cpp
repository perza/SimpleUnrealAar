// Fill out your copyright notice in the Description page of Project Settings.

#include "LibActor.h"

#ifdef USE_ANDROID_JNI
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

// Sets default values
ALibActor::ALibActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALibActor::BeginPlay()
{
	Super::BeginPlay();

	CreateLibInstance();
}

// Called every frame
void ALibActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALibActor::CreateLibInstance()
{
#ifdef USE_ANDROID_JNI

	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		//:TEST1: call method added in the AndroiLIb_UPL.xml
		jmethodID AndroidThunkJava_DebugStringToAdb = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_DebugStringToAdb", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_DebugStringToAdb);

		//:TEST2: get class from library.
		globalMyClass = (jclass)Env->NewGlobalRef(FAndroidApplication::FindJavaClass("com/mycompany/myproduct/mylibrary/MyTestClass"));
	}

#endif
}

