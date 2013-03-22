//
//  Game.cpp
//  template
//
//  Created by Max Marze on 3/4/13.
//
//

#include "Game.h"
#include "TitleScreen.h"

#define PLAYER  1
#define NUM_OF_LEVELS 6

TitleScreen title;
Player playerOne;
Enemy enemyOne;
Level newLevel;

void Game::SetLevelMusic(int musicId)
{
    switch (musicId) {
        case 1:
            agk::LoadMusic(1, "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/Maxs game.mp3");
            agk::SetMusicFileVolume(1, 75);
            agk::PlayMusic(1, 1);
            break;
            
        default:
            break;
    }
    
}

void Game::BeginGame()
{
}

void Game::CreateGame()
{
    
    title.DrawScreen();
    titleState = true;
    //agk::SetPhysicsGravity(0, 200.f);
    agk::SetPhysicsGravity(0, 1000.f);
}

void Game::GameLoop()
{
    agk::Print("Prototype 0.0001");
    agk::Print("Changed to AGK");
    if (titleState == true) {
        title.CheckInput();
    }
    int k;
    //title.CheckInput();
    if (title.GetHasStarted() == true) {
        title.SetHasStarted();
        titleState = false;
        levelCreateState = false;
        levelOn = 1;
        agk::SetClearColor(55, 255, 249);
        title.DeleteScreen();
        //agk::ClearScreen();
        agk::Sync();
        //k = agk::CreateSprite(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/background1.jpg"));
        //SetLevelMusic(1);
        playerOne.CreatePlayer(PLAYER);
        newLevel.CreateLevel(levelOn);
        agk::LoadImage(2, "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/Enemy_one.png");
        agk::CreateSprite(11, 2);
        agk::SetSpriteScale(11, 2.f, 2.f);
        agk::SetSpritePosition(11, 200.f, 200.f);
        
    }
    if(titleState == false)
    {
        playerOne.MovePlayer();
        if(newLevel.CheckForWin(playerOne) == true)
        {
            levelOn++;
            newLevel.CreateLevel(levelOn);
            playerOne.RespawnPlayer();
        }
        //playerOne.CheckPlayerScreenBounds(k);
        
    }
    agk::Sync();
}

void Game::DestroyGame()
{
    
}