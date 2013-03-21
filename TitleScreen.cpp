//
//  TitleScreen.cpp
//  Frogio
//
//  Created by Max Marze on 3/13/13.
//
//

#include "TitleScreen.h"


void TitleScreen::DrawScreen()
{
    screenId = agk::CreateSprite(agk::LoadImage("/Users/maxmarze/Documents/AGK_BETA/AGK/IDE/templates/template_mac_xcode4/title_screen_proto.png"));
    std::cout << "Virtual Height: " << agk::GetVirtualHeight() << std::endl;
    std::cout << "Virtual Width: " << agk::GetVirtualWidth() << std::endl;
    hasStarted = false;
}

bool TitleScreen::CheckInput()
{
    if(agk::GetRawKeyPressed(13) == 1)
    {
        agk::Print("Enter was pressed");
        hasStarted = true;
        return true;
    } else
    {
        hasStarted = false;
        return false;
    }
}

void TitleScreen::DeleteScreen()
{
    agk::DeleteSprite(screenId);
    agk::ClearScreen();
}