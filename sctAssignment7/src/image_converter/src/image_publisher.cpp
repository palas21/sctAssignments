#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include "std_msgs/msg/string.hpp"

class ImagePublisher : public rclcpp::Node
{
  public:
    // We declare the parameters and create the publisher and timer
    ImagePublisher()
    : Node("image_publisher"), frame_id_(0){
      declare_parameters(); 
      publisher_ = this->create_publisher<sensor_msgs::msg::Image>(this->get_parameter("image_topic").as_string(), 10);
      timer_ = this->create_wall_timer(std::chrono::milliseconds(this->get_parameter("frequency").as_int()), std::bind(&ImagePublisher::publish_frame, this));
      video_capture_.open(this->get_parameter("video_path").as_string());
    }

  private:
    // This method will be called every time the timer is triggered
    void publish_frame(){
        // We read the frame from the video file, convert it to ros image message and publish it
        cv::Mat frame;
        if (video_capture_.isOpened()){
            video_capture_ >> frame; // We read the frame from the video file and store it in the frame variable
            if (!frame.empty()){
                sensor_msgs::msg::Image::SharedPtr img_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg(); // We convert the frame to a ROS image message using cv_bridge
                img_msg->header.frame_id = std::to_string(frame_id_);  // We set the frame_id_ to the header of the image message
                publisher_->publish(*img_msg); // We publish the image message
                RCLCPP_INFO(this->get_logger(), "Publishing frame %ld", frame_id_); // We print the frame_id_
                ++frame_id_;
            }
            else{ // In case the video file is empty, we release the video capture and print an error message
                RCLCPP_ERROR(this->get_logger(), "Video file is empty");
                video_capture_.release();
                rclcpp::shutdown();
            }
        }
        else{ // In case the video file is not opened, we print an error message
            RCLCPP_ERROR(this->get_logger(), "Video file is not opened");
            rclcpp::shutdown();
        }
    }

    // We declare the parameters
    void declare_parameters(){
        this->declare_parameter<std::string>("video_path", "path/to/video.mp4");
        this->declare_parameter<int>("frequency", 20);
        this->declare_parameter<std::string>("image_topic", "image");
    }

    rclcpp::TimerBase::SharedPtr timer_; // We declare the timer for the publishing
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_; // We declare the publisher for the image
    cv::VideoCapture video_capture_; // We declare the video capture object which will read the video file and convert it to frames
    size_t frame_id_; // We declare the frame_id_
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ImagePublisher>());
  rclcpp::shutdown();
  return 0;
}