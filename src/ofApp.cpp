#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    receiver.setup(PORT);
    
    posX = 0;
    posY = 0;
    
    manhattanMap.loadImage("image/manhattanMap.png");
    autoShader.load("shaders/livecoding");
    autoShader.setMillisBetweenFileCheck(100);
    //drawWireframe = false;
    
    plane.set(200, 300, 10, 20);
    plane.mapTexCoordsFromTexture(manhattanMap.getTextureReference());
    
    autoShader.load("shaders/livecoding");
    autoShader.setMillisBetweenFileCheck(100);

}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        if(m.getAddress() == "/your/position"){
			// both the arguments are int32's
			posX = m.getArgAsInt32(0);
			posY = m.getArgAsInt32(1);
		}
		// check for mouse button message
        else if(m.getAddress() == "/your/window"){
		// the single argument is a string
			windowX = m.getArgAsInt32(0);
            windowY = m.getArgAsInt32(1);
		}
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    //ofPushMatrix();
    ofSetColor(255, 255, 255);
    //ofSetRectMode(OF_RECTMODE_CENTER);
    //manhattanMap.draw(0,0,0,windowX,windowY);
    ofCircle(posX-(windowX/2), -(posY-(windowY/2)),10, 10);//is there better way to adjust vertex?
    
    
    autoShader.begin();
    autoShader.setUniformTexture("tex0", manhattanMap.getTextureReference(),0);
    autoShader.setUniform2f("windowSize", ofGetWidth(), ofGetHeight());
//    autoShader.setUniform1f("posX", posX);
//    autoShader.setUniform1f("posY", posY);
    //ofPopMatrix();
//    
//    if(drawWireframe){
//        plane.drawWireframe();
//        plane.draw();
//    }
    
    cam.end();
    autoShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'w') {
        drawWireframe ^= true;
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
