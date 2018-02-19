// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "buildingescapeGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodebuildingescapeGameModeBase() {}
// Cross Module References
	BUILDINGESCAPE_API UClass* Z_Construct_UClass_AbuildingescapeGameModeBase_NoRegister();
	BUILDINGESCAPE_API UClass* Z_Construct_UClass_AbuildingescapeGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_buildingescape();
// End Cross Module References
	void AbuildingescapeGameModeBase::StaticRegisterNativesAbuildingescapeGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AbuildingescapeGameModeBase_NoRegister()
	{
		return AbuildingescapeGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AbuildingescapeGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_buildingescape,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "buildingescapeGameModeBase.h" },
				{ "ModuleRelativePath", "buildingescapeGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AbuildingescapeGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AbuildingescapeGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AbuildingescapeGameModeBase, 2455055341);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AbuildingescapeGameModeBase(Z_Construct_UClass_AbuildingescapeGameModeBase, &AbuildingescapeGameModeBase::StaticClass, TEXT("/Script/buildingescape"), TEXT("AbuildingescapeGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AbuildingescapeGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
