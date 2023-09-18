#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <math.h>

// Defining pickup and delivery points
float x_pickup_point = -1.0;
float y_pickup_point = 2.0;
float x_delivery_point = -2.0;
float y_delivery_point= 0.0;
float tolerance = 0.5;
bool pickup_point = false;
bool delivery_point = false;

// Define callback function for odometry
void odometry_cb(const nav_msgs::Odometry::ConstPtr& msg) 
{
	float x_robot_pose = msg->pose.pose.position.x;
	float y_robot_pose = msg->pose.pose.position.y;
	
	float pickup_distance;
	float delivery_distance;
	// case 1: robot going to pick delivery
	if(!pickup_point && !delivery_point)
	{
		pickup_distance = sqrt(pow((x_pickup_point - x_robot_pose), 2) + pow((y_pickup_point - y_robot_pose), 2));
		ROS_INFO("Distance from robot to pickup point = %f", pickup_distance);
		
		if(pickup_distance <= tolerance)
		{
			ROS_INFO("Reached to pickup point");
			pickup_point = true;
		}
	}
        // case 2 : after picking the delivery, robot is going for delivering the package to delivery point
	if(pickup_point && !delivery_point)
	{
		delivery_distance = sqrt(pow((x_delivery_point - x_robot_pose), 2) + pow((y_delivery_point - y_robot_pose), 2));
		ROS_INFO("Distance from robot to delivery point = %f", delivery_distance);
		
		if(delivery_distance <= tolerance)
		{
			ROS_INFO("Reached to delivery point");
			delivery_point = true;
		}
	}
}

int main( int argc, char** argv )
{
	ros::init(argc, argv, "add_markers");
  	ros::NodeHandle n;
  	ros::Rate r(1);
  	ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  	// Subscribe to odometry values
  	ros::Subscriber odometry_sub = n.subscribe("/odom", 1000, odometry_cb);

  	// Set our initial shape type to be a cube
  	uint32_t shape = visualization_msgs::Marker::CUBE;

  	// Initialize marker
  	visualization_msgs::Marker marker;

  	// Set the frame ID and timestamp.  See the TF tutorials for information on these.
  	marker.header.frame_id = "map";
  	marker.header.stamp = ros::Time::now();

  	// Set the namespace and id for this marker.  This serves to create a unique ID
  	// Any marker sent with the same namespace and id will overwrite the old one
  	marker.ns = "add_markers";
  	marker.id = 0;

  	// Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  	marker.type = shape;

  	// Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  	marker.action = visualization_msgs::Marker::ADD;

  	// Set the scale of the marker -- 1x1x1 here means 1m on a side
  	marker.scale.x = 0.6;
  	marker.scale.y = 0.6;
  	marker.scale.z = 0.6;
	
  	// Set the color -- be sure to set alpha to something non-zero!
  	marker.color.r = 1.0f;
  	marker.color.g = 1.0f;
  	marker.color.b = 0.0f;
  	marker.color.a = 1.0;
	
  	// Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
	marker.pose.position.x = x_pickup_point;
  	marker.pose.position.y = y_pickup_point;
  	marker.pose.position.z = 0;
  	marker.pose.orientation.x = 0.0;
  	marker.pose.orientation.y = 0.0;
  	marker.pose.orientation.z = 0.0;
  	marker.pose.orientation.w = 1.0;
	
	marker.lifetime = ros::Duration();

  	while (ros::ok())
  	{
		// Publish the marker
		while (marker_pub.getNumSubscribers() < 1)
		{
			if (!ros::ok())
			{
				return 0;
			}
			ROS_WARN_ONCE("Create a subscriber to the marker");
			sleep(1);
		}
		
		if(pickup_point)
		{
			marker.action = visualization_msgs::Marker::DELETE;
			
		}
		
		if(delivery_point)
		{
			marker.pose.position.x = x_delivery_point;
			marker.pose.position.y = y_delivery_point;
			marker.action = visualization_msgs::Marker::ADD;
			
		}
		
		marker_pub.publish(marker);
		
		ros::spinOnce();
	}
	
	return 0;
}
