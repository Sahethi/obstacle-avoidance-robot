#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
import sys
PI = 3.1415926535897
speed = 3

def move_turtle(length, rotations):

    rospy.init_node('move_turtle', anonymous=False)
    pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    rate = rospy.Rate(10)  # 10hz

    vel = Twist()

    current_rotation=0
    while current_rotation < rotations:
        move_in_line(length, vel, pub)
        rotate(vel, pub)
        current_rotation+=0.25

def move_in_line(side_length, vel, pub):
    
    vel.linear.x = speed
    vel.linear.y = 0
    vel.linear.z = 0

    vel.angular.x = 0
    vel.angular.y = 0
    vel.angular.z = 0

    t0 = rospy.Time.now().to_sec()
    distance_travelled = 0

    while distance_travelled < side_length:
        rospy.loginfo("Linear")
        rospy.loginfo("x=%f", vel.angular.x)
        rospy.loginfo("y=%f", vel.angular.y)
        rospy.loginfo("z=%f", vel.angular.z)

        rospy.loginfo("Angular")
        rospy.loginfo("x=%f", vel.angular.x)
        rospy.loginfo("y=%f", vel.angular.y)
        rospy.loginfo("z=%f", vel.angular.z)
        pub.publish(vel)
        t1 = rospy.Time.now().to_sec()  
        distance_travelled = speed*(t1-t0)

    vel.linear.x = 0
    pub.publish(vel)

def rotate(vel,pub):
	angular_speed = 2
	vel.angular.z = angular_speed
	t0	= rospy.Time.now().to_sec()
	angle_travelled = 0

	while (angle_travelled < PI/2.0 ):
		pub.publish(vel)
		t1 = rospy.Time.now().to_sec()
		angle_travelled = angular_speed*(t1-t0)

	vel.angular.z = 0
	pub.publish(vel)	

if __name__ == '__main__':
    try:
        move_turtle(float(sys.argv[1]), float(sys.argv[2]))
    except rospy.ROSInterruptException:
        pass
