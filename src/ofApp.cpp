//
//  ofApp.cpp
//  2d Pixel to Voxel Matrix
//
//  Created by Daniel Mastretta 10/2014.
//
//

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

ofSetVerticalSync(true);
ofSetFrameRate(60);
ofSetColor(100,75,200);
front.loadImage("images/link.png");

int w = front.getWidth(); // width from the imported image
int h = front.getHeight(); // height from the imported image

for(int y = 0; y < h; y++) { // loops the height pixels from the image
		for(int x = 0; x < w; x++) { // loops through the width pixels from the image
			ofColor voxColor = front.getColor(y,x); // gets the color belonging to that particular pixel in the image
            if (voxColor.a != 0)   // if the alpha channel of the image says it's transparent it ignores it.
            {
			int voxSize = 10;  // Dictamines the size the Voxels will have
			ofPoint voxPos = ofPoint(x*voxSize,y*voxSize,0); // Determines position in space of the voxel
			Voxel thisVoxel; // Creates an instance in memory of the voxel
			thisVoxel.setInit(voxPos*1.3,voxSize,voxColor); // initializes the voxel's position and color
			myVoxels.push_back(thisVoxel); // adds it to the array
			}
		}
	}



}

//--------------------------------------------------------------
void ofApp::update(){
ofBackground(150);

}

//--------------------------------------------------------------
void ofApp::draw(){

// Camera and light stuff... urgh need to figure out this better.
    cam.begin();
    light.enable();
    ofEnableLighting();
    glEnable(GL_DEPTH_TEST);

// draw every voxel
for (int i = 0; i < myVoxels.size(); i++){
    myVoxels[i].draw();
    }


// Disable camera and light systems.
    glDisable(GL_DEPTH_TEST);
    ofDisableLighting();
    light.disable();
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == 'f'){
        ofToggleFullscreen();
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
