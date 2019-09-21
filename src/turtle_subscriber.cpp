#include "ros/ros.h"
#include "turtle/Quality.h"

void printQuality(const turtle::Quality::ConstPtr &msg){
    int idx = msg->index;
    int quality = msg->value;
    if (quality>=7){
        ROS_INFO("Index: %d", idx);
        ROS_INFO("Quality of turtle: %d", quality);
    }
    else
    {
        ROS_INFO("Index: %d", idx);
	ROS_INFO("trash");
    }
}

int main(int argc, char **argv){
    ROS_INFO("Running subscriber");
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/quality", 10, printQuality);
    ros::spin();

    return 0;
}

