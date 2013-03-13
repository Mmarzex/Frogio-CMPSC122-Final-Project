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
    //tileIds[i] = agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/air.png");
    //cout << i << endl;
    tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/air.png"));
    i++;
    //tileIds[i] = agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/dirt_resize.png");
    tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/dirt_resize.png"));
    i++;
    //tileIds[i] = agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/grass_top_resize.png");
    tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/grass_top_resize.png"));
    //cout << i << endl;
    tileNumber = i;
    //cout << endl << endl;
}

void Level::LoadTileMap(const string& filename)
{
    fstream mapFile(filename.c_str());
    for(int r = 0; r < MAX_TILES; r++)
    {
        vector<int>* newVector = new vector<int>;
        for(int c = 0; c < MAX_TILES; c++)
        {
            int temp = 0;
            if(!mapFile.eof())
            {
                mapFile >> temp;
                newVector->push_back(tileIds[temp]);
                //tileMap[r][c] = tileIds[temp];
            } else
            {
                newVector->push_back(tileIds[0]);
                //tileMap[r][c] = tileIds[0];
            }
        }
        tileMap.push_back(*newVector);
    }
}

void Level::DrawTiles()
{
    cout << tileIds[0] << endl;
    cout << tileIds[1] << endl;
    float height = 400.f;
    //float height = 0.f;
    float width = 0.f;
    //int i = 0;
    numOfTileSprites = 0;
    for(int r = 0; r < MAX_TILES; r++)
    {
        for(int c = 0; c < MAX_TILES; c++)
        {
            if(tileMap[r][c] != tileIds[0])
            {
                //tileSprites[numOfTileSprites] = agk::CreateSprite(tileMap[r][c]);
                tileSprites.push_back(agk::CreateSprite(tileMap[r][c]));
                agk::SetSpriteScale(tileSprites[numOfTileSprites], SCALE, SCALE);
                agk::SetSpritePhysicsOn(tileSprites[numOfTileSprites], 1);
                //agk::SetSpriteGroup(tileSprites[numOfTileSprites], 1);
                //agk::SetSpritePhysicsMass(tileSprites[numOfTileSprites], 100.f);
                //agk::FixSpriteToScreen(tileSprites[numOfTileSprites], 1);
                agk::SetSpritePosition(tileSprites[numOfTileSprites], width, height);
            }
            width += (16.f * SCALE);
            //i++;
            numOfTileSprites++;
        }
        height += (16.f * SCALE);
        width = 0.f;
    }
}

void Level::CheckCollision(const Player& player)
{
    for(int i = 0; i < numOfTileSprites; i++)
    {

    }
}

void Level::CheckCollision(const Enemy& enemy)
{
    for(int i = 0; i < numOfTileSprites; i++)
    {
        
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
