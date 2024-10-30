#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

	ofApp::x = 512;
	ofApp::y = 384;
	ofApp::radius;

	sound.load("resident-evil-2-save-room.wav");
	sound.play();
	sound.setLoop(true);

	gui.setup();
	gui.add(volume.set("volume", 0.5, 0.0, 0.1));
	gui.add(decay.set("decay", 0.5, 0.0, 1.0));

	fft = new float[128];

	for (int i = 0; i < 128; i++) {
		fft[i] = 0;
	}

	bands = 64;

	// Removes insides
	ofNoFill();

	// Sets background to black
	ofBackground(0);

	//kinect.init();
	//kinect.open();

	//imageblur.allocate(kinect.getWidth(), kinect.getHeight(), OF_IMAGE_COLOR);


}

//--------------------------------------------------------------
void ofApp::update(){

	ofSoundUpdate();

	sound.setVolume(volume);

	soundSpectrum = ofSoundGetSpectrum(bands);

	for (int i = 0; i < bands; i++) {
		fft[i] *= decay;
		if (fft[i] < soundSpectrum[i]) {
			fft[i] = soundSpectrum[i];
		}
	}

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

	// If not set, defaults to a thickness of 1.
	ofSetLineWidth(5);

	// Sets dividing line in the center of the screen
	ofDrawLine((ofGetWidth() / 2), 0, (ofGetWidth() / 2), ofGetHeight());

	
	// RGB and Alpha is the last value
	// Alpha value also caps out at 255
	//ofSetColor(255, 0, 0, 100);
	
	// Draws circle 
	ofDrawCircle(x, y, radius);

	// Spawns ball in the center of the screen
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
