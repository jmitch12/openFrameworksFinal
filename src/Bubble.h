

#ifndef Bubble_h
#define Bubble_h

#pragma once
#include "ofMain.h"

class Bubble {
public:
    Bubble();
    
    int x, y, xVel, yVel;
    ofColor color;
    float bubbleSize;
    
    void setup(int _x, int _y);
    void update();
    void draw();
};

#endif /* Bubble_h */
