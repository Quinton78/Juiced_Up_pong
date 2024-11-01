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

	shader.load("shaderBlurX.vert", "shaderBlurX.frag");
	shader.load("shaderBlurY.vert", "shaderBlurY.frag");


	// Removes insides
	ofNoFill();

	// Sets background to black
	ofBackground(0);


}

//--------------------------------------------------------------
void ofApp::update(){



	if (x >= ofGetWidth() - radius) {
		xdir = -1;
	}

	if (x <= radius) {
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

	ofSetColor(255);
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
	
	//ofSetColor(255, 0, 0, 100);
	

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
