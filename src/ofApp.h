#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"
#include "ofxCvImage.h"


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
		

		// For future UI elements like the buttons
		ofxPanel gui;

		ofxToggle toggle;
		ofxButton button;
		ofxLabel label;

		ofxIntField intField;
		ofxFloatField floatField;
		ofxTextField textField;
		
		// Shader variable
		//ofShader shader;

		// Audio variable for music
		ofSoundPlayer music;

		// Audio variable for sound effects
		ofSoundPlayer SFX;

		int x;
		int y;
		int xdir = 1;
		int ydir = 1;
		// Speed of the circle
		int speed = 5;
		// Determines radius of circle
		int radius = 20;

		//  Player 1 and 2 score
		int addScore_1 = 1;
		int currentScore_1;
		int addScore_2 = 1;
		int currentScore_2;
		
		// Spawn positions for player 1 and 2
		int y1 = 10;
		int y2 = 10;
};