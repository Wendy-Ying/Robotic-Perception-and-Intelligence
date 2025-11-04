#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class HelloWorldPublisher : public rclcpp::Node
{
public:
    HelloWorldPublisher()
        : Node("publisher"), m_count(0)
    {
        m_publisher = this->create_publisher<std_msgs::msg::String>("/hello_world", 10);
        m_timer = this->create_wall_timer(500ms, std::bind(&HelloWorldPublisher::timercallback, this));
    }

private:
    void timercallback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(this->m_count++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        this->m_publisher->publish(message);
    }

private:
    rclcpp::TimerBase::SharedPtr m_timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_publisher;
    size_t m_count;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HelloWorldPublisher>());
    rclcpp::shutdown();
    return 0;
}
