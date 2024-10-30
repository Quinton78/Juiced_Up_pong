#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"


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

		ofxPanel gui;

		ofImage imageblur;

		ofParameter<int> blur;

		ofParameter<int> bob;

		ofParameter<float> volume;
		ofParameter<float> decay;

		ofSoundPlayer sound;

		float *fft;

		float *soundSpectrum;

		int bands;

		int x;
		int y;
		int xdir = 1;
		int ydir = 1;
		int speed = 10;
		int radius = 20;
		
};
