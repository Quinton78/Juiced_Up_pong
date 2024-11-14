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
		void keycodePressed(ofKeyEventArgs& e);
		

		// Allows me to use gui features
		ofxPanel gui;

		// Butons for starting ans stopping the game
		ofxButton buttonStart;
		ofxButton buttonQuit;

		// Using toggle over button here so that you don't have to hold down the button to keep the title screen open
		ofxToggle titleScreen;

		// Variables for my font
		ofTrueTypeFont font;
		ofTrueTypeFont font2;
		
		// Shader variable
		//ofShader shader;

		// Audio variable for music
		ofSoundPlayer music;

		// Audio variable for sound effects
		ofSoundPlayer SFX_1;
		ofSoundPlayer SFX_2;

		// Collisiosn for ball
		ofRectangle collision;

		// Rects for player 1 and 2
		ofRectangle Player_1;
		ofRectangle Player_2;

		// Variables for position
		int x;
		int y;

		// Variables for what direction the ball goes in
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