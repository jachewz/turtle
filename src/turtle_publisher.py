#!/usr/bin/env python
## Simple turtle quality published std_msgs/Strings messages
## to the 'quality' topic

import rospy
import random
from turtle.msg import Quality

def publish():
    """Publishes index and quality of random turtle at 5hz"""
    pub = rospy.Publisher('/quality', Quality, queue_size=10)
    rospy.init_node('turtle_publisher')
    rate = rospy.Rate(5) # 5hz
    i = 0
    while not rospy.is_shutdown():
        msg = Quality()
	msg.index = i + 1
	msg.value = random.randint(1,10)
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        publish()
    except rospy.ROSInterruptException:
        pass
