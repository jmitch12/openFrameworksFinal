#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    vidGrabber.initGrabber(320,240);
    finder.setup("haarcascade_frontalface_default.xml");
    
    this->myThread = new FaceDetectionThread();
    
    for (int i=0; i<10; i++) {
        int temp = ofRandom(30);
        myNumbers.push_back(temp);
    }
    for (int i=0; i<10; i++) {
        Bubble tempBubble;
        tempBubble.setup(ofRandomWidth(), ofRandomHeight());
        myBubbles.push_back(tempBubble);
    }
    this->myThread->startThread();
}

//--------------------------------------------------------------
void ofApp::update(){

    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){
        finder.findHaarObjects(vidGrabber.getPixelsRef());
	}
    
    for (int i=0; i<myBubbles.size(); i++) {
        myBubbles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    vidGrabber.draw(0, 0, 1024,768);
	
    ofNoFill();
    ofSetColor(0,0,0);

	for(unsigned int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle face = finder.blobs[i].boundingRect;
		ofRect(face.x*3.4, face.y*3, face.width*2.8, face.height*3.4);
	}
    
    cout<< myBubbles.size() <<endl;
    for (int i=0; i<myBubbles.size(); i++) {
        myBubbles[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'a'){
        if( this->myThread->isThreadRunning()){
            this->myThread->stopThread();
        }else{
            this->myThread->startThread();
        }
    }
    if (myBubbles.size() > 0) {
        myBubbles.erase(myBubbles.begin());
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i=0; i<1; i++) {
        Bubble newBubble;
        newBubble.setup(x, y);
        myBubbles.push_back(newBubble);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
