#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <std_srvs/srv/empty.hpp>
#include <turtlesim/srv/set_pen.hpp>
#include <turtlesim/msg/pose.hpp>
#include <turtlesim/srv/spawn.hpp>


#include <functional>
#include <memory>

class TurtlesimClient : public rclcpp::Node{
    public:
        TurtlesimClient() : Node("turtlesim_client"){
            velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
            subscriber_ = this->create_subscription<sensor_msgs::msg::Joy>("/joy", 10, std::bind(&TurtlesimClient::joyCallback, this, std::placeholders::_1));
            //pose_subscriber_ = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose", 10, std::bind(&TurtlesimClient::poseCallback, this, std::placeholders::_1));
            clear_client = this->create_client<std_srvs::srv::Empty>("clear");
            reset_client = this->create_client<std_srvs::srv::Empty>("reset");
            set_pen_client = this->create_client<turtlesim::srv::SetPen>("turtle1/set_pen");
            spawn_client = this->create_client<turtlesim::srv::Spawn>("spawn");
        }

    private:
        void joyCallback(sensor_msgs::msg::Joy msg){
            if(msg.buttons[0] == 1){
                auto request = std::make_shared<std_srvs::srv::Empty::Request>();
                auto result = clear_client->async_send_request(request);
            }
            if(msg.buttons[1] == 1){
                auto request = std::make_shared<std_srvs::srv::Empty::Request>();
                auto result = reset_client->async_send_request(request);
                speed = 2;
            }
            if(msg.buttons[2] == 1){
                auto request = std::make_shared<turtlesim::srv::Spawn::Request>();
                request->x = 5.0;
                request->y = 5.0;
                request->theta = 0.0;
                request->name = "turtle" + std::to_string(++turtle_num);
                auto result = spawn_client->async_send_request(request);
            }
            if(msg.buttons[3] == 1){
                auto request = std::make_shared<turtlesim::srv::SetPen::Request>();
                if(speed = 2){
                    auto request = std::make_shared<turtlesim::srv::SetPen::Request>();
                    request->r = 255;
                    request->g = 255;
                    request->b = 255;
                    request->width = 5;
                    request->off = 0;
                    speed = 4;
                }
                else{

                    request->r = 0;
                    request->g = 0;
                    request->b = 0;
                    request->width = 0;
                    request->off = 1;
                    speed = 2;
                }
                auto result = set_pen_client->async_send_request(request);
            }
            
            auto twist = std::make_shared<geometry_msgs::msg::Twist>();
            twist->linear.x = (msg.axes[5] - 1) * -1 * speed;
            twist->angular.z = msg.axes[0] * 2.5;
            velocity_publisher_->publish(*twist);
        }

        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
        rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscriber_;
        //rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_subscriber_;
        rclcpp::Client<std_srvs::srv::Empty>::SharedPtr clear_client;        
        rclcpp::Client<std_srvs::srv::Empty>::SharedPtr reset_client;
        rclcpp::Client<turtlesim::srv::SetPen>::SharedPtr set_pen_client;
        rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr spawn_client;
        size_t turtle_num = 1;
        size_t speed = 2;
};

int main(int argc, char **argv){    
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtlesimClient>());
    rclcpp::shutdown();
    return 0;
}