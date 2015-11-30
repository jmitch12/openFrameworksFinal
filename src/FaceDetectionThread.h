//
//  FaceDetectionThread.hpp
//  06_openCVaddon
//
//  Created by Jane Mitchell on 11/24/15.
//
//

#pragma once

#include <stdio.h>
#include <ofMain.h>

class FaceDetectionThread : public ofThread {
public:
    FaceDetectionThread();
    ~FaceDetectionThread();
    void threadedFunction();
    int counter;



};



