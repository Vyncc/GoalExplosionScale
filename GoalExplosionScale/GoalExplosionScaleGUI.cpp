#include "pch.h"
#include "GoalExplosionScale.h"

std::string GoalExplosionScale::GetPluginName() {
	return "GoalExplosionScale";
}

void GoalExplosionScale::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> GoalExplosionScale
void GoalExplosionScale::RenderSettings()
{
	ImGui::Checkbox("Enabled", Enabled.get());
	ImGui::SliderFloat("DrawScale", DrawScale.get(), 0.f, 100.f);
}
