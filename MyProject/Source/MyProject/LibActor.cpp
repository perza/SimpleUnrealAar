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
		FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_DebugStringToAdb);


		//JNIEnv* env = FAndroidApplication::GetJavaEnv();
		//jclass localGameActivityClass = FJavaWrapper::FindClass(Env, "com/epicgames/ue4/GameActivity", false);
		//__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "AndroidCamera: StartupModule - localGameActivityClass: 0x%p", GameActivityClassID);
		// GameActivityClassID = (jclass)Env->NewGlobalRef(localGameActivityClass);
		//jmethodID AndroidThunkJava_DebugStringToAdb = FJavaWrapper::FindMethod(Env, localGameActivityClass, "AndroidThunkJava_DebugStringToAdb", "()V", false);
		//FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_DebugStringToAdb);


		// globalMyClass = (jclass)Env->NewGlobalRef(FAndroidApplication::FindJavaClass("com/mycompany/myproduct/mylibrary/MyTestClass"));

		//:TEST2: find a class in an AAR library
		jclass localMyClass = FJavaWrapper::FindClass(Env, "com/mycompany/myproduct/mylibrary/MyTestClass", false); //
		globalMyClass = (jclass)Env->NewGlobalRef(localMyClass);
		Env->DeleteLocalRef(localMyClass);
	}

	/*
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID SetIntegerKeyMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_MyCode_SetIntegerKey", "(Ljava/lang/String;I)V", false);

		jstring KeyJava = Env->NewStringUTF(TCHAR_TO_UTF8(*Key));
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, SetIntegerKeyMethod, KeyJava, Value);
		Env->DeleteLocalRef(KeyJava);
	}
	*/



	/*
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID CreateLibManagerInstanceMethod = FJavaWrapper::FindStaticMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CreateLibManagerInstance", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, CreateLibManagerInstanceMethod);
	}*/
#endif
}

