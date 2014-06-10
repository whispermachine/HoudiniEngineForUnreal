/*
 * PROPRIETARY INFORMATION.  This software is proprietary to
 * Side Effects Software Inc., and is not to be reproduced,
 * transmitted, or disclosed in any way without written permission.
 *
 * Produced by:
 *      Mykola Konyk
 *      Side Effects Software Inc
 *      123 Front Street West, Suite 1401
 *      Toronto, Ontario
 *      Canada   M5J 2M2
 *      416-504-9876
 *
 */

#pragma once
#include "IHoudiniEngine.h"

class IAssetTools;
class IAssetTypeActions;
class IComponentAssetBroker;

class FHoudiniEngine : public IHoudiniEngine
{

public: /** IModuleInterface methods. **/
	
	virtual void StartupModule() OVERRIDE;
	virtual void ShutdownModule() OVERRIDE;

public: /** IHoudiniEngine methods. **/

	virtual TSharedPtr<FSlateDynamicImageBrush> GetHoudiniLogoBrush() const OVERRIDE;

public:

	/** App identifier string. **/
	static const FName HoudiniEngineAppIdentifier;

public:

	/** Return singleton instance of Houdini Engine, used internally. **/
	static FHoudiniEngine& Get();

private:

	/** Register AssetType action. **/
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);

private:

	/** Singleton instnace of Houdini Engine. **/
	static FHoudiniEngine* HoudiniEngineInstance;

private:

	/** AssetType actions associated with Houdini asset. **/
	TArray<TSharedPtr<IAssetTypeActions> > AssetTypeActions;

	/** Broker associated with Houdini asset. **/
	TSharedPtr<IComponentAssetBroker> HoudiniAssetBroker;

	/** Houdini logo brush. **/
	TSharedPtr<FSlateDynamicImageBrush> HoudiniLogoBrush;
};