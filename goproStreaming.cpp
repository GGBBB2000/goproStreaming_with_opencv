#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat detectFace(cv::Mat &image, std::string &cascade_file, int &flag, cv::Scalar);
std::string setCascade();

int main(int argc, char ** args){

    cv::Mat a = cv::imread(args[1]);
    int flag = 1;
    std::string smile= "/usr/share/opencv/haarcascades/haarcascade_smile.xml";
    std::string eye = "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml";

    cv::Mat detectFaceImage = detectFace(a, smile, flag, cv::Scalar(100, 200, 0));
    cv::Mat detectEyeImage  = detectFace(detectFaceImage, eye, flag, cv::Scalar(200, 0, 0));
    imshow("image", detectEyeImage);

#if defined(VERBOSE)
    if (flag == 0) printf("Faces detected\n");
#endif

    cv::waitKey(0);
}

cv::Mat detectFace(cv::Mat &image, std::string &cascade_file, int &flag, cv::Scalar s) {
    cv::CascadeClassifier cascade;
    cascade.load(cascade_file);

    std::vector<cv::Rect> faces;
    cascade.detectMultiScale(image, faces, 1.1, 3, 0, cv::Size(20,20));

    if (faces.size() > 0) flag = 0;

    for (long unsigned int i = 0; i < faces.size(); i++){
	rectangle(image, 
		cv::Point(faces[i].x,faces[i].y),
		cv::Point(faces[i].x + faces[i].width, 
		    faces[i].y + faces[i].height),
		s,
		3,
		CV_AA
		);
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

