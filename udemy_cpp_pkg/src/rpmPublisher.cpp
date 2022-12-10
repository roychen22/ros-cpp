#include "ros/ros.h"
#include "std_msgs/Float64.h"


const float RPM = 100;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rpm_pub_node");
    ros::NodeHandle node_handle;
    ros::Publisher publisher = node_handle.advertise<std_msgs::Float64>("rpm", 10);
    ros::Rate rate(2);
    ROS_INFO("rpm publisher node has been started!");

    while (ros::ok())
    {
        std_msgs::Float64 rpm_msg;
        rpm_msg.data = RPM;
        publisher.publish(rpm_msg);

        rate.sleep();
    }

     
}