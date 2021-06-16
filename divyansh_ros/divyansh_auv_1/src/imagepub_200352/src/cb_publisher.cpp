#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>



int main(int argc, char** argv)
{
 ros::init(argc, argv, "cb_publisher");
 ros::NodeHandle nh;
 image_transport::ImageTransport it(nh);
 image_transport::Publisher pub = it.advertise("cb_img", 1);
 
 int width, height, ssize, freq;
 n.param("width", width, 40);
 n.param("height", height, 40);
 n.param("square_size", ssize, 5);
 n.param("frequency", freq, 1);
 
 int img[height][width]={0};
 
 int r=0,c=0,rcount=0,ccount=0;
 
 for(r=0;r<height;r=r+(2*ssize))
 {
  for(c=0;c<width;c=c+(2*ssize))
  {
   for(rcount=0;rcount<ssize;rcount++)
   {
    for(ccount=0;ccount<ssize;ccount++)
    {
     img[r+rcount][c+ccount]=255;
    } 
   }
  }
 }
 
 cv::Mat imgnew = cv::Mat(height, width, CV_8UC1, img);
 
 // cv::waitKey(30);
 
 sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", imgnew).toImageMsg();

 // ros::Rate loop_rate(freq);
 
 while(nh.ok())
 {
  pub.publish(msg);
  // ros::spinOnce();
  // loop_rate.sleep();
 }

} 
