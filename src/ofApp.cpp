#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){

	ofApp::x = 512;
	ofApp::y = 384;
	ofApp::radius;

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
	}

	if (x <= radius) {
		// Increase score count for P1 here
		// This is detecting the right side of the screen
		xdir = 1;
	}

	if (y >= ofGetHeight() - radius) {
		ydir = -1;
	}

	if (y <= radius) {
		ydir = 1;
	}

	x += xdir * speed;
	y += ydir * speed;
}

//--------------------------------------------------------------
void ofApp::draw(){

	//ofSetColor(255);
	shader.begin();
	// Draws circle 
	ofDrawCircle(x, y, radius);
	shader.end();

	// If not set, defaults to a thickness of 1.
	ofSetLineWidth(5);

	// Sets dividing line in the center of the screen
	ofDrawLine((ofGetWidth() / 2), 0, (ofGetWidth() / 2), ofGetHeight());

	
	// RGB and Alpha is the last value
	// Alpha value also caps out at 255
	

	// Spawns ball in the center of the screen*/
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
