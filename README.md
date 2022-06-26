# SimpleUnrealJar

__MyLibProj__ - Android Studio project for building a very minimal `.jar` library;

__MyProject__ - Unreal project that tries to connect to the `.jar` library.

## Reproduce

1. Go to the Android Studio project and create a new jar file with the `MyLibProj->mylibrary->Tasks->other->createFullJarRelease` gradle task. Created `jar` archive can be found in the following path:

```
MyLibProj\mylibrary\build\intermediates\full_jar\release\full.jar
```

2. Copy it to the UE project to the path:

```
MyProject\Plugins\TestPlugin\ThirdParty\repository\mylibrary-release.jar
```

3. Launch the game on your device. There should appear toast with the following message:

```
DebugStringToast
```

4. If you have any errors or troubles with launching the game on the phone, use advices [here](https://forums.unrealengine.com/t/android-builds-do-not-work-anymore/139067/10?u=prikalel).