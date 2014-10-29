//
//  ofApp.cpp
//  2d Pixel to 3d Voxel Matrix - 3 Faces
//
//  Created by Daniel Mastretta 10/2014.
//
//

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

ofEnableSmoothing();

cam.setVFlip(true);
ofSetVerticalSync(true);
ofSetFrameRate(60);

// load the images first

top.loadImage("images/linkT.png");
left.loadImage("images/linkL.png");
right.loadImage("images/linkR.png");

// read the width and height of each image, needed to size the loops

int wT = top.getWidth();
int hT = top.getHeight();

int wL = left.getWidth();
int hL = left.getHeight();

int wR = right.getWidth();
int hR = right.getHeight();


// for each image 2 positions will be found:

// The Top image knows general X and Z (further to be fed into variables xT and zT)
// The Left image knows general X and Y (xL and yL)
// the Right image knows general Z and Y (zR and yR)

// The reason I call them like this is because if the image is read from top to bottom (xT = general X from Top image, and so on...)
// if the 2 values in X, Y or Z match then that will be fed into the final position of the voxel, meaning generalX = xT when equals to xL

// The next lines read the info of the pixels in each image

for (int xT = 0; xT < wT; xT++) {
    for(int zT = 0; zT < hT; zT++) {

        for (int xL = 0; xL < wL; xL++) {
            for(int yL = 0; yL < hL; yL++) {

                for (int zR = 0; zR < wR; zR++) {
                        for(int yR = 0; yR < hR; yR++) {

                            ofColor tColor = top.getColor(xT,zT);
                            ofColor lColor = left.getColor(xL,yL);
                            ofColor rColor = right.getColor(zR,yR);

                                  if (tColor.a > 1 && lColor.a > 1 && rColor.a > 1) {

                                                if(xT==xL) { int x = xT;
                                                    if(yL==yR) { int y = yL;
                                                        if(zT==zR) { int z = zR;

                                                            int voxSize = 10;
                                                            float voxDistance = 0; // 0 will make voxels stick together
                                                            ofPoint voxPos = ofPoint(x*voxSize,y*voxSize,z*voxSize);
                                                            Voxel thisVoxel;
                                                            thisVoxel.setInit(voxPos*(1+voxDistance),voxSize,tColor);
                                                            myVoxels.push_back(thisVoxel);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
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

// Camera and light stuff... urgh need to figure out this better.
    cam.begin();

    //ofDrawGrid(100);

    light.enable();
    ofEnableLighting();
    glEnable(GL_DEPTH_TEST);

// draw every voxel
\
ofFill();

if (doFill){
    ofNoFill();
}

for (int i = 0; i < myVoxels.size(); i++){
    myVoxels[i].draw();
    }


// Disable camera and light systems.
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

    if (key == 's'){
        doFill = !doFill;

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
