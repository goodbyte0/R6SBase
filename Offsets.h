/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#define ADDRESS_GAMEMANAGER 0x4A8BE58  // Game->
#define ADDRESS_GAMERENDERER 0x4A30790 // Game->

#define OFFSET_GAMERENDERER_ENGINELINK 0x120 // GameRenderer->
#define OFFSET_ENGINELINK_ENGINE 0x218 // GameRenderer->EngineLink->
#define OFFSET_ENGINE_CAMERA 0x38 // GameRenderer->EngineLink->Engine->

#define OFFSET_CAMERA_VIEWRIGHT 0x170 // Camera->
#define OFFSET_CAMERA_VIEWUP 0x180 // Camera->
#define OFFSET_CAMERA_VIEFORWARD 0x190 // Camera->
#define OFFSET_CAMERA_VIEWTRANSLATION 0x1A0 // Camera->
#define OFFSET_CAMERA_VIEWFOVX 0x1B0 // Camera->
#define OFFSET_CAMERA_VIEWFOVY 0x1C4 // Camera->

#define OFFSET_GAMEMANAGER_ENTITYLIST 0xB8 // GameManager->

#define OFFSET_ENTITY_ENTITYINFO 0x18 // Entity->
#define OFFSET_ENTITY_PLAYERINFO 0x2A0 // Entity->

#define OFFSET_ENTITYINFO_MAINCOMPONENT 0xA8 // Entity->EntityInfo->
#define OFFSET_MAINCOMPONENT_CHILDCOMPONENT 0x8 // Entity->EntityInfo->MainComponent->
#define OFFSET_CHILDCOMPONENT_HEALTH 0x118 // Entity->EntityInfo->MainComponent->ChildComponent->

#define OFFSET_PLAYERINFO_COMPONENT_TEAM 0x148 // Entity->PlayerInfo->
#define OFFSET_PLAYERINFO_COMPONENT_NAME 0x170  // Entity->PlayerInfo->

#define OFFSET_ENTITY_POSITION 0x190 // Entity->
#define OFFSET_ENTITY_NECK 0x130 // Entity->
#define OFFSET_ENTITY_HEAD 0x140 // Entity->
#define OFFSET_ENTITY_RIGHTHAND 0x170 // Entity->
#define OFFSET_ENTITY_LEFTHAND 0x1B0 // Entity->







