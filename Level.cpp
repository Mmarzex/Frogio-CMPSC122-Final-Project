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
#define LEVEL_ONE "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/levelOne.txt"
#define LEVEL_TWO "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/levelTwo.txt"
#define LEVEL_THREE "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/levelOne.txt"
#define LEVEL_FOUR "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/levelTwo.txt"
#define LEVEL_FIVE "/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/levelOne.txt"

/// NOT ACTUALLY LEVEL JUST END WITH SCORE AND CREDITS
#define LEVEL_SIX ""
#define GAME_OVER ""

void Level::CreateLevel(int level)
{
    switch (level) {
        case 1:
            LoadTiles(1);
            CreateNextLevel(LEVEL_ONE);
            break;
        case 2:
            LoadTiles(2);
            CreateNextLevel(LEVEL_TWO);
            break;
        case 3:
            LoadTiles(3);
            CreateNextLevel(LEVEL_THREE);
            break;
        case 4:
            LoadTiles(4);
            CreateNextLevel(LEVEL_FOUR);
            break;
        case 5:
            LoadTiles(5);
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
void Level::LoadTiles(int level)
{
    int i = 0;
    switch (level) {
        case 1:
            // DEBUG ///////
            tileIds[i] = agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/air.png");
            //cout << i << endl;
            //tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/air.png"));
            i++;
            tileIds[i] = agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/dirt_resize.png");
            //tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/dirt_resize.png"));
            i++;
            tileIds[i] = agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/grass_top_resize.png");
            //tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/grass_top_resize.png"));
            //cout << i << endl;
            tileNumber = i;
            //cout << endl << endl;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
            
        default:
            break;
    }
}

/*void Level::LoadTiles()
{
    tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/air.png"));
    tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/dirt_resize.png"));
    tileIds.push_back(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/frogio/grass_top_resize.png"));
}


void Level::LoadTileMap(const string& filename)
{
    fstream mapFile(filename.c_str());
    string tempString = "";
    getline(mapFile, tempString);
    // MAKE DATA MEMBER
    columns = 0;
    for(int i = 0; i < tempString.size(); i++)
    {
        if(tempString[i] == ' ')
            columns++;
    }
    mapFile.close();
    mapFile.open(filename.c_str());
    for(int r = 0; r < columns; r++)
    {
        //vector<int> temp = new vector<int>;
        vector<int> newVector;
        //tileMap.push_back(newVector);
        for(int c = 0; c < columns; c++)
        {
            int temp = 0;
            if(!mapFile.eof())
            {
                mapFile >> temp;
                newVector.push_back(tileIds[temp]);
            } else
            {
                newVector.push_back(tileIds[0]);
            }
        }
        tileMap.push_back(newVector);
        newVector.clear();
    }
}*/

void Level::LoadTileMap(const string& filename)
{
    fstream mapFile2(filename.c_str());
    string tempString = "";
    getline(mapFile2, tempString);
    // MAKE DATA MEMBER
    columns = 0;
    for(int i = 0; i < tempString.size(); i++)
    {
        if(tempString[i] == ' ')
            columns++;
    }
    columns++;
    cout << "Number of tiles in a row: " << columns << endl;
    fstream mapFile(filename.c_str());
    for(int r = 0; r < columns; r++)
    {
        //vector<int>* newVector = new vector<int>;
        for(int c = 0; c < columns; c++)
        {
            int temp = 0;
            if(!mapFile.eof())
            {
                mapFile >> temp;
                //newVector->push_back(tileIds[temp]);
                tileMap[r][c] = tileIds[temp];
            } else
            {
                //newVector->push_back(tileIds[0]);
                tileMap[r][c] = tileIds[0];
            }
        }
        //tileMap.push_back(*newVector);
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
    for(int r = 0; r < columns; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            if(tileMap[r][c] != tileIds[0])
            {
                tileSprites[numOfTileSprites] = agk::CreateSprite(tileMap[r][c]);
                //tileSprites.push_back(agk::CreateSprite(tileMap[r][c]));
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
        //cout << "Height: " << height << endl;
        maxWidth = width - (16.f * SCALE);
        height += (16.f * SCALE);
        width = 0.f;
    }
}

/*void Level::DrawTiles()
{
    float height = 400.f;
    float width = 0.f;
    // Data Member
    numOfTileSprites = 0;
    for(int r = 0; r < columns; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            if(tileMap[r][c] != tileIds[0])
            {
                tileSprites.push_back(agk::CreateSprite(tileMap[r][c]));
                agk::SetSpriteScale(tileSprites[numOfTileSprites], SCALE, SCALE);
                agk::SetSpritePhysicsOn(tileSprites[numOfTileSprites], 1);
                agk::SetSpritePosition(tileSprites[numOfTileSprites], width, height);
            }
            width += (16.f * SCALE);
            numOfTileSprites++;
        }
        height += (16.f * SCALE);
        width = 0.f;
    }
}*/

void Level::DeleteTiles()
{
    for(int i = 0; i < numOfTileSprites; i++)
    {
        agk::DeleteSprite(tileSprites[i]);
    }
}

bool Level::CheckForWin(Player& player)
{
    if(agk::GetSpriteX(player.GetID()) >= maxWidth)
    {
        agk::Print("You reached the end of the level!");
        agk::ClearScreen();
        player.LevelEndPlayer();
        DeleteTiles();
        return true;
    } else
    {
        return false;
    }
}

///// CALLED AT START
///// CALLED WHEN END OF LEVEL IS REACHED TO PROGRESS TO NEXT LEVEL
void Level::CreateNextLevel(const string& levelName)
{
    //LoadTiles();
    LoadTileMap(levelName);
    DrawTiles();
}
