#pragma once
#include "ofMain.h"
#include "ofxGui.h"

struct PingPongBuffer {
public:
    void allocate(int _w, int _h, int _internalformat = GL_RGBA){
        
        for (int i = 0; i < 2; i++) {
            FBOs[i].allocate(_w, _h, _internalformat);
            FBOs[i].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
        }
        clear();
    };
    void swap(){
        std::swap(src, dist);
    };
    void clear(){
        for (int i = 0; i < 2; i++) {
            FBOs[i].begin();
            ofClear(0,255);
            FBOs[i].end();
        }
    };
    
    ofFbo& operator []( int n ){ return FBOs[n]; };
    ofFbo * src = &FBOs[0];
    ofFbo * dist = &FBOs[1];
private:
    ofFbo FBOs[2];
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
    ofShader updatePos;
    ofShader updateRenderer;
    
    PingPongBuffer posPingPong;
    
    ofFbo renderFBO;
    
    float timeStep;
    int textureRes;
    int numParticle;
    
    ofVboMesh mesh;
    
    ofxPanel panel;
    ofParameter<float> m;
    ofParameter<float> t;
    ofParameter<float> w;
    ofParameter<ofVec2f> center;
    ofxToggle bSlow;
    
    ofEasyCam cam;
    ofVec2f toCenter;
    
    // smooth change target
    float tm;
    float tt;
    float tw;
    
    float speed;
    
    bool bShowTex = false;

};
