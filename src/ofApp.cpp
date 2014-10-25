//
//  ofApp.cpp
//  2d Pixel to Voxel Matrix
//
//  Created by Daniel Mastretta 10/2014.
//
//

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

ofSetVerticalSync(true);
ofSetFrameRate(60);
ofSetColor(100,75,200);
front.loadImage("images/link.png");

int w = front.getWidth();
int h = front.getHeight();

unsigned char* pixels = front.getPixels();

for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {
			ofColor voxColor = front.getColor(x,y);
                if (voxColor.a != 0){
			int voxSize = 10;
			ofPoint voxPos = ofPoint(x*voxSize,y*voxSize,0);
			Voxel thisVoxel;
			thisVoxel.setInit(voxPos*1.3,voxSize,voxColor);
			myVoxels.push_back(thisVoxel);
			}
		}
	}



}

//--------------------------------------------------------------
void ofApp::update(){
ofBackground(150);

}

//--------------------------------------------------------------
void ofApp::draw(){


    cam.begin();
    light.enable();
    ofEnableLighting();
    glEnable(GL_DEPTH_TEST);

for (int i = 0; i < myVoxels.size(); i++){
    myVoxels[i].draw();
    }

    glDisable(GL_DEPTH_TEST);
    ofDisableLighting();
    light.disable();
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == 'f'){
        ofToggleFullscreen();
    }
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
