#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "hello_world_pub_node");
    ros::NodeHandle node_handle;
    ros::Publisher publisher = node_handle.advertise<std_msgs::String>("hello_world", 10);
    ros::Rate pub_rate(5);
    ROS_INFO("publisher node has been started!");

    int counter = 0;
    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "Hello World! " + std::to_string(counter);
        publisher.publish(msg);
        ++counter;
        pub_rate.sleep();
    }
     
}