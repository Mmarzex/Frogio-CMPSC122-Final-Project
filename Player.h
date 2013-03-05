//
//  Player.h
//  template
//
//  Created by Max Marze on 2/26/13.
//
//

#ifndef __template__Player__
#define __template__Player__

#include "agk.h"

class Player
{
public:
    void CreatePlayer(int id);
    int GetID();
    void RespawnPlayer();
    void CheckKeyState();
    void CheckKeyRelease();
    void MovePlayer();
private:
    int playerID;
};

#endif /* defined(__template__Player__) */
