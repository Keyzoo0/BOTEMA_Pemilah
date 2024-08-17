#!/usr/bin/python3

import rospy

if __name__ == '__main__' :
    while 1 :
        rospy.init_node("test_node")
        rospy.loginfo("kontol")
        rospy.logwarn("awas cok")

        rospy.sleep(1)
    