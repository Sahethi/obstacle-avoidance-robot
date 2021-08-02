
# Obstacle Avoidance Bot

This project is to create a differential drive bot to avoid obstacles. The designed bot is simulated in Gazebo and was done by the help of [ROS Tutorials](https://www.theconstructsim.com/ros-projects-exploring-ros-using-2-wheeled-robot-part-1/).
The details are provided in this [PDF](https://github.com/Sahethi/ros-assignment/blob/master/Obstacle%20Avoidance%20Using%20ROS%20and%20Gazebo.pdf). 

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
    ├── CmakeLists.txt    
    ├── Obstacle Avoidance Using ROS and Gazebo.pdf          
    ├── package.xml
    ├── .catkin_workspace
    └── README.md 

## Video

[![Video](/assets/robot.png)](https://www.youtube.com/watch?v=sNOSZIfiu6g)

  
## Tech Stack

* **ROS** 
* **Gazebo**

  
## Authors

- [@Sahethi](https://www.github.com/Sahethi)

  