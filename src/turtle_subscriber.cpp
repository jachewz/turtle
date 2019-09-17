#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
 * Receipt of turtle quality
 */

/**
 * Tokenize strings using a delimiter character
**/
void tokenize(std::string const &str, const char delim, std::vector<std::string> &out){

    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos){
	end = str.find(delim, start);
	out.push_back(str.substr(start, end - start));
    }
}

void printQuality(const std_msgs::String::ConstPtr& msg){
    std::string const message = msg->data;
    const char delim = ',';
    std::vector<std::string> out;
    tokenize(message, delim, out);
    int quality = std::stoi(out[1]);
    if (quality>=7){
        ROS_INFO("Index: %s", out[0].c_str());
        ROS_INFO("Quality of turtle: %d", quality);
    }
    else
    {
        ROS_INFO("Index: %s", out[0].c_str());
	ROS_INFO("trash turtle");
    }
}

int main(int argc, char **argv){
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("quality", 1000, printQuality);
    ros::spin();

    return 0;
}

