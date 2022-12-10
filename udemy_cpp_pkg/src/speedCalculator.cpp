#include "ros/ros.h"
#include "std_msgs/Float64.h"

ros::Publisher publisher;

float WHEEL_DIAMETER;

void rpmCallback(const std_msgs::Float64ConstPtr &rpm_msg)
{
    ros::NodeHandle callback_node_handle;
    bool bRes = callback_node_handle.getParam("wheel_radius", WHEEL_DIAMETER);

    if (bRes)
    {
        float speed_data = M_PI * WHEEL_DIAMETER * rpm_msg->data / 60;

        std_msgs::Float64 speed_msg;
        speed_msg.data = speed_data;
        publisher.publish(speed_msg);
    }
    else
    {
        ROS_WARN("wheel radius not avialable");
    }

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "speed_calculator_node");
    ros::NodeHandle node_handle;
    publisher = node_handle.advertise<std_msgs::Float64>("speed", 10);
    ros::Subscriber subscriber = node_handle.subscribe<std_msgs::Float64>("rpm", 10, rpmCallback);

    ROS_INFO("subscriber node has been started!");

    ros::spin();
     
}