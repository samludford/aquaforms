#include "ofApp.h"

float counter;
float control_x1, control_y1;
float control_x2, control_y2;

float n = 200;
float spacing = 3;
bool second_control = false;

bool saving = false;

ofImage use;

//--------------------------------------------------------------
void ofApp::setup(){

    
    ofBackground(30);
    ofSetColor(200);
    ofSetBackgroundAuto(false);
    mFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
//    ofToggleFullscreen();
//    ofSetWindowShape(800, 800);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    control_x1 = ofMap(ofNoise(counter/200),0,1,-ofGetWidth()/3,ofGetWidth()/3);
    control_y1 = ofMap(ofNoise(counter/300+40),0,1,-ofGetHeight()/3,ofGetHeight()/3);
    control_x2 = ofMap(ofNoise(counter/800+10),0,1,-ofGetWidth()/3,ofGetWidth()/3);
    control_y2 = ofMap(ofNoise(counter/900),0,1,-ofGetHeight()/3,ofGetHeight()/3);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    mFbo.begin();
    
    if(saving) {
        ofBeginSaveScreenAsPDF(ofToString(ofGetFrameNum()) + ".pdf");
    }
    
    ofSetColor(30);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(200);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    
    for(int i=-n/2 ; i < n/2 ; i++) {
        
        ofPushMatrix();
        
        ofRotate(i * 360/n);
        
        float x = i*spacing;
        ofPolyline line;
        
        line.curveTo(ofMap(ofNoise(counter/20),0,1,-x,x), -ofGetHeight()/3 + 20);
        line.curveTo(sin(counter/60+10)*x, -ofGetHeight()/3 + 20);
        line.curveTo(control_x1, control_y1);
        if(second_control) {
            line.curveTo(control_x2, control_y2);
        }
        line.curveTo(cos(counter/40)*x, ofGetHeight()/3-20);
        line.curveTo(x, ofGetHeight()/3-20);
        line.draw();
        
        ofPopMatrix();
    }
    
    ofPopMatrix();
//    mFbo.end();
//    mFbo.draw(0, 0);
    counter++;
    
    if(saving) {
        ofEndSaveScreenAsPDF();
        saving = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    
    if(key == '1') {
        n = 10;
        spacing = 1;
        second_control = true;
    } else if(key == '2') {
        n = 10;
        spacing = 20;
        second_control = true;
    } else if(key == '3') {
        n = 50;
        spacing = 5;
        second_control = true;
    } else if(key == '4') {
        n = 100;
        spacing = 6;
        second_control = true;
    } else if(key == '5') {
        n = 300;
        spacing = 1;
        second_control = false;
    } else if(key == '6') {
        n = 300;
        spacing = 10;
        second_control = true;
    } else if(key == '7') {
        n = 200;
        spacing = 3;
        second_control = false;
    } else if(key == ' ') {
        
        ofSaveScreen(ofToString(ofGetFrameNum())+".png");
    } else if(key == 's') {
        saving = true;
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
