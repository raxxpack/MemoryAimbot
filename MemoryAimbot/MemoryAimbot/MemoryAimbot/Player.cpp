//
//  Player.cpp
//  MemoryAimbot
//
//  Created by Rahim Mitha on 2014-04-29.
//  Copyright (c) 2014 Rahim Mitha. All rights reserved.
//

#include "Player.h"
#include <Windows.h>
#include "HackProcess.h"

void ReadInformation(int playerNum, HackProcess fProcess) {
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + dw_entityBase + (playerNum*dw_EntityLoopDistance)), &CBaseEntity, sizeof(int), 0);
	
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwTeam), &team, sizeof(int), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwCloaked), &isCloaked, sizeof(int), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwCharacterClass), &characterClass, sizeof(int), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwHealth), &health, sizeof(int), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwPose), &pose, sizeof(int), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwIsVisible), &isVisible, sizeof(bool), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwCrosshairEntityID), &crosshairEntityID, sizeof(bool), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwBoneMatrix), &boneMatrix, sizeof(void*), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwAngle), &angle, sizeof(float), 0);
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dwOrigin), &origin, sizeof(float[3]), 0);
}
