/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*
*	This product contains software technology licensed from Id
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/

#pragma once

#include "extdll.h"
#include "util.h"
#include "cbase.h"

#define SF_CONVEYOR_VISUAL		BIT( 0 )
#define SF_CONVEYOR_NOTSOLID		BIT( 1 )
#define SF_CONVEYOR_STARTOFF		BIT( 2 )

class CFuncConveyor : public CBaseDelay
{
	DECLARE_CLASS(CFuncConveyor, CBaseDelay);
public:
	void Spawn(void);
	void Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);
	virtual int ObjectCaps(void) { return (BaseClass::ObjectCaps() & ~FCAP_ACROSS_TRANSITION) | FCAP_SET_MOVEDIR; }
	void UpdateSpeed(float speed);

	DECLARE_DATADESC();

	float	m_flMaxSpeed;
};