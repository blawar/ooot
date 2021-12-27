#pragma once

#define MULTILINE(...) #__VA_ARGS__

namespace shaders
{
	const char* fogFunc = MULTILINE(vec3 applyFog(in vec3 rgb, in float distance) {
		float fogAmount = 1.0 - exp(-distance * 1.0);
		vec3 fogColor	= vec3(0.5, 0.6, 0.7);
		return mix(rgb, fogColor, fogAmount);
	});
}
