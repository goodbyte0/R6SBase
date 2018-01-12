/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#include "Vector3.h"
#include "stdafx.h"

namespace Engine
{
	class Entity
	{
		public:
			Vector3& GetPosition();
			Vector3& GetBone();
			Vector3& GetNeck();
			Vector3& GetHead();
			Vector3& GetRightHand();
			Vector3& GetLeftHand();
			float GetHealth();
    };
}
