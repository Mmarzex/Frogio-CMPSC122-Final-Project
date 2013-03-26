// Includes, namespace and prototypes
#include "template.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"
#include "Game.h"

using namespace AGK;

app App;
Game myGame;
void AppForceExit ( void );

// Begin app, called once at the start
void app::Begin( void )
{
    agk::SetVirtualResolution ( m_DeviceWidth, m_DeviceHeight );
    myGame.CreateGame();
    myGame.BeginGame();
}

// Main loop, called every frame
void app::Loop ( void )
{
    myGame.GameLoop();
}

// Called when the app ends
void app::End ( void )
{
    myGame.DestroyGame();
}
