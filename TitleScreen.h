//
//  TitleScreen.h
//  Frogio
//
//  Created by Max Marze on 3/13/13.
//
//

#ifndef __Frogio__TitleScreen__
#define __Frogio__TitleScreen__

#include <iostream>
#include "agk.h"
#include "Game.h"

class TitleScreen
{
    
public:
    void DrawScreen();
    bool CheckInput();
    bool GetHasStarted() { return hasStarted; }
    void SetHasStarted() { hasStarted = false; }
    void DeleteScreen();
private:
    bool hasStarted;
    int screenId;
};

#endif /* defined(__Frogio__TitleScreen__) */
