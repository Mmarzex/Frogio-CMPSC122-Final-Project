//
//  Shot.h
//  template
//
//  Created by Max Marze on 3/4/13.
//
//

#ifndef __template__Shot__
#define __template__Shot__

#include <iostream>
#include "agk.h"

class Shot
{
public:
    void CreateShot();
    void SpawnShot();
    void CheckShotCollision();
private:
    int shotId;
};

#endif /* defined(__template__Shot__) */
