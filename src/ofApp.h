#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxAutoReloadedShader.h"

#define PORT 12345
#define NUM_MSG_STRINGS 20

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxOscReceiver receiver;
        int posX, posY;
        int windowX, windowY;
    
        ofImage manhattanMap;
    
        ofEasyCam cam;
    
        //shader
        ofxAutoReloadedShader autoShader;
        bool drawWireframe;
        ofPlanePrimitive plane;
};
