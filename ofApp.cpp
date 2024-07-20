#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofNoFill();
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int i = 0; i < 10; i++) {

		float v_start = ofGetFrameNum() * 3 + i * 10;

		ofSetColor(ofMap(i, 0, 10, 239, 0));

		ofBeginShape();
		for (float v = v_start; v < v_start + 60; v += 0.5) {

			auto u = v * 15 + i * 10;
			auto location = this->make_point(300, 80, u, v);

			ofVertex(location);
		}
		ofEndShape();
	}

	for (int i = 0; i < 10; i++) {

		float v_start = 180 + ofGetFrameNum() * 3 + i * 10;

		ofSetColor(ofMap(i, 0, 10, 239, 0));

		ofBeginShape();
		for (float v = v_start; v < v_start + 60; v += 0.5) {

			auto u = v * 15 + i * 10;
			auto location = this->make_point(300, 80, u, v);

			ofVertex(location);
		}
		ofEndShape();
	}

	this->cam.end();

	/*
	int start = 528;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// ���w�f�b�T������ �`���Ċy���ސ��w�����@P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}