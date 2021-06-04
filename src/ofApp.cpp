#include "ofApp.h"
#include "phase.h"

using namespace ofxCv;

using namespace cv;
using namespace std;


static void help()
{
    cout << "\nThis program seek for letter bounding box on image\n"
        << "Call:\n"
        << "/.edge input_image_name [output_image_name]"
        << endl;
}
//--------------------------------------------------------------
void ofApp::setup(){
    
    filePath= "/Users/user1/Music/lena.png";
    before.load(filePath);
    Mat image = toCv(before);
    //Mat image;
    //
    if (image.empty())
    {
        cout << "Cannot read image file " << endl;
        //help();
        return -1;
    }
   
    auto size = image.size();
    resize(image, image, size);
    
    PhaseCongruency pc(image.size(), 4, 6);

    Mat edges, corners;
    pc.feature(image, edges, corners);

    Mat edge_img;
    normalize(edges, edge_img, 255, 0, NORM_MINMAX, CV_8U);
    toOf(edge_img, after_edge);
    after_edge.update();
    
    Mat corner_img;
    normalize(corners, corner_img, 255, 0, NORM_MINMAX, CV_8U);
    toOf(corner_img, after_corner);
    after_corner.update();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    before.draw(0, 0, 512, 512);
    after_edge.draw(512, 0, 512, 512);
    after_corner.draw(1024, 0, 512, 512);
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
