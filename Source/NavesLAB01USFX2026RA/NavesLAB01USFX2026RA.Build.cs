// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NavesLAB01USFX2026RA : ModuleRules
{
	public NavesLAB01USFX2026RA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
