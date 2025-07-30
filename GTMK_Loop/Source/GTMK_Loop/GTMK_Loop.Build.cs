// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GTMK_Loop : ModuleRules
{
	public GTMK_Loop(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
