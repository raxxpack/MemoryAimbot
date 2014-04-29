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
	
	ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(CBaseEntity + dw_teamOffset), &team, sizeof(int), 0);
}
