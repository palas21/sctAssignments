#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include "std_msgs/msg/string.hpp"


class ImageSubscriber : public rclcpp::Node 
{
  public:
    // In this constructor, we declare the parameters and create the subscriber and publishers
    ImageSubscriber() 
    : Node("image_subscriber"), frame_id_(0)
    {
      declare_parameters();
      subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(this->get_parameter("image_topic").as_string(), 10, std::bind(&ImageSubscriber::subscribe_frame, this, std::placeholders::_1));
      publisher_gray_ = this->create_publisher<sensor_msgs::msg::Image>(this->get_parameter("gray_topic").as_string(), 10);
      publisher_canny_ = this->create_publisher<sensor_msgs::msg::Image>(this->get_parameter("canny_topic").as_string(), 10);
      publisher_blur_ = this->create_publisher<sensor_msgs::msg::Image>(this->get_parameter("blur_topic").as_string(), 10);
    }

  private:
    // This method will be called every time a new image message is received
    void subscribe_frame(const sensor_msgs::msg::Image::SharedPtr msg){
        
        // We declare the variables to store the images
        cv::Mat frame;
        cv::Mat frame_gray;
        cv::Mat frame_blur;
        cv::Mat frame_canny;

        try{
            frame = cv_bridge::toCvCopy(msg, "bgr8")->image; // We convert the ROS image message to an OpenCV image
        }
        
        catch (cv_bridge::Exception& e){ // In case of exception, we print an error message
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }

        cv::GaussianBlur(frame, frame_blur, cv::Size(9, 9), 0);  // We apply a Gaussian blur to the image using OpenCV with kernel size 9x9 
        cv::Canny(frame, frame_canny, 50, 150); // We apply the Canny edge detector to the image using OpenCV with thresholds 50 and 150
        cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY); // We convert the image to grayscale using OpenCV

         ++frame_id_;

        // We show and publish the images according to the parameters

        if(this->get_parameter("blur_show").as_bool()){
          cv::imshow("Blur", frame_blur); // We show the blur image using OpenCV imshow() function
        }
        if(this->get_parameter("blur_publish").as_bool()){
          sensor_msgs::msg::Image::SharedPtr ros_image_blur_ = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame_blur).toImageMsg(); // We convert the blur image to a ROS image message using cv_bridge
          ros_image_blur_->header.frame_id = std::to_string(frame_id_); // We set the frame_id_ to the header of the image message
          publisher_blur_->publish(*ros_image_blur_); // We publish the image message
        }

        // Same proccess for the other images
        
        if(this->get_parameter("canny_show").as_bool()){
          cv::imshow("Canny", frame_canny);
        }
        if(this->get_parameter("canny_publish").as_bool()){
          sensor_msgs::msg::Image::SharedPtr ros_image_canny_ = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame_canny).toImageMsg();
          ros_image_canny_->header.frame_id = std::to_string(frame_id_);
          publisher_canny_->publish(*ros_image_canny_);
        }


        if(this->get_parameter("gray_show").as_bool()){
          cv::imshow("Gray", frame_gray);
        }
        if(this->get_parameter("gray_publish").as_bool()){
          sensor_msgs::msg::Image::SharedPtr ros_image_gray_ = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame_gray).toImageMsg();
          ros_image_gray_->header.frame_id = std::to_string(frame_id_);
          publisher_gray_->publish(*ros_image_gray_);
        }

        cv::waitKey(1);
    }

    // This method declares the parameters of the node
    void declare_parameters(){
      this->declare_parameter<std::string>("image_topic", "image");
      
      this->declare_parameter<bool>("blur_publish", true);
      this->declare_parameter<bool>("blur_show", true);
      this->declare_parameter<std::string>("blur_topic", "blur");

      this->declare_parameter<bool>("gray_publish", true);
      this->declare_parameter<bool>("gray_show", true);
      this->declare_parameter<std::string>("gray_topic", "gray");

      this->declare_parameter<bool>("canny_publish", true);
      this->declare_parameter<bool>("canny_show", true);
      this->declare_parameter<std::string>("canny_topic", "canny");
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_; // this subscriber will receive the image messages
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_gray_; // this publisher will publish the gray image
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_canny_; // this publisher will publish the canny image
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_blur_; // this publisher will publish the blur image 
    size_t frame_id_; // this variable will be used to publish the frame_id with the image messages for different kinds
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv); 
  rclcpp::spin(std::make_shared<ImageSubscriber>());
  rclcpp::shutdown();
  return 0;
}