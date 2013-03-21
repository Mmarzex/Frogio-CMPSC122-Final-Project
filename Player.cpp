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
    agk::CreateSprite(playerID, agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/ship_one.png"));
    agk::SetSpritePosition(playerID, 16.f, PLAYERSTARTHEIGHT);
    agk::SetSpriteScale(playerID, 2.f, 2.f);
    agk::SetSpritePhysicsOn(playerID);
    agk::SetSpritePhysicsCanRotate(playerID, 0);
    playerState = 0;
    playerScore = 0;
    playerLivesLeft = 3;
    midScreen = agk::GetVirtualWidth() / 2.0f;
    playerWid = agk::GetSpriteWidth(playerID) / 2.0f;
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
    agk::Print("YOU LOST!");
    CreatePlayer(playerID);
}

void Player::CheckKeyState()
{
    float speed = 10000.f;
    //float jumpSpeed = 15000.f;
    float jumpSpeed = 45000.f;
    float x = agk::GetSpriteX(playerID);
    float y = agk::GetSpriteY(playerID);
    
    // update based on changes since last frame
    float mathStuff = x - playerOffset;
    agk::SetViewOffset(mathStuff, 0);
    
    // check for movement keys
    if(agk::GetRawKeyState(65) == 1)
    {
        agk::SetSpritePhysicsImpulse(playerID, x, y, -speed, y);
    } else if(agk::GetRawKeyState(68) == 1)
    {
        agk::SetSpritePhysicsImpulse(playerID, x, y, speed, y);
    }
    
    if(agk::GetRawKeyPressed(87) == 1)
    {
        agk::SetSpritePhysicsImpulse(playerID, x, y, x, -jumpSpeed);
    }
}

void Player::CheckKeyRelease()
{
    if(agk::GetRawKeyReleased(65) == 1)
    {
        agk::SetSpritePhysicsVelocity(playerID, 0, 0);
    }
    if(agk::GetRawKeyReleased(68) == 1)
    {
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
        RespawnPlayer();
        
    }
}


/// data member to increase the width to check in order to move
void Player::CheckPlayerScreenBounds(int &bkg)
{
    if(agk::GetSpriteX(playerID) >= agk::GetVirtualWidth())
    {
        agk::DeleteSprite(bkg);
        bkg = agk::CreateSprite(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/background1.jpg"));
        agk::SetSpriteDepth(bkg, 10000);
    }
}
