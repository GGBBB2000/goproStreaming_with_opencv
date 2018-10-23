#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

Mat detectFace(Mat &image, string &cascade_file, int &flag);
string setCascade();

int main(int argc, char ** args){
    Mat a = imread(args[1]);
    int flag = 1;
    string test = setCascade();
    Mat detectFaceImage = detectFace(a, test, flag);
    imshow("image", a);
#if defined(VERBOSE)
    printf("Faces detected\n");
    waitKey(0);
#endif
}

Mat detectFace(Mat &image, string &cascade_file, int &flag) {
    CascadeClassifier cascade;
    cascade.load(cascade_file);

    vector<Rect> faces;
    cascade.detectMultiScale(image, faces, 1.1,3,0,Size(20,20));

    for (long unsigned int i = 0; i < faces.size(); i++){
	flag = 0;
	rectangle(image, Point(faces[i].x,faces[i].y),
		Point(faces[i].x + faces[i].width,faces[i].y + faces[i].height),
		Scalar(0,200,0),3,CV_AA);
    }
    return image;
}

string setCascade() {
    return
    //"/usr/share/opencv/haarcascades/haarcascade_eye.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_eye_tree_eyeglasses.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalcatface.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalcatface_extended.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml"
    "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalface_alt_tree.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalface_default.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_fullbody.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_lefteye_2splits.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_licence_plate_rus_16stages.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_lowerbody.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_profileface.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_righteye_2splits.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_russian_plate_number.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_smile.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_upperbody.xml"
    //"/usr/share/opencv/lbpcascades/lbpcascade_frontalcatface.xml"
    //"/usr/share/opencv/lbpcascades/lbpcascade_frontalface.xml"
    //"/usr/share/opencv/lbpcascades/lbpcascade_frontalface_improved.xml"
    //"/usr/share/opencv/lbpcascades/lbpcascade_profileface.xml"
    //"/usr/share/opencv/lbpcascades/lbpcascade_silverware.xml"
    ;
}

