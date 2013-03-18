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
private:
    bool titleState;
};

#endif /* defined(__template__Game__) */
