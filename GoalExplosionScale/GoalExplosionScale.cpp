#include "pch.h"
#include "GoalExplosionScale.h"


BAKKESMOD_PLUGIN(GoalExplosionScale, "GoalExplosionScale", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void GoalExplosionScale::onLoad()
{
	_globalCvarManager = cvarManager;

	cvarManager->registerCvar("goalexplosionscale_enabled", "1", "Enable/Disable the plugin. 0 = false = disabled, 1 = true = enabled")
		.bindTo(Enabled); // bind the global shared pointer to this CVar
	cvarManager->registerCvar("goalexplosionscale_drawscale", "1", "Scale of the goals explosions")
		.bindTo(DrawScale); // bind the global shared pointer to this CVar

	gameWrapper->HookEventWithCaller<BallWrapper>("Function TAGame.Ball_TA.SetExplosionFXActor", [this](BallWrapper caller, void* params, std::string eventName) {

		ABall_TA_execSetExplosionFXActor_Params* param = (ABall_TA_execSetExplosionFXActor_Params*)params;
		if (!param) return;

		if (param->ExplosionFX)
		{
			ActorWrapper fx = ActorWrapper(reinterpret_cast<uintptr_t>(param->ExplosionFX));

			if (*Enabled.get())
				fx.SetDrawScale(*DrawScale.get());
			else
				fx.SetDrawScale(1.f);
		}
		});
}

void GoalExplosionScale::onUnload()
{
}