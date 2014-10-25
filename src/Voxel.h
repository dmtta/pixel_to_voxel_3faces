#pragma once
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
