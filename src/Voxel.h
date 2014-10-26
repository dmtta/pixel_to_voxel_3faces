#pragma once
//
//  Voxel.cpp
//  Voxel Class - 2d Pixel to 3d Voxel Matrix - 3 Faces
//
//  Created by Daniel Mastretta 10/2014.
//
//

#include "ofMain.h"


class Voxel
{
    public:
        Voxel();

        void draw();
        void update();

        ofPoint pos;
        int siz;
        ofColor voxColor;

        float boxSize;
        void setInit(ofPoint _pos, int _siz, ofColor _voxColor);


    protected:
    private:
};
