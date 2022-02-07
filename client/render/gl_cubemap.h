#pragma once
#include "vector.h"
#include "mathlib.h"
#include "gl_framebuffer.h"

// rebuilding cubemap states
enum CubemapBuildState
{
	CMREBUILD_INACTIVE,
	CMREBUILD_CHECKING,
	CMREBUILD_WAITING // waiting when engine finish cubemap baking
};

typedef struct mcubemap_s
{
	char			name[64];
	int				texture;
	CFrameBuffer	framebuffer;
	vec3_t			mins, maxs;
	vec3_t			origin;
	bool			valid;
	short			size;
	byte			numMips;
} mcubemap_t;