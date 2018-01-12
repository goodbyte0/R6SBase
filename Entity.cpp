/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include "Entity.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Vector3& Entity::GetPosition()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_POSITION);
	}

	Vector3& Entity::GetNeck()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_NECK);
	}

	Vector3& Entity::GetHead()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_HEAD);
	}

	Vector3& Entity::GetRightHand()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_RIGHTHAND);
	}

	Vector3& Entity::GetLeftHand()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_LEFTHAND);
	}

	float Entity::GetHealth()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return 0.0f;

		auto pEntityInfo = *Memory::Ptr<void**>(this, OFFSET_ENTITY_ENTITYINFO);

		auto pMainComponent = *Memory::Ptr<void**>(pEntityInfo, OFFSET_ENTITYINFO_MAINCOMPONENT);

		auto pChildComponent = *Memory::Ptr<void**>(pMainComponent, OFFSET_MAINCOMPONENT_CHILDCOMPONENT);

		return *Memory::Ptr<float*>(pChildComponent, OFFSET_CHILDCOMPONENT_HEALTH);
	}

	
}