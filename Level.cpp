//
//  Level.cpp
//  template
//
//  Created by Max Marze on 3/3/13.
//
//

#include "Level.h"
#include <iostream>
#include <fstream>
using namespace std;

// LEVEL FILE NAMES
#define LEVEL_ONE "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/levelOne.txt"
#define LEVEL_TWO ""
#define LEVEL_THREE ""
#define LEVEL_FOUR ""
#define LEVEL_FIVE ""

/// NOT ACTUALLY LEVEL JUST END WITH SCORE AND CREDITS
#define LEVEL_SIX ""
#define GAME_OVER ""

void Level::CreateLevel(int level)
{
    switch (level) {
        case 1:
            CreateNextLevel(LEVEL_ONE);
            break;
        case 2:
            CreateNextLevel(LEVEL_TWO);
            break;
        case 3:
            CreateNextLevel(LEVEL_THREE);
            break;
        case 4:
            CreateNextLevel(LEVEL_FOUR);
            break;
        case 5:
            CreateNextLevel(LEVEL_FIVE);
            break;
        default:
            CreateNextLevel(GAME_OVER);
            break;
    }
}


///// NEED TO IMPLEMENT TILES FOR EACH DIFFERENT LEVEL
///// POSSIBLE ARRAY OF STRINGS OF FILEPATHS FOR EACH LEVEL
///// SWITCH STATEMENT TO PICK WHICH ONES TO LOAD WITH LoadTiles
void Level::LoadTiles()
{
    int i = 0;
    // DEBUG ///////
    tileIds[i] = agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/air.png");
    cout << i << endl;
    i++;
    tileIds[i] = agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/grass.png");
    cout << i << endl;
    tileNumber = i;
    cout << endl << endl;
}

void Level::LoadTileMap(const string& filename)
{
    fstream mapFile(filename.c_str());
    for(int r = 0; r < MAX_TILES; r++)
    {
        for(int c = 0; c < MAX_TILES; c++)
        {
            int temp = 0;
            if(!mapFile.eof())
            {
                mapFile >> temp;
                tileMap[r][c] = tileIds[temp];
            } else
            {
                tileMap[r][c] = tileIds[0];
            }
        }
    }
}

void Level::DrawTiles()
{
    cout << tileIds[0] << endl;
    cout << tileIds[1] << endl;
    float height = 100.f;
    float width = 100.f;
    int i = 0;
    for(int r = 0; r < MAX_TILES; r++)
    {
        for(int c = 0; c < MAX_TILES; c++)
        {
            tileSprites[i] = agk::CreateSprite(tileMap[r][c]);
            agk::SetSpriteScale(tileSprites[i], 2.f, 2.f);
            agk::SetSpritePhysicsOn(tileSprites[i]);
            agk::SetSpritePosition(tileSprites[i], width, height);
            width += (16.f * SCALE);
            i++;
        }
        height += (16.f * SCALE);
        width = 100.f;
    }
}

///// CALLED AT START
///// CALLED WHEN END OF LEVEL IS REACHED TO PROGRESS TO NEXT LEVEL
void Level::CreateNextLevel(const string& levelName)
{
    LoadTiles();
    LoadTileMap(levelName);
    DrawTiles();
}
