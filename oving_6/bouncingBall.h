#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

struct Config{ 
    // BEGIN: 4a
    public:
        int color_up;
        int color_down;
        int velocity;
    // END: 4a
};

extern map<int, Color> ball_color;

istream& operator>>(istream& is, Config& cfg);

void bouncingBall();
