#pragma once

#include "ofMain.h"
#include "ofxFaceTracker2.h"
#include "ofxDelaunay.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofImage imgA;
    ofImage imgB;
    ofImage imgC;
    
    // 3 serate trackers
    ofxFaceTracker2 tracker;
    
    // delauny
    ofxDelaunay delauny;
    
    // store the face points
    vector < ofPoint > imgApts;
    vector < ofPoint > imgBpts;
    
    
    ofMesh baseMesh;
    
    
    
};
