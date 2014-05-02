//
//  Aimbot.cpp
//  MemoryAimbot
//
//  Created by Rahim Mitha on 2014-05-02.
//  Copyright (c) 2014 Rahim Mitha. All rights reserved.
//

#include "Aimbot.h"

void Esp_Aimbot()
{
	PlayerDataVec playerVec = GetPlayerVec();
	int enemyCount = 0;
	
	PlayerDataVec enemiesVec[MAXPLAYERS];
	PlayerDataVec viableEnemiesVec[MAXPLAYERS];
	
	if(playerVec.isInGame > 0) {
		
        for (int i = 0; i < MAXPLAYERS; i++) {
			PlayerDataVec enemyVec;
			ReadProcessMemory(HProcHandle, (PVOID)(0x839270 + i * 0x4CC),&enemyVec.isValid,4,NULL);
			ReadProcessMemory(HProcHandle, (PVOID)(0x84F2D8 + i * 0x1DC + 0x1C0),&enemyVec.isAlive,4,NULL);
			ReadProcessMemory(HProcHandle, (PVOID)(0x84F2D8 + i * 0x1DC + 0xCC),&enemyVec.clientNum,4,NULL);
			
            for (int x = 0; x < 16; x++) {
                ReadProcessMemory(HProcHandle, (PVOID)(0x839270 + i * 0x4CC + (0xC + x)),&enemyVec.name[x], 1,NULL);
			}
			ReadProcessMemory(HProcHandle, (PVOID)(0x839270 + i * 0x4CC + 0x1C),&enemyVec.team,4,NULL);
			ReadProcessMemory(HProcHandle, (PVOID)(0x12886A0 + i * 0x274),&enemyVec.health,4,NULL);
			
			if (enemyVec.isValid == 1 && enemyVec.clientNum != playerVec.clientNum) {
                if (enemyVec.team == playerVec.team)
                    enemyVec.color = Friendly;
                else
					enemyVec.color = Enemy;
				
				ReadProcessMemory(HProcHandle, (PVOID)(0x839270 + i * 0x4CC + 0x398),&enemyVec.xPos,4,NULL);
				ReadProcessMemory(HProcHandle, (PVOID)(0x839270 + i * 0x4CC + 0x39C),&enemyVec.yPos,4,NULL);
				ReadProcessMemory(HProcHandle, (PVOID)(0x839270 + i * 0x4CC + 0x3A0),&enemyVec.zPos,4,NULL);
				ReadProcessMemory(HProcHandle, (PVOID)(0x839270 + i * 0x4CC + 0x470),&enemyVec.pose,4,NULL);
				
                enemiesVec[enemyCount] = enemyVec;
				enemyCount++;
            }
		}
		
		playerVec = GetPlayerVec();
        float dist;
        float drawx;
        float drawy;
		
        for (int i = 0; i < enemyCount; i++)
        {
			dist = SubVectorDist(playerVec, enemiesVec[i]).length() / 48;
			if (WorldToScreen(enemiesVec[i].VecCoords(), playerVec.VecCoords()))
            {
                enemiesVec[i].visible = true;
				
                if ((((enemiesVec[i].pose & 0x08) != 0)) ||
                    ((enemiesVec[i].pose & 0x100) != 0) ||
                    ((enemiesVec[i].pose & 0x200) != 0))
                {
                    drawx = 700.0f / dist;
                    drawy = 400.0f / dist;
                    ScreenY += 4.6f;
                }
                else
                {
                    drawx = 400.0f / dist;
                    drawy = 700.0f / dist;
                }
			}
			
			int validPlayerCounter = 0;
			PlayerDataVec validAimbotEnemies[MAXPLAYERS];
			for (int i = 0; i < enemyCount; i++)
			{
				if (enemiesVec[i].team != playerVec.team)
				{
					validAimbotEnemies[validPlayerCounter] = enemiesVec[i];
					if(FocusTarget == validPlayerCounter)
					{
						if(validAimbotEnemies[validPlayerCounter].health < 1)
							FocusTarget = -1;
					}
					validPlayerCounter++;
				}
			}
			
			//Currently its RIGHT MOUSE KEY 0x02
			if (GetAsyncKeyState(0x02))
			{
				int target = 0;
				if (FocusTarget != -1)
				{
					if (validAimbotEnemies[FocusTarget].health > 0)
						target = FocusTarget;
					else target = FindClosestEnemyIndex(validAimbotEnemies, validPlayerCounter, playerVec);
				}
				else
					target = FindClosestEnemyIndex(validAimbotEnemies, validPlayerCounter, playerVec);
				
				if (target != -1)
				{
					dist = SubVectorDist(playerVec, validAimbotEnemies[target]).length() / 48;
					WorldToScreen(validAimbotEnemies[target].VecCoords(), playerVec.VecCoords());
					FocusTarget = target;
					if ((((validAimbotEnemies[target].pose & 0x08) != 0)) ||
						((validAimbotEnemies[target].pose & 0x100) != 0) ||
						((validAimbotEnemies[target].pose & 0x200) != 0))
					{
						drawx = 700.0f / dist;
						drawy = 400.0f / dist;
						ScreenY += 4.6f;
					}
					else
					{
						drawx = 400.0f / dist;
						drawy = 700.0f / dist;
					}
					
					int x = (int)(ScreenX);
					int y = (int)(ScreenY - drawy);
					
					if (validAimbotEnemies[target].health > 0)
					{
						GetWindowRect(Handle, &WindowRect);
						SetCursorPos((WindowRect.left)  + x, (WindowRect.top) + y);
					}
				}
			}
			else
				FocusTarget = -1;
		}
	}
}