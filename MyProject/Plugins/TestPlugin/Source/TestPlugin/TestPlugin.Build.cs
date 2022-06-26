// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class TestPlugin: ModuleRules {
  public TestPlugin(ReadOnlyTargetRules Target): base(Target) {
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
    PublicIncludePaths.AddRange(
      new string[] {
        // ... add public include paths required here ...
      }
    );

    PrivateIncludePaths.AddRange(
      new string[] {
        // ... add other private include paths required here ...
      }
    );

    PublicDependencyModuleNames.AddRange(
      new string[] {
        "Core",
        "CoreUObject",
        "Engine"
        // ... add other public dependencies that you statically link with here ...
      }
    );

    PrivateDependencyModuleNames.AddRange(
      new string[] {
        // ... add private dependencies that you statically link with here ...
      }
    );

    DynamicallyLoadedModuleNames.AddRange(
      new string[] {
        // ... add any modules that your module loads dynamically here ...
      }
    );

    PrivateIncludePathModuleNames.AddRange(
      new string[] {
        "Settings",
        "Launch",
      }
    );

    // Read this related thread: https://forums.unrealengine.com/development-discussion/android-development/76381-how-do-i-include-native-libraries-from-a-plugin

    if (Target.Platform == UnrealTargetPlatform.Android) {
      bool bHasJAR = false;
      string JarNFLDir = "";
      try {
        JarNFLDir = Path.Combine(ModuleDirectory, "../../ThirdParty/repository");
        bHasJAR = System.IO.Directory.Exists(JarNFLDir);
      } catch (System.Exception) {}

      if (bHasJAR) {
        string Err = string.Format("Jar Library found in {0}", JarNFLDir);
        System.Console.WriteLine(Err);
        PublicLibraryPaths.Add(JarNFLDir); // <- important.

        string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
        AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "AndroidLib_UPL.xml")));
      } else {
        string Err = string.Format("Jar Library not found in {0}", JarNFLDir);
        System.Console.WriteLine(Err);
      }
    }
  }
}