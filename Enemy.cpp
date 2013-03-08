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
#define ENEMY_START_HEIGHT 535.911f
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
    float k = 0.f;
    SetEnemySpawnTime();
    for (int i = 0; i < 4; i++) {
        CreateEnemy(i);
        agk::SetSpritePosition(enemySprites[i], 500.f + k, ENEMY_START_HEIGHT);
        k += 24.f;
    }
    std::cout << "Enemy mass: " << agk::GetSpritePhysicsMass(enemySprites[2]) << std::endl << std::endl;
}


/// DOESN'T WORK RIGHT ENTIRELY FIX!!!!
/////// USE agk::GetSpriteDistance()!!!!!!!!!!!!
void Enemy::MoveEnemy(const Player& player)
{
    /*for(int i = 2; i < numOfEnemySprites; i++)
    {
        agk::SetSpritePhysicsVelocity(enemySprites[i], 1000.f, 100.f);
    }*/
    float speed = 750.f;
    
    for(int i = 0; i < numOfEnemySprites; i++)
    {
        float x = agk::GetSpriteX(enemySprites[i]);
        float y = agk::GetSpriteY(enemySprites[i]);
        float playerEnemyXDifference = agk::GetSpriteX(enemySprites[i]) - agk::GetSpriteX(player.GetID());
        if(playerEnemyXDifference >= 100 && playerEnemyXDifference < 500)
        {
            //agk::SetSpritePhysicsVelocity(enemySprites[i], x - speed, y);
            agk::SetSpritePhysicsImpulse(enemySprites[i], x, y, x - speed, y);
        } else
        {
            agk::SetSpritePhysicsVelocity(enemySprites[i], 0, 0);
        }
    }
}

void Enemy::CheckCollision(const Player& player)
{
    
    /// Check for if collision from jump
    //// If Jump collision UpScore
    
    /// Check for if collision from running into
    ///// If run Call respawn player
    
    /// Check For collision from shot
    ///// If shot UpScore, Delete Enemy
    
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