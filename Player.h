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
    int GetID() const;
    void PowerUpPlayer();
    void RespawnPlayer();
    void CheckKeyState();
    void CheckKeyRelease();
    void MovePlayer();
    void CheckPlayerScreenBounds(int &bkg);
    void LevelEndPlayer();
    //void CheckCollision(const Enemy& enemy);
private:
    int playerID;
    
    /// For if poweredUp or not
    /// 0 by default
    int playerState;
    
    /// Player Score
    int playerScore;
    
    /// Player Lives
    /// 3 By default
    int playerLivesLeft;
    
    int totalPlayerScore;
    
    float midScreen;
    float playerWid;
    float playerOffset;
};

#endif /* defined(__template__Player__) */
