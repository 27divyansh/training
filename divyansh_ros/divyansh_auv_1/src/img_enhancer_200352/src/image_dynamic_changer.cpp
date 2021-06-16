#include <ros/ros.h>

#include <dynamic_reconfigure/image_dynamic_changer.h>
#include <image_enhancer_200352/imagechangerconfig.h>

void callback(image_enhancer_200352::imagechangerconfig &config, int_t level)
{
 int b;
 float c;
 //nh.param("contrast",c,1.0);
 //nh.param("brightness",b,1);
 b=config.brightness;
 c=config.contrast;
 
 msg = msg*c + b;
 
 cv::imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
 cv::waitKey(30);
 
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "image_dynamic_changer");
 
 dynamic_reconfigure::image_dynamic_changer<image_enhancer_200352::imagechangerconfig> server;
 dynamic_reconfigure::image_dynamic_changer<image_enhancer_200352::imagechangerconfig>::CallbackType f;
 
 ros::NodeHandle nh;
 cv::namedWindow("view");
 
 //image_transport::ImageTransport it(nh);
 //image_transport::Subscriber sub = it.subscribe("cb_image", 1, imageCallback);
 ros::spin();
 cv::destroyWindow("view");
}
