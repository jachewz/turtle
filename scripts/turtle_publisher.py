#!/usr/bin/env python
"""
<Turtle quality publisher of 'Quality' messages to the '/turtle/quality' topic>

Author: Jackson

Date last updated: 22/09/19 by Jackson

Purpose: Publish index and quality of random turtle in a custom 'Quality' message to the '/turtle/quality' topic

Published topic/s:
    /turtle/quality    
 
"""
import rospy
import random
from turtle.msg import Quality

def publish():
    """Publishes index and quality of random turtle at 5hz"""
    pub = rospy.Publisher('/turtle/quality', Quality, queue_size=10)
    rospy.init_node('turtle_publisher')
    rate = rospy.Rate(5) # 5hz
    i = 0
    while not rospy.is_shutdown():
        msg = Quality()
        i += 1
	msg.index = i
	msg.value = random.randint(1,10)
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        publish()
    except rospy.ROSInterruptException:
        pass
