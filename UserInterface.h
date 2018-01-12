/**
* Overlord Project
* Copyright (C) 2016-2017 RangeMachine
*/

#pragma once

#include "stdafx.h"

class UserInterface
{
public:
	void SetStyle();
	void Render();

	static UserInterface* GetInstance();

private:
	UserInterface();
	~UserInterface();

	static UserInterface* m_pInstance;
};