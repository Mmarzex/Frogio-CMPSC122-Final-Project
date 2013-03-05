//
//  Enemy.cpp
//  template
//
//  Created by Max Marze on 2/27/13.
//
//

#include "Enemy.h"
#include <iostream>

#define PLAYER 1

void Enemy::CreateEnemy(int id)
{
    enemyID = id;
    //enemySpawnTime = agk::GetSeconds();
    enemySprites[id] = agk::CreateSprite(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/Snake_one.png"));
    agk::SetSpritePhysicsOn(enemySprites[id]);
    agk::SetSpriteScale(enemySprites[id], 2.f, 2.f);
    agk::SetSpritePhysicsCanRotate(enemySprites[id], 0);
    //agk::CreateSprite(enemyID, agk::LoadImage("/Users/maxmarze/sandbox/AGK/IDE/templates/template_mac_xcode4/Snake_one.png"));
    //agk::SetSpriteScale(1, 2.f, 2.f);
    //agk::SetSpritePhysicsOn(enemyID);
    //agk::SetSpritePhysicsCanRotate(enemyID, 0);
    numOfEnemySprites++;
}

void Enemy::SpawnEnemies()
{
    SetEnemySpawnTime();
    for (int i = 2; i < 11; i++) {
        CreateEnemy(i);
        agk::SetSpritePosition(enemySprites[i], 10.f * i, 10.f * i);
    }
}

void Enemy::MoveEnemy()
{
    for(int i = 2; i < numOfEnemySprites; i++)
    {
        agk::SetSpritePhysicsVelocity(enemySprites[i], 1000.f, 100.f);
    }
}

void Enemy::CheckCollision()
{
    for(int i = 2; i < 11; i++)
    {
        if(agk::GetPhysicsCollision(PLAYER, i) == 1)
            std::cout << "Enemy #" << i << " Collided with player" << std::endl;
    }
}

int Enemy::GetEnemySpawnTime()
{
    return enemySpawnTime;
}

void Enemy::SetEnemySpawnTime(int time)
{
    if(time == 0)
        enemySpawnTime = agk::GetSeconds();
    else
        enemySpawnTime = 0;
}