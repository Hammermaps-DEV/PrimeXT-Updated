#pragma once
#include "mathlib.h"
#include "gl_local.h"
#include "gl_shader.h"

#define DEAD_GRAYSCALE_TIME		5.0f
#define TARGET_SIZE				256

// post-process shaders
class CBasePostEffects
{
public:
	word	blurShader[2];		// e.g. underwater blur	
	word	dofShader;		// iron sight with dof
	word	monoShader;		// monochrome effect
	word	genSunShafts;		// sunshafts effect
	word	drawSunShafts;		// sunshafts effect
	word	tonemapShader;
	word	luminanceGenShader;
	word	luminanceDownscaleShader;
	word	blurMipShader;
	word	bloomShader;

	int	target_rgb[2];
	float	grayScaleFactor;
	float	blurFactor[2];
	bool	m_bUseTarget;

	// DOF parameters
	float	m_flCachedDepth;
	float	m_flLastDepth;
	float	m_flStartDepth;
	float	m_flOffsetDepth;
	float	m_flStartTime;
	float	m_flDelayTime;
	float	m_flStartLength;
	float	m_flOffsetLength;
	float	m_flLastLength;
	float	m_flDOFStartTime;

	// automatic exposure 
	gl_drawbuffer_t	*avg_luminance_fbo[11];
	int	avg_luminance_texture;
	GLuint avg_luminance_pbo[2];

	// sunshafts variables
	Vector	m_vecSunLightColor;
	Vector	m_vecSunPosition;

	void InitializeTextures();
	void InitializeShaders();

	void RequestScreenColor();
	void RequestScreenDepth();
	void RequestTargetCopy(int slot);
	bool ProcessDepthOfField();
	bool ProcessSunShafts();
	void SetNormalViewport();
	void SetTargetViewport();
	bool Begin();
	void End();

	float ComputeAvgLuminance();
	float ComputeExposure(float avgLuminance);

private:
	void InitScreenColor();
	void InitScreenDepth();
	void InitTargetColor(int slot);
	void InitDepthOfField();

	void InitAutoExposure();
	float ComputeEV100FromAvgLuminance(float avgLum);
	float ConvertEV100ToExposure(float ev100);
};
