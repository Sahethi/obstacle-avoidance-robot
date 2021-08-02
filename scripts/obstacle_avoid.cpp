#include "ros/ros.h"
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <string>
#include<iostream>
using namespace std;

ros::Publisher pub;
string status = "" ;
float threshold_dist = 1.5;
float linear_speed = 0.6;
float angular_speed = 1;
geometry_msgs::Twist message;
float linear_x = 0;
float angular_z = 1;

void takeAction(float right , float front , float left){
    if (front > threshold_dist  && left > threshold_dist && right > threshold_dist){
        status = "case 1 - no obstacle";
        linear_x = linear_speed;
        angular_z = 0;
    }else if (front < threshold_dist  && left < threshold_dist && right < threshold_dist){
        status = "case 7 - front and left and right";
        linear_x = -linear_speed;
        angular_z = angular_speed; 
    }else if (front < threshold_dist && left > threshold_dist && right > threshold_dist){
        status = "case 2 - front";
        linear_x = 0;
        angular_z = angular_speed;
    }else if (front > threshold_dist && left > threshold_dist && right < threshold_dist){
        status = "case 3 - right";
        linear_x = 0;
        angular_z = -angular_speed;
    }else if (front > threshold_dist && left < threshold_dist && right > threshold_dist){
        status = "case 4 - left";
        linear_x = 0;
        angular_z = angular_speed;
    }else if (front < threshold_dist && left > threshold_dist && right < threshold_dist){
        status = "case 5 - front and right";
        linear_x = 0;
        angular_z = -angular_speed;
    }else if (front < threshold_dist && left < threshold_dist && right > threshold_dist){
        status = "case 6 - front and left";
        linear_x = 0;
        angular_z = angular_speed;
    }else if (front > threshold_dist && left < threshold_dist && right < threshold_dist){
        status = "case 8 - left and right";
        linear_x = linear_speed;
        angular_z = 0;
    }else{
        status = "unknown case";
    }

    message.linear.x=linear_x;
    message.angular.z=angular_z;
    pub.publish(message);
    cout<<"  "<<status;
    cout<<"  "<<right;
    cout<<"  "<<front;
    cout<<"   "<<left<<endl;
}


float smallestElementInArray(float arr[] , int n){
    float temp = 2.0;
    for(int i=0; i<n; i++) {
      if(temp>arr[i]) 
         temp=arr[i];
   }
   return temp;
}

void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg){
    int length = msg->ranges.size();
    int lendiv3 = length/3;
    float right[length/3] , front[length/3] , left[length/3];
    for( int i=0 ; i < length ; i++){
        if(i < lendiv3)
            right[i] = msg->ranges[i];
        else if ((i > lendiv3-1) && (i < 2*lendiv3))
            front[i-240] = msg->ranges[i];
        else if (((2*lendiv3)-1) && (i < length))
            left[i - 480] = msg->ranges[i];
    }
    float rightmin = smallestElementInArray(right , length/3);
    float frontmin = smallestElementInArray(front , length/3);
    float leftmin = smallestElementInArray(left , length/3);
    takeAction(rightmin , frontmin , leftmin);
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "reading_laser");
    ros::NodeHandle n;

    pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Subscriber sub = n.subscribe("/robot/laser/scan", 10, laserCallback);

    ros::spin();
    return 0;
}
