#include <stdio.h>

#include "Bubble.h"

ofSoundPlayer sound;

Bubble::Bubble() {
    x = ofGetWindowWidth() * 0.5;
    y = ofGetWindowHeight() * 0.5;
    xVel = ofRandom(-5,5);
    yVel = ofRandom(-5,5);
}

void Bubble::setup(int _x, int _y) {
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    ofSetFrameRate(60);
    
    x = _x;
    y = _y;
    bubbleSize = ofRandom(10,50);
    
    color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    
    sound.loadSound("sounds/Mario.mp3");
    
    
}

void Bubble::update() {
    x += xVel;
    y += yVel;
    
    if ((x > ofGetWindowWidth()) || (x < 0)) {
        xVel *= (-1);
        sound.play();
    }
    if ((y > ofGetWindowHeight()) || (y < 0)) {
        yVel *= (-1);
        sound.play();
    }
    
    //collision with rectangle
    
//    for (<#initialization#>; <#condition#>; <#increment#>) {
//        <#statements#>
//    }
    
    
}

void Bubble::draw() {
    ofSetColor(color);
    ofCircle(x, y, bubbleSize);
}