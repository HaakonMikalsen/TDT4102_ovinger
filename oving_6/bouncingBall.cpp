#pragma once
#include "bouncingBall.h"

// BEGIN: 4b
map<int, Color> ball_color{{1, Color(9096682)}, {2, Color(10894656)}, {3, Color(11140524)}, {4, Color(16757114)}};
// END: 4b

// BEGIN: 4c
istream& operator>>(istream& is, Config& cfg) {
    string val;
    is >> val;
    cfg.color_up = stoi(val);

    is >> val;
    cfg.color_down = stoi(val);

    is >> val;
    cfg.velocity = stoi(val);
    return is;
}
// END: 4c

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800};
constexpr int BOUNCE_WINDOW_HEIGHT{500};

// FJERN DETTE NAAR DU BEGYNNER PÅ OPPGAVE 4e)
// #define BOUNCING_BALL
//

void bouncingBall() {
#ifndef BOUNCING_BALL
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y,
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};

    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color color_up{Color::blue};
    Color color_down{Color::blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};
    // const int r = 30;
    Color c = Color::blue;

    Config slow = {1, 1, 0};
    Config fast = {1, 1, 0};

    // read in the configurations
    filesystem::path file_name{"konfigurasjon.txt"};
    ifstream is{file_name};
    is >> slow >> fast;

    // initialise the run
    velocity = slow.velocity;
    color_up = ball_color.at(slow.color_up);
    color_down = ball_color.at(slow.color_down);

    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = velocity * cos(alpha);
        increment_y = velocity * sin(alpha);

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every second pass
            if (count_num_passes % 2 == 0) {
                if (velocity == slow.velocity) {
                    velocity = fast.velocity;
                    color_up = ball_color.at(fast.color_up);
                    color_down = ball_color.at(fast.color_down);
                } else {
                    velocity = slow.velocity;
                    color_up = ball_color.at(slow.color_up);
                    color_down = ball_color.at(slow.color_down);
                }
            }
        } else {
            // moving rightwards
            x += increment_x;
        }
        y += increment_y;
        if ((y+radius)>=window.height()){
            alpha*=-1;
            y = window.height()-radius;
            c = color_up;
        }
        if ((y-radius)<=0){
            alpha*=-1;
            y = radius;
            c = color_down;
        }

        window.draw_circle({x, y}, radius, c);

        // HINT 1: Ta en titt på koden ovenfor og se hvilke variabler som brukes.
        // Bruk disse variablene for å implementere bevegelsen til den sprettende ballen. For eksempel:
        // Variablene count_bounce_top og count_bounce_bottom kan brukes
        // for å holde styr på hvilken retning ballen skal gå.
        // Variabelen increment_y skal brukes for å øke y.

        // HINT 2: window.draw_circle({x, y}, r, c) tegner en sirkel med radius r,
        // sentrum i (x, y) og fargen c

        // BEGIN: 4d
        // movement in y-direction
        // END: 4d

        window.next_frame();
    }
#endif
}