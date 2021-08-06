
# Obstacle Avoidance Bot

This project is to create a differential drive bot to avoid obstacles. The designed bot is simulated in Gazebo and was done by the help of [ROS Tutorials](https://www.theconstructsim.com/ros-projects-exploring-ros-using-2-wheeled-robot-part-1/).
The details are provided in this [PDF](https://github.com/Sahethi/ros-assignment/blob/master/Obstacle%20Avoidance%20Using%20ROS%20and%20Gazebo.pdf). 

## Table of Contents

* [About the Project](#about-the-project)
  * [File Structure](#file-structure)
  * [Tech Stack](#tech-stack)
  * [Installation](#installation)
* [Video](#video)
* [Authors](#authors)
* [License](#license)

## About The Project
* The Aim of the Project is to make a differential drive robot and simulated the designed robot in Gazebo. We further create a ROS node which performes obstacle avoidance with the help of a laser scanner.

### File Structure
    .
    ├── assets              
    │    ├──robot.png               
    ├── launch                     
    │   ├── rviz.launch  
    |   ├── spawn.launch           
    │   └── world.launch             
    ├── scripts                    
    │   ├──obstacle_avoid.cpp               
    │   ├──obstacle_avoidance.py   
    │   ├──reading_laser.py   
    ├── urdf                    
    │   ├──gazebo.xacro              
    │   ├──macros.xacro
    │   ├──materials.xacro
    │   ├──robot.xacro  
    ├── worlds                    
    │   ├──world01.world              
    │   ├──world02.world   
    │   ├──world03.world
    ├── .catkin_workspace    
    ├── CmakeLists.txt  
    ├── License.md         
    ├── Obstacle Avoidance Using ROS and Gazebo.pdf
    ├── README.md
    └── package.xml

### Tech Stack

* **ROS** 
* **Gazebo**

### Installation
* Clone the project
```
https://github.com/Sahethi/obstacle-avoidance-robot.git

cd obstacle-avoidance-robot
```
* Run catkin_make and open three terminals.
* In first terminal, run the command `roslaunch my_worlds world.launch`. This will open your simulation of the world in Gazebo.
* In another terminal, run this command `roslaunch obstacle_avoidance_robot spawn.launch`. This will launch your robot in your Gazebo environment. 
    * You can also add parameters to it like this `roslaunch obstacle_avoidance_robot spawn.launch x:=1 y:=2 z:=4`. It is not necessary to mention all three values together, you can mention on x or y or z. 
* In your last terminal, run this command  `rosrun obstacle_avoidance_robot` obstacle_avoidance.py. This is a python script which enables your bot to avoid obstacles. 
    
    

## Video

[![Video](/assets/robot.png)](https://www.youtube.com/watch?v=sNOSZIfiu6g)


  
## Authors

- [@Sahethi](https://www.github.com/Sahethi)

## License
The [License](https://github.com/Sahethi/obstacle-avoidance-robot/blob/master/LICENSE.md) used for this Project.
  