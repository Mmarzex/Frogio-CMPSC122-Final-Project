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
#include <string>
using std::string;

class Player
{
public:
    Player();
    void CreatePlayer(int id);
    void SetPlayerName(string name);
    int GetID() const;
    int GetLives() const;
    void DecreaseLives();
    void DisplayScore();
    void PowerUpPlayer();
    void RespawnPlayer();
    void CheckKeyState();
    void CheckKeyRelease();
    void MovePlayer();
    void CheckPlayerScreenBounds(int &bkg);
    void LevelEndPlayer();
    bool LifeCheck();
    void ScoresToFile();
    //void CheckCollision(const Enemy& enemy);
private:
    int playerID;
    
    string playerName;
    
    /// For if poweredUp or not
    /// 0 by default
    int playerState;
    
    /// Player Score
    int playerScore;
    
    /// Player Lives
    /// 3 By default
    int playerLivesLeft;
    
    int totalPlayerScore;
    
    int playerGameOverMusic;
    
    float midScreenWid;
    float midScreenH;
    float playerH;
    float playerWid;
    float playerOffset;
};

#endif /* defined(__template__Player__) */
