//
//  Player.h
//  MemoryAimbot
//
//  Created by Rahim Mitha on 2014-04-29.
//  Copyright (c) 2014 Rahim Mitha. All rights reserved.
//

#ifndef __MemoryAimbot__Player__
#define __MemoryAimbot__Player__

#include <iostream>
#include <vector>

//Valid as of Apr 29 2014
//Offsets
const DWORD dwPlayerBase = 0x102AC9C;
const DWORD dwEntityBase = 0x1038314;
const DWORD dwEntitySize = 0x10;

//Entity
const DWORD dwHealth = 0xA4;
const DWORD dwClass = 0x1524;
const DWORD dwTeam = 0xAC;
const DWORD dwPose;
const DWORD dwMaxHealth = 0x1778;
const DWORD dwCrosshairEntityID;


class Player {
public:
	int team;
	int health;
	int maxHealth;
	int pose; //eg. Crouching, standing, scoped
	int crosshairEntityID;
	
	bool isAlive;
	bool isVisible;
	
	std::vector<float> position;
	std::vector<float> velocity;
	std::vector<float> accellaration;
	
	void ReadInformation(int Player);
};



#endif /* defined(__MemoryAimbot__Player__) */
