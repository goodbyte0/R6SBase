/**
* Overlord Project
* Copyright (C) 2016-2017 RangeMachine
*/

#pragma once

#include "stdafx.h"

class Settings
{
public:
	bool bESPEnabled;

	bool bESPBox;

	bool Menu;

	static Settings* GetInstance();

private:
	Settings();
	~Settings();

	static Settings* m_pInstance;
};