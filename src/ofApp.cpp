#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){

	// Setting these variables these number spawns ball in the center of the screen
	ofApp::x = 512;
	ofApp::y = 384;
	ofApp::radius;
	ofApp::addScore_1;
	ofApp::currentScore_1;
	ofApp::addScore_2;
	ofApp::currentScore_2;

	music.load("Leon.mp3");
	music.setVolume(1.0f);
	music.play();
	music.setLoop(true);

	shader.load("shaderBlurX");


	// Removes insides
	ofNoFill();

	// Sets background to black
	ofBackground(0);



}

//--------------------------------------------------------------
void ofApp::update(){


	// Currently the ball bounces when is hits the left or right side of tthe screen
	// Since there is no player I'm keeping it this way for now aas it makes testing easier
	if (x >= ofGetWidth() - radius) {
		// Increase score count for P2 here
		// This is detecting the left side of the screen 
		xdir = -1;
		// In theory this should work but doesn't
		currentScore_2 = addScore_2 + currentScore_2;
	}

	if (x <= radius) {
		// Increase score count for P1 here
		// This is detecting the right side of the screen
		xdir = 1;
		currentScore_1 = addScore_1 + currentScore_1;
	}

	if (y >= ofGetHeight() - radius) {
		ydir = -1;
	}

	if (y <= radius) {
		ydir = 1;
	}

	x += xdir * speed;
	y += ydir * speed;

	// Closes program when score reaches 11
	// Note that a pop up will appear when this code runs
	// Just clock ignore and you can close it normally
	if (currentScore_1 == 11) {
		terminate();
	}
	if (currentScore_2 == 11) {
		terminate();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	/*shader.begin();
	shader.end();*/

	// If not set, defaults to a thickness of 1.
	ofSetLineWidth(5);

	// Sets dividing line in the center of the screen
	ofDrawLine((ofGetWidth() / 2), 0, (ofGetWidth() / 2), ofGetHeight());

	// Will have to create variables for score that allow it to increment up
	ofDrawBitmapString(ofToString(currentScore_2), 520, 25);
	ofDrawBitmapString(ofToString(currentScore_1), 498, 25);

	// RGB and Alpha is the last value
	// Alpha value also caps out at 255
	//ofSetColor(255);
	
	// Draws circle 
	ofDrawCircle(x, y, radius);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
