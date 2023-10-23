#include <ros/ros.h>

#include <octomap/octomap.h>

#include <octomap_msgs/GetOctomap.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "static_octomap_publisher");

  ros::NodeHandle handle;

  // octomap service
  ros::ServiceClient get_octomap = handle.serviceClient<octomap_msgs::GetOctomap>("octomap_full");

  octomap_msgs::GetOctomap srv;

  if (!get_octomap.call(srv)) {
    ROS_ERROR("Failed to receive Octomap");
    return 0;
  }

  const octomap_msgs::Octomap& map = srv.response.map;

  ROS_INFO("ID: %s", map.id.c_str());
  ROS_INFO("Resolution: %.3f", map.resolution);
  ROS_INFO("Elements: %d", static_cast<int>(map.data.size()));

  return 0;
}