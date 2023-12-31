#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// By SimpleActionClient, client will send goal requests to the "move_base" server
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pick_objects");
    //tell the action client that we want to spin a thread by default
    MoveBaseClient ac("move_base", true);

    // move_base action server to come up in 5 second
    while(!ac.waitForServer(ros::Duration(5.0))){
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;

    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    // Define a position and orientation for the robot to reach
    goal.target_pose.pose.position.x = -1.0;
    goal.target_pose.pose.position.y = 2.0;
    goal.target_pose.pose.orientation.w = 1.5;

    // Send the goal position and orientation for the robot to reach
    ROS_INFO("Sending goals for the robot to reach");
    ac.sendGoal(goal);

    // Wait in infinite time for the results
    ac.waitForResult();

    // Check if the robot reached its goal
    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
        ROS_INFO("The base moved 1 meter forward");
    } else {
        ROS_INFO("ERROR: The base failed to move forward 1 meter");
    }

    // Waiting for 3 secs at pick up zone

    ros::Duration(3.0).sleep();
    ROS_INFO("Waited for 3 seconds, and end of the whole process.");


    // Add second goal for the robot to reach
    goal.target_pose.pose.position.x = -2.0;
    goal.target_pose.pose.position.y = 0.0;
    goal.target_pose.pose.orientation.w = 1.5;
   
    ROS_INFO("robot going to second goal");
    ac.sendGoal(goal);

    ac.waitForResult();

    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
        ROS_INFO("The base moved 2 meter forward");
    } else {
        ROS_INFO("ERROR: The base failed to move forward 2 meter");
    }

    

    return 0;

}
