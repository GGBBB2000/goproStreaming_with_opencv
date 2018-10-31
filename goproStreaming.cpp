#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat detectFace(cv::Mat &image, std::string &cascade_file, int &flag, cv::Scalar);
std::string setCascade();
cv::Mat detectFaceAndSmile(cv::Mat &image, int &flag);
void streaming(); 


int main(int argc, char ** args){
    int flag = 1;
    //cv::VideoCapture cap("http://10.5.5.9:8080/live/amba.m3u8");
    // cv::VideoCapture cap("http://10.5.5.9:8080/gp/gpControl/executep1=gpStream&c1=restart");
    //cv::VideoCapture cap("http://10.5.5.9/gp/gpControl/execute?p1=gpStream&a1=proto_v2&c1=restart");
    cv::VideoCapture cap("udp://10.5.5.9:8554");
    // cv::VideoCapture cap(0);
    // cv::namedWindow("GoPro");
    //cv::Mat frame = cv::imread(args[1]);
    cv::Mat frame;
    do {
     		cap >> frame;
     		imshow("Cap", detectFaceAndSmile(frame, flag));
		// imshow("Cap", frame);
    } while (cv::waitKey(10) < 0);
     
     

    //imshow("image", detectFaceAndSmile(frame, flag));


#if defined(VERBOSE)
    if (flag == 0) printf("Faces detected\n");
#endif

    cv::waitKey(0);
}

cv::Mat detectFaceAndSmile(cv::Mat &image, int &flag) {

    cv::CascadeClassifier face_cascade; 
    cv::CascadeClassifier smile_cascade; 

    face_cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
    // face_cascade.load("learning/data/cascade/trained_data/cascade.xml");
    smile_cascade.load("/usr/share/opencv/haarcascades/haarcascade_smile.xml");

    std::vector<cv::Rect> faces;
    std::vector<cv::Rect> smile;

    face_cascade.detectMultiScale(image, faces, 1.1, 3, 0, cv::Size(20,20));
    smile_cascade.detectMultiScale(image, smile, 1.1, 3, 0, cv::Size(20,20));

    if (faces.size() > 0) flag = 0;

    for (std::size_t i = 0; i < faces.size(); i++){
	rectangle(image, 
		cv::Point(faces[i].x,faces[i].y),
		cv::Point(faces[i].x + faces[i].width, 
		    faces[i].y + faces[i].height),
		cv::Scalar(0, 200, 0),
		3,
		CV_AA
		);
	for (std::size_t j = 0; j < smile.size(); j++) {
	    if ((faces[i] & smile[j]) == smile[j]) {
		rectangle(image, 
			cv::Point(smile[j].x,smile[j].y),
			cv::Point(smile[j].x + smile[j].width, 
			    smile[j].y + smile[j].height),
			cv::Scalar(200, 0, 0),
			3,
			CV_AA
			);
	    }
	}
	
    }
    return image;
}
    
    //"/usr/share/opencv/haarcascades/haarcascade_eye.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_eye_tree_eyeglasses.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalcatface.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalcatface_extended.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml"
    //"/usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml"
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

