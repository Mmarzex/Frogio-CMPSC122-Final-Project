//
//  Game.h
//  template
//
//  Created by Max Marze on 3/4/13.
//
//

#ifndef __template__Game__
#define __template__Game__

#include "agk.h"
#include "GlobalHeaders.h"

/// DEFINITIONS

class Game
{
public:
    void SetLevelMusic(int musicId);
    void BeginGame();
    void CreateGame();
    void GameLoop();
    void DestroyGame();
    void SaveHighScore();
private:
    bool titleState;
    bool levelCreateState;
    int levelOn;
    
    int playerGameOverMusic;
    
    //TitleScreen title;
    Player playerOne;
    Enemy enemyOne;
    Level newLevel;

};

#endif /* defined(__template__Game__) */
