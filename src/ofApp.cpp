#include "ofApp.h"

// Remember that enums need to be defined up here and not in setup or anywhere else in the code
// They won't work otherwise
enum Pong {
	Title,
	Game,
	Countdown,
	End
};
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

	//shader.load("shaderBlurX");

	gui.setup();

	gui.add(toggle.setup("toggle", false));
	gui.add(button.setup("button"));
	gui.add(label.setup("label", "THIS IS LABEL"));
	gui.add(intField.setup("int field", 100, 0, 100));
	gui.add(floatField.setup("float field", 100.0, 0.0, 100.0));
	gui.add(textField.setup("text field", "text"));

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

	State = Title;

}

//--------------------------------------------------------------
void ofApp::update(){

	//if (Game == State) {}
		// In theory what should happen is that it delays ball movement for 5 seconds
		for (int i = 5; i >= 0; --i) {
			if (i == 0) {
				if (currentScore_2 || currentScore_1 < 11) {
					x += xdir * speed;
					y += ydir * speed;
				}
				// Basically just here for edge cases where the game ends and screen is wiped but the ball is still moving
				// So point keep incrementing up while the game is supposed to be over
				else if (currentScore_2 || currentScore_1 >= 11) {
					speed = 0;
					x = 512;
					y = 384;
				}
			}
		}
		// Currently the ball bounces when is hits the left or right side of tthe screen
				// Since there is no player I'm keeping it this way for now aas it makes testing easier
		if (x >= ofGetWidth() - radius) {
			// Increase score count for P2 here
			// This is detecting the left side of the screen 
			// In theory this should work but doesn't
			currentScore_2 = addScore_2 + currentScore_2;
			// Resets position to the center of the screen
			x = 512;
			y = 384;
			// Randomizes what direction the ball goes in when spawned into game world
			xdir = ofLerp(-1, 1, glm::round(ofRandom(1)));
			ydir = ofLerp(-1, 1, glm::round(ofRandom(1)));
		}

		if (x <= radius) {
			// Increase score count for P1 here
			// This is detecting the right side of the screen
			currentScore_1 = addScore_1 + currentScore_1;
			// resets position to the center of the screen
			x = 512;
			y = 384;
			// Randomizes what direction the ball goes in when spawned into game world
			xdir = ofLerp(-1, 1, glm::round(ofRandom(1)));
			ydir = ofLerp(-1, 1, glm::round(ofRandom(1)));
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
	

	

	
}

//--------------------------------------------------------------
void ofApp::draw(){

	/*shader.begin();
	shader.end();*/

	// Check for title screen state
	// Display buttons and text here
	/*if (State == Title) {
		ofDrawBitmapString("PONG!", 490, 384);
		// When buttons are pressed changes game states
	}*/
	/*if (State == Game) {
		// Put everything that needs to be drawn here
	}*/
	// If not set, defaults to a thickness of 1.
	ofSetLineWidth(5);

	// Sets dividing line in the center of the screen
	ofDrawLine((ofGetWidth() / 2), 0, (ofGetWidth() / 2), ofGetHeight());

	// Will have to create variables for score that allow it to increment up
	ofDrawBitmapString(ofToString(currentScore_2), 520, 25);
	ofDrawBitmapString(ofToString(currentScore_1), 498, 25);
	//ofDrawBitmapString(ofToString(i), 600, 100);

	// RGB and Alpha is the last value
	// Alpha value also caps out at 255
	//ofSetColor(255);
	
	// Draws circle 
	ofDrawCircle(x, y, radius);

	ofRectangle Player_1;
	Player_1.x = 10;
	Player_1.y = y1;
	Player_1.width = 20;
	Player_1.height = 80;
	ofDrawRectangle(Player_1);

	ofRectangle Player_2;
	Player_2.x = 995;
	Player_2.y = y2;
	Player_2.width = 20;
	Player_2.height = 80;
	ofDrawRectangle(Player_2);

	// Closes program when score reaches 11
	// Note that a pop up will appear when this code runs
	// Just clock ignore and you can close it normally
	if (currentScore_1 >= 11) {
		State = End;
		if (End == State) {
			ofClear(0, 0, 0);
			ofDrawBitmapString("GAME OVER", 490, 384);
		}
	}
	if (currentScore_2 >= 11) {
		// Sets game state
		State = End;
		// Checks if game state is End
		if (End == State) {
			ofClear(0, 0, 0);
			ofDrawBitmapString("GAME OVER", 490, 384);
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

void ofApp::keycodePressed(ofKeyEventArgs& e) {

	// Displays keycode of input
	// Useful for debugging
	cout << "KEYCODE : " << e.keycode << endl;

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
