#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>


int main(int argc, char** argv)
{
 ros::init(argc, argv, "file_publisher");
 ros::NodeHandle nh;
 image_transport::ImageTransport it(nh);
 image_transport::Publisher pub = it.advertise("image", 1);
 
 char file;
 nh.param<std::string>("file",file,"/home/divyansh/Pictures/divyansh.png");
 
 int freq;
 nh.param("frequency",freq,1);
 

 cv::Mat img = cv::imread(file, IMREAD_COLOR);
 
 cv_bridge::CvImage img_bridge;
 sensor_msgs::Image img_msg;
 std_msgs::Header.stamp = ros::Time::now();
 
 img_bridge = cv_bridge::CvImage(header, sensor_msgs::image_encodings::RGB8, img);
 img_bridge.toImageMsg(img_msg);
 
 // ros::Rate loop_rate(freq);
 
 while(nh.ok())
 {
  pub.publish(img_msg);
  // ros::spinOnce();
  // loop_rate.sleep();
 }
 
}
