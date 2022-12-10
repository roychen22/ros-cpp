#include "ros/ros.h"
#include "udemy_cpp_pkg/OddEvenCheck.h"


bool determineOddEven(udemy_cpp_pkg::OddEvenCheck::Request req,
                      udemy_cpp_pkg::OddEvenCheck::Response res)
{
    int remainder = req.number % 2;

    if (0 == remainder)
    {
        res.answer = "EVEN";
    }
    else if (1 == remainder)
    {
        res.answer = "ODD";
    }
    else
    {
        return false;
    }

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "odd_even_service_server_node");
    ros::NodeHandle node_handle;

    ros::ServiceServer service = node_handle.advertiseService("odd_even_check", determineOddEven);

    ROS_INFO("Odd even check server is runing...");

    ros::spin();

    return 0;
}
