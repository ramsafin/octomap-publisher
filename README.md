# OctoMap Publisher

## Getting Started

Install OctoMap packages:
```shell
sudo apt-get install ros-${ROS_DISTRO}-octomap-mapping ros-${ROS_DISTRO}-octomap-rviz-plugins
```

Publish static octomap:
```shell
 rosrun octomap_server octomap_server_node data/fr_078_tidyup.bt _frame_id:=map
```

Run the demo node (a simple service client):
```shell
rosrun octomap_publisher static_octomap_publisher
```

For visualization in RViz use MarkerArray on `occupied_cells_vis_array` topic.
