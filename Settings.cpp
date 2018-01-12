/**
* Overlord Project
* Copyright (C) 2016-2017 RangeMachine
*/

#include "Settings.h"

#include "ImGui/imgui.h"

Settings* Settings::m_pInstance;

Settings::Settings()
{
	// ESP
	bool bESPEnabled = false;

	bool bESPBox = false;

	bool Menu = false;
}

Settings::~Settings()
{
}

Settings* Settings::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new Settings();

	return m_pInstance;
}