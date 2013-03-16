//
//  Level.h
//  template
//
//  Created by Max Marze on 3/3/13.
//
//

#ifndef __template__Level__
#define __template__Level__

#include <vector>
#include <string>
#include "agk.h"

#include "Player.h"
#include "Enemy.h"
using std::vector;
using std::string;

// Max tiles that can be used with any drawn level
// Max Sprites that can be used by any drawn level
#define MAX_TILES 46
#define MAX_SPRITES 1000

// Scale for all Sprites
#define SCALE 4.f


class Level
{
public:
    void CreateLevel(int level);
    void LoadTiles();
    void LoadTileMap(const string& filename);
    void DrawTiles();
    void CheckCollision(const Player& player);
    void CheckCollision(const Enemy& enemy);
    void CreateNextLevel(const string& levelName);
private:
    int levelId;
    int tileIds[MAX_TILES];
    int tileSprites[MAX_SPRITES];
    int tileMap[MAX_TILES][MAX_TILES];
    /*vector<int> tileIds;
    vector<int> tileSprites;
    vector<vector<int> > tileMap;*/
    int tileNumber;
    int numOfTileSprites;
};
#endif /* defined(__template__Level__) */
