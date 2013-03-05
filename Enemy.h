//
//  Enemy.h
//  template
//
//  Created by Max Marze on 2/27/13.
//
//

#ifndef __template__Enemy__
#define __template__Enemy__

#include "agk.h"

#define ENEMY_SPRITES 100

class Enemy
{
public:
    void CreateEnemy(int id);
    void SpawnEnemies();
    int GetID();
    void MoveEnemy();
    void CheckCollision();
    void SetEnemySpawnTime(int time = 0);
    int GetEnemySpawnTime();
    
    
private:
    int enemyID;
    int enemySprites[ENEMY_SPRITES];
    int numOfEnemySprites;
    int enemySpawnTime;
};

#endif /* defined(__template__Enemy__) */
