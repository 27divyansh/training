#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
 int b;
 float c;
 nh.param("contrast",c,1.0);
 nh.param("brightness",b,1);
 
 msg = msg*c + b;
 
 cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
 cv::waitKey(30);
 
}


int main(int argc, char **argv)
{
 ros::init(argc, argv, "image_changer");
 ros::NodeHandle nh;
 cv::namedWindow("view");
 
 image_transport::ImageTransport it(nh);
 image_transport::Subscriber sub = it.subscribe("cb_image", 1, imageCallback);
 ros::spin();
 cv::destroyWindow("view");
}
