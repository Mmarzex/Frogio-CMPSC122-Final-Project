//
//  Player.cpp
//  template
//
//  Created by Max Marze on 2/26/13.
//
//

#include "Player.h"
#include <iostream>

//#define PLAYERSTARTHEIGHT 535.911f
#define PLAYERSTARTHEIGHT 264.f


void Player::CreatePlayer(int id)
{
    playerID = id;
    agk::CreateSprite(playerID, agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/ship_one.png"));
    agk::SetSpritePosition(playerID, 16.f, PLAYERSTARTHEIGHT);
    agk::SetSpriteScale(playerID, 2.f, 2.f);
    agk::SetSpritePhysicsOn(playerID);
    agk::SetSpritePhysicsCanRotate(playerID, 0);
    playerState = 0;
    playerScore = 0;
    playerLivesLeft = 3;
    midScreen = agk::GetVirtualWidth() / 2.f;
    playerWid = agk::GetSpriteWidth(playerID) / 2.f;
    playerOffset = midScreen + playerWid;
    
    //// DEBUG
    std::cout << "Player mass:" << agk::GetSpritePhysicsMass(playerID) << std::endl << std::endl;
}

int Player::GetID() const
{
    return playerID;
}

void Player::PowerUpPlayer()
{
    playerState = 1;
    
    /// Recreate sprite with appropriate state
}

void Player::RespawnPlayer()
{
    agk::DeleteSprite(1);
    int initialTime = agk::GetSeconds();
    agk::Print("YOU LOST!");
    CreatePlayer(playerID);
}

void Player::CheckKeyState()
{
    float mathStuff;
    float speed = 1000.f;
    float x = agk::GetSpriteX(playerID);
    float y = agk::GetSpriteY(playerID);
    if(agk::GetRawKeyState(65) == 1)
    {
        //float speed = 100.f;
        //float x = agk::GetSpriteX(playerID);
        //float y = agk::GetSpriteY(playerID);
        //agk::SetSpritePosition(1, x + (-1* speed), y);
        //agk::SetSpritePhysicsVelocity(playerID, (speed * -2), 0);
        agk::SetSpritePhysicsImpulse(playerID, x, y, x -speed, y);
        //float mathStuff = agk::GetSpriteX(playerID) - (agk::GetVirtualWidth() / 2) + (agk::GetSpriteWidth(playerID) / 2);
        mathStuff = agk::GetSpriteX(playerID) - playerOffset;
        agk::SetViewOffset(mathStuff, 0);
        std::cout << "Player X, pressing left: " << agk::GetSpriteX(playerID) << std::endl;
    } else if(agk::GetRawKeyState(68) == 1)
    {
        //float x = agk::GetSpriteX(playerID);
        //float y = agk::GetSpriteY(playerID);
        //agk::SetSpritePosition(1, x + speed, y);
        //agk::SetSpritePhysicsVelocity(PLAYER, speed, 0);
        //agk::SetSpritePhysicsForce(1, x, y, speed, 0);
        //agk::SetSpritePhysicsVelocity(playerID, speed*2, 0);
        //agk::SetSpritePhysicsImpulse(playerID, x, y, speed * 4, 0);
        agk::SetSpritePhysicsImpulse(playerID, x, y, x + speed, y);
        //agk::SetViewOffset(agk::GetSpriteX(playerID), 0);
        //float mathStuff = agk::GetSpriteX(playerID) - (agk::GetVirtualWidth() / 2) +(agk::GetSpriteWidth(playerID) / 2);
        mathStuff = agk::GetSpriteX(playerID) - playerOffset;
        agk::SetViewOffset(mathStuff, 0);
        //agk::SetViewOffset(agk::GetWorldXFromSprite(playerID, agk::GetSpriteX(playerID), agk::GetSpriteY(playerID)), 0);
        //agk::Sync();
        std::cout << "Player X, pressing right: " << agk::GetSpriteX(playerID) << std::endl;
        //std::cout << "Player X Velocity: " << agk::GetSpritePhysicsVelocityX(playerID) << std::endl << std::endl;
    }
    if(agk::GetRawKeyState(83) == 1)
    {
        //float x = agk::GetSpriteX(playerID);
        //float y = agk::GetSpriteY(playerID);
        //agk::SetSpritePosition(1, x, y + speed);
        agk::Print("Down");
    }
    if(agk::GetRawKeyPressed(87) == 1)
    {
        //float x = agk::GetSpriteX(playerID);
        //float y = agk::GetSpriteY(playerID);
        //agk::SetSpritePosition(1, x, y + (-1 * speed));
        //agk::SetSpritePhysicsImpulse(playerID, x, y, 10, -10000);
        agk::SetSpritePhysicsImpulse(playerID, x, y, x, y - 15000.f);
        //agk::SetSpritePhysicsVelocity(playerID, 0, speed * -2);
        
    }
    //std::cout << "x = " << x << " , y = " << y << std::endl;
}

void Player::CheckKeyRelease()
{
    if(agk::GetRawKeyReleased(65) == 1)
    {
        agk::SetSpritePhysicsVelocity(playerID, 0, 0);
    }
    if(agk::GetRawKeyReleased(68) == 1)
    {
        //float x = agk::GetSpriteX(playerID);
        //float y = agk::GetSpriteY(playerID);
        agk::SetSpritePhysicsVelocity(playerID, 0, 0);
    }
    if(agk::GetRawKeyReleased(87) == 1)
    {
        agk::SetSpritePhysicsVelocity(playerID, 0, 0);
    }
}

void Player::MovePlayer()
{
    CheckKeyState();
    CheckKeyRelease();
    
    if(agk::GetSpriteCollision(playerID, 11) == 1)
    {
        //float x = agk::GetSpriteX(playerID);
        //float y = agk::GetSpriteY(playerID);
        //agk::SetSpritePosition(PLAYER, x - speed, y - speed);
        RespawnPlayer();
        
    }
}
