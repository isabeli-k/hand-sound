#include <opencv2/opencv.hpp>
#include <iostream>

void countFPS (int64 start) {
	double fps = cv::getTickFrequency() / (cv::getTickCount() - start);
    std::cout << "FPS : " << fps << std::endl;
}

void videoCapture (cv::VideoCapture capture) {
    
    // Check if the webcam opened successfully
    if (!capture.isOpened()) {
        std::cerr << "Error: Could not open the webcam." << std::endl;
    }

    std::cout << "Webcam opened successfully. Press 'q' to exit." << std::endl;

    // Create a window to display the webcam feed
    cv::namedWindow("Webcam Test", cv::WINDOW_AUTOSIZE);
}

int displayFrame (cv::Mat frame, cv::VideoCapture capture) {
	// Capture a frame from the webcam
    capture >> frame;
    
    // Check if the frame is empty
	if (frame.empty()) {
		std::cerr << "Error: Could not capture frame." << std::endl;
		return -1;
	}

	// Display the frame in the window
	cv::imshow("Webcam Test", frame);
	
	return 0;
}

int main() {
    // Open the default camera (usually the first camera)
    cv::VideoCapture cap(0);    
    videoCapture(cap);

    while (true) {
        
        cv::Mat frame;
		int64 start = cv::getTickCount();        
        displayFrame (frame, cap);
        
        //Print FPS
        countFPS(start);
	
		// Exit the loop if 'q' is pressed or frame is empty
        if (cv::waitKey(1) == 'q' || displayFrame (frame, cap) == -1) {
            break;
        }
    }

    // Release the webcam and close the window
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
