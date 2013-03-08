//
//  Game.cpp
//  template
//
//  Created by Max Marze on 3/4/13.
//
//

#include "Game.h"

#define PLAYER  1

Player playerOne;
Enemy enemyOne;

void Game::CreateGame()
{
    //agk::SetVirtualResolution ( m_DeviceWidth, m_DeviceHeight );
    agk::SetVirtualResolution(800, 600);
    agk::CreateSprite(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/background1.jpg"));
    agk::SetPhysicsGravity(0, 150.f);
    agk::SetPhysicsWallBottom(1);
    agk::LoadImage(1, "ship_one.png");
    agk::LoadMusic(1, "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/Maxs game.mp3");
    playerOne.CreatePlayer(PLAYER);
    Level newLevel;
    newLevel.CreateLevel(1);
    //agk::LoadMusic(1, "/Users/maxmarze/sandbox/AGK/IDE/templates/template_mac_xcode4/music.mp3");
    //agk::SetMusicFileVolume(1, 75);
    //agk::PlayMusic(1, 1);
    //agk::SetMusicFileVolume(2, 75);
    //agk::PlayMusic(2, 1, 2, 2);
    //playerOne.CreatePlayer(PLAYER);
    //enemyOne.SpawnEnemies();
    agk::LoadImage(2, "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/Enemy_one.png");
    agk::CreateSprite(11, 2);
    agk::SetSpriteScale(11, 2.f, 2.f);
    agk::SetSpritePosition(11, 200.f, 200.f);
    //newLevel.LoadTiles();
    //newLevel.LoadTileMap();
    //newLevel.DrawTiles();
}

void Game::GameLoop()
{
    agk::Print("Prototype 0.0001");
    agk::Print("Changed to AGK");
    
    /// ALSO DOESN'T WORK MUST TRY BETA ////
    /*if(agk::GetMusicPlaying() == 0)
    {
        //agk::SetMusicFileVolume(1, 100);
        agk::PlayMusic(1);
    }*/
    /*if(agk::GetMusicPlaying() == 1)
     {
     std::cout << "Music is playing at time: " << agk::GetSeconds() << std::endl;
     } */
    
    // Tried didn't work
    /*if(agk::GetMusicPlaying() == 0)
     {
     agk::PlayMusic(2);
     } */
    playerOne.MovePlayer();
    enemyOne.MoveEnemy(playerOne);
    /*if(enemyOne.GetEnemySpawnTime() + 10 < agk::GetSeconds())
    {
        enemyOne.MoveEnemy(playerOne);
        enemyOne.SetEnemySpawnTime();
    }*/
    enemyOne.CheckCollision(playerOne);
    agk::Sync();
}

void Game::DestroyGame()
{
    
}