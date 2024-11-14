#include "ofApp.h"

// Remember that enums need to be defined up here and not in setup or anywhere else in the code
// They won't work otherwise
enum Pong {
	Title,
	Game,
	Countdown,
	End
};
// Starts game in Title screen state
enum Pong State = Title;

//--------------------------------------------------------------
void ofApp::setup(){

	// Setting these variables these number spawns ball in the center of the screen
	ofApp::x = 512;
	ofApp::y = 384;
	ofApp::y1;
	ofApp::y2;
	ofApp::radius;
	ofApp::addScore_1;
	ofApp::currentScore_1;
	ofApp::addScore_2;
	ofApp::currentScore_2;

	music.load("Leon.mp3");
	music.setVolume(1.0f);
	music.play();
	music.setLoop(true);

	SFX_1.load("Bell.mp3");
	SFX_2.load("sploosh.mp3");

	font.load("CartoonCheck-Black.ttf", 32);
	font2.load("CartoonCheck-Black.ttf", 100);

	//shader.load("shaderBlurX");

	gui.setup();
	gui.add(buttonStart.setup("Start Game"));
	gui.add(buttonQuit.setup("Quit Game"));
	gui.add(titleScreen.setup("Return to title", false));

	// Removes insides
	ofNoFill();

	// Sets background to black
	ofBackground(0);

	// Randomizes it so that the initial randomization isn't always the same number
	ofSeedRandom((new ofTime)->getAsMilliseconds());

	// Randomizes what direction the ball goes in when spawned into game world
	xdir = ofLerp(-1, 1, glm::round(ofRandom(-1)));
	ydir = ofLerp(-1, 1, glm::round(ofRandom(-1)));

	ofAddListener(ofGetWindowPtr()->events().keyPressed, this,
		&ofApp::keycodePressed);

}

//--------------------------------------------------------------
void ofApp::update(){

	if (Game == State) {
		// In theory what should happen is that it delays ball movement for 5 seconds
		for (int i = 5; i >= 0; --i) {
			if (i == 0) {
				if (currentScore_2 || currentScore_1 < 11) {
					x += xdir * speed;
					y += ydir * speed;
				}
				// Basically just here for edge cases where the game ends and screen is wiped but the ball is still moving
				// Making it so points keep incrementing up while the game is supposed to be over
				else if (currentScore_2 || currentScore_1 >= 11) {
					speed = 0;
					x = ofGetWidth() / 2;
					y = ofGetHeight() / 2;
				}
			}
		}
		// Currently the ball bounces when is hits the left or right side of tthe screen
		// Since there is no player I'm keeping it this way for now aas it makes testing easier
		if (x >= ofGetWidth() - radius) {
			// Increase score count for P1 here
			// This is detecting the right side of the screen
			currentScore_1 = addScore_1 + currentScore_1;
			// Resets position to the center of the screen
			x = ofGetWidth() / 2;
			y = ofGetHeight() / 2;
			// Randomizes what direction the ball goes in when spawned into game world
			xdir = ofLerp(-1, 1, glm::round(ofRandom(1)));
			ydir = ofLerp(-1, 1, glm::round(ofRandom(1)));

			// Plays SFX 'Bell'
			SFX_2.play();

			// Attempting to reset play position here
			ofRectangle Player_1;
			Player_1.y = y1;
		}

		if (x <= radius) {
			// Increase score count for P2 here
			currentScore_2 = addScore_2 + currentScore_2;
			// Resets position to the center of the screen
			x = ofGetWidth() / 2;
			y = ofGetHeight() / 2;
			// Randomizes what direction the ball goes in when spawned into game world
			xdir = ofLerp(-1, 1, glm::round(ofRandom(1)));
			ydir = ofLerp(-1, 1, glm::round(ofRandom(1)));
			
			// Plays SFX 'Bell'
			SFX_2.play();

			// Attempting to reset player position here
			ofRectangle Player_2;
			Player_2.y = y2;
		}

		// Bouncing off the top and bottom of the screen
		// Bottom of the screen
		if (y >= ofGetHeight() - radius) {
			ydir = -1;
		}
		// Top of the screen
		if (y <= radius) {
			ydir = 1;
		}

		// Sound effects for result screen must be played in update in order to work properly
		// Plays 'sploosh' when score increments up
		if (currentScore_1 >= 1) {
			SFX_1.play();
		}
		if (currentScore_2 >= 1) {
			SFX_1.play();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	/*shader.begin();
	shader.end();*/

	// Check for title screen state
	// Display buttons and text here
	if (Title == State) {
		font.drawString("PONG!", ofGetWidth() / 2.25, 400);
		// When buttons are pressed changes game states
		if (buttonStart) {
			State = Game;
		}
		// Note that a pop up will appear when this code runs
		// Just click ignore and you can close it normally
		if (buttonQuit) {
			terminate();
		}
		gui.draw();
	}
	if (Game == State) {
		// Put everything that needs to be drawn here
		// If not set, defaults to a thickness of 1.
		ofSetLineWidth(5);

		// Sets dividing line in the center of the screen
		ofDrawLine((ofGetWidth() / 2), 0, (ofGetWidth() / 2), ofGetHeight());

		// Displays current score for player 1
		ofDrawBitmapString(ofToString(currentScore_1), (ofGetWidth() / 2.1), 25);
		// Displays current score for player 2
		ofDrawBitmapString(ofToString(currentScore_2), (ofGetWidth() / 1.9), 25);

		// Draws circle 
		ofDrawCircle(x, y, radius);

		// Creates rectangle for player 1
		ofRectangle Player_1;
		Player_1.x = 10;
		Player_1.y = y1;
		Player_1.width = 20;
		Player_1.height = 80;
		ofDrawRectangle(Player_1);

		// Creates rectangle for player 2
		ofRectangle Player_2;
		Player_2.x = ofGetWidth() - 30;
		Player_2.y = y2;
		Player_2.width = 20;
		Player_2.height = 80;
		ofDrawRectangle(Player_2);
	}

	// Closes program when score reaches 11
	// Note that you can't replay the game but it does take you back to the title screen to exit the game
	if (currentScore_1 >= 1) {
		// Changes state
		State = End;
		// Checks if game state is End
		if (End == State) {
			// Displays winner text
			ofClear(0, 0, 0);
			font.drawString("The Winner is...", ofGetWidth() / 2.6, 384);
			font2.drawString("Player 1!", ofGetWidth() / 3.5, 550);
			gui.draw();
			// Takes you back to title screen
			if (titleScreen == true) {
				ofClear(0, 0, 0);
				font.drawString("PONG!", ofGetWidth() / 2.25, 400);
				gui.draw();
				State = Title;
			}
		}
	}
	if (currentScore_2 >= 1) {
		// Changes state
		State = End;
		// Checks if game state is End
		if (End == State) {
			// Displays winner text
			ofClear(0, 0, 0);
			font.drawString("The Winner is...", ofGetWidth() / 2.6, 384);
			font2.drawString("Player 2!", ofGetWidth() / 3.5, 550);
			gui.draw();
			// Takes you back to title screen
			if (titleScreen == true) {
				ofClear(0, 0, 0);
				font.drawString("PONG!", ofGetWidth() / 2.25, 400);
				gui.draw();
				State = Title;
			}
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

void ofApp::keycodePressed(ofKeyEventArgs& e) {

	// Displays keycode of input
	// Useful for debugging
	//cout << "KEYCODE : " << e.keycode << endl;

	// Player 1 inputs
	// Move down ('S')
	if (e.keycode == 83) {
		y1 += 10;
	}
	// Move up ('W')
	if (e.keycode == 87) {
		y1 -= 10;
	}

	// Player 2 inputs
	// Move down ('Up_Arrow')
	if (e.keycode == 264) {
		y2 += 10;
	}
	// Move up ('Down_Arrow')
	if (e.keycode == 265) {
		y2 -= 10;
	}
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
