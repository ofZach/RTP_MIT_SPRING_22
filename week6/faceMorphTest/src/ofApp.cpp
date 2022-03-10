#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    imgA.load("images/a.png");
    imgB.load("images/b.png");
    imgC.load("images/c.png");
    
    tracker.setup();
    tracker.setThreaded(false);
    tracker.update(imgC);
    
    vector < ofPoint > pts;
    for (int i = 0; i < tracker.getInstances()[0].getLandmarks().getImagePoints().size(); i++){
        pts.push_back(tracker.getInstances()[0].getLandmarks().getImagePoints()[i]);
    }
    
    for (int i = 0; i < pts.size(); i++){
        delauny.addPoint( pts[i] );
    }
//    delauny.addPoint(ofPoint(0,0));
//    delauny.addPoint(ofPoint(imgC.getWidth(),0));
//    delauny.addPoint(ofPoint(imgC.getWidth(),imgC.getHeight()));
//    delauny.addPoint(ofPoint(0,imgC.getHeight()));
    
    delauny.triangulate();
    
    // now get imgA and imgB pts;
    tracker.update(imgA);
    for (int i = 0; i < tracker.getInstances()[0].getLandmarks().getImagePoints().size(); i++){
        imgApts.push_back(tracker.getInstances()[0].getLandmarks().getImagePoints()[i]);
    }
    
    tracker.update(imgB);
    for (int i = 0; i < tracker.getInstances()[0].getLandmarks().getImagePoints().size(); i++){
        imgBpts.push_back(tracker.getInstances()[0].getLandmarks().getImagePoints()[i]);
    }
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
   // tracker.drawDebug();
   // delauny.triangleMesh.drawWireframe();
    
//    
//    // let's do imgA based on delauny
//    ofMesh meshA = delauny.triangleMesh;
//    for (int i = 0; i < meshA.getVertices().size(); i++){
//        // get the point for this index.
//        ofPoint pt = imgApts[i];
//        // set the texture coordinate
//        meshA.addTexCoord(imgA.getTexture().getCoordFromPoint(pt.x, pt.y));
//        meshA.getVertices()[i] =pt;
//    }
//    imgA.getTexture().bind();
//    meshA.draw();
//    imgA.getTexture().unbind();
    
    
    // let's mix the points
    float pct = ofMap(mouseX, 0, ofGetWidth(), 0, 1);
    vector < ofPoint > mixedPoints;
    for (int i = 0; i < imgApts.size(); i++){
        mixedPoints.push_back((1-pct)*imgApts[i] + (pct)*imgBpts[i]);
    }

    // now, let's make two meshes, one for imageA, one for imageB based on these points


    ofMesh meshA = delauny.triangleMesh;
    for (int i = 0; i < meshA.getVertices().size(); i++){
        // get the point for this index.
        ofPoint pt = imgApts[i];
        // set the texture coordinate
        meshA.addTexCoord(imgA.getTexture().getCoordFromPoint(pt.x, pt.y));
        meshA.getVertices()[i] =mixedPoints[i];
    }
    imgA.getTexture().bind();
    meshA.draw();
    imgA.getTexture().unbind();


    ofMesh meshB = delauny.triangleMesh;
    for (int i = 0; i < meshB.getVertices().size(); i++){
        // get the point for this index.
        ofPoint pt = imgBpts[i];
        // set the texture coordinate
        meshB.addTexCoord(imgB.getTexture().getCoordFromPoint(pt.x, pt.y));
        meshB.getVertices()[i] =mixedPoints[i];
    }
    ofSetColor(255,255,255,255*pct);
    imgB.getTexture().bind();
    meshB.draw();
    imgB.getTexture().unbind();

    ofSetColor(255);
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
