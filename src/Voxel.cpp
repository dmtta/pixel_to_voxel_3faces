#include "Voxel.h"

Voxel::Voxel() {


}

void Voxel::setInit(ofPoint _pos, int _siz, ofColor _voxColor){

    voxColor = _voxColor;
    pos = _pos;
    siz = _siz;

}

void Voxel::draw(){

    ofSetColor(voxColor);
    ofDrawBox(pos,siz);

}
