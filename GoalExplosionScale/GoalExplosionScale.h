#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);


// Function TAGame.Ball_TA.SetExplosionFXActor
struct ABall_TA_execSetExplosionFXActor_Params
{
	void* InExplosion;
	void* ExplosionGoal;
	void* ExplosionFX;
	void* GoalOrientation;
};


class GoalExplosionScale: public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginSettingsWindow
{
	std::shared_ptr<bool> Enabled = std::make_shared<bool>(true);
	std::shared_ptr<float> DrawScale = std::make_shared<float>(1.f);

	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();

	// Inherited via PluginSettingsWindow
	void RenderSettings() override;
	std::string GetPluginName() override;
	void SetImGuiContext(uintptr_t ctx) override;
};

