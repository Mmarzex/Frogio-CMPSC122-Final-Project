//
//  Player.cpp
//  template
//
//  Created by Max Marze on 2/26/13.
//
//

#include "Player.h"
#include <iostream>
#include <fstream>
//using std::ofstream;
//using std::cout;
//using std::endl;

//#define PLAYERSTARTHEIGHT 535.911f
#define PLAYERSTARTHEIGHT 368.f

Player::Player()
{
    playerState = 0;
    playerScore = 0;
    playerLivesLeft = 3;
    
}

void Player::CreatePlayer(int id)
{
    playerID = id;
    agk::CreateSprite(playerID, agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/ship_one.png"));
    agk::SetSpritePosition(playerID, 16.f, PLAYERSTARTHEIGHT);
    agk::SetSpriteScale(playerID, 2.f, 2.f);
    agk::SetSpritePhysicsOn(playerID);
    agk::SetSpritePhysicsCanRotate(playerID, 0);
    midScreenWid = agk::GetVirtualWidth() / 2.0f;
    playerWid = agk::GetSpriteWidth(playerID) / 2.0f;
    playerOffset = midScreenWid + playerWid;
    totalPlayerScore = 20000;
    //// DEBUG
    std::cout << "Player mass:" << agk::GetSpritePhysicsMass(playerID) << std::endl << std::endl;
    std::cout << "Player lives: " << playerLivesLeft << std::endl << std::endl;
}

void Player::SetPlayerName(string name)
{
    playerName = name;
}

int Player::GetID() const
{
    return playerID;
}

int Player::GetLives() const
{
    return playerLivesLeft;
}

void Player::DecreaseLives()
{
    playerLivesLeft--;
}

void Player::DisplayScore()
{
    agk::PrintC("Total Score: ");
    agk::Print(totalPlayerScore);
    agk::PrintC("Level Score: ");
    agk::Print(playerScore);
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
    float jumpSpeed = 75000.f;
    float x = agk::GetSpriteX(playerID);
    float y = agk::GetSpriteY(playerID);
    
    // update based on changes since last frame
    float mathStuff = x - playerOffset;
    float mathStuffH = y - playerOffset;
    //agk::SetViewOffset(mathStuff, 0);
    agk::SetViewOffset(mathStuff, mathStuffH);
    
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
        
    }
}

void Player::LevelEndPlayer()
{
    totalPlayerScore += playerScore;
    playerScore = 0;
    agk::DeleteSprite(playerID);
}

bool Player::LifeCheck()
{
    if(playerLivesLeft == 0)
        return true;
    else
        return false;
}

void Player::ScoresToFile()
{
    std::ofstream outfile ("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/leaderboard.txt", std::ios_base::app);
    outfile << "Score: " << totalPlayerScore;
    outfile << " of Player, " << playerName << std::endl;
    outfile.close();
}




