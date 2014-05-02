//
//  main.cpp
//  MemoryAimbot
//
//  Created by Rahim Mitha on 2014-04-29.
//  Copyright (c) 2014 Rahim Mitha. All rights reserved.
//

#include <iostream>
#include "HackProcess.h"
#include "Player.h"

HackProcess fProcess;

#define VK_LEFT_MOUSE_CLICK 0x01
#define VK_F_KEY 0x46
#define F6_KEY 0x75


int main(int argc, const char * argv[])
{
	fProcess.RunProcess();
	std::cout << "Game Found! Running aimbot..." << std::endl;
	
	while (!GetAsynchKeyState(F6_KEY)) {
		
		
	}
	
    return 0;
}

