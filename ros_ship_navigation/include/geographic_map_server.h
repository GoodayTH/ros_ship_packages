#ifndef GEOGRAPHIC_MAP_SERVER_H_INCLUDED
#define GEOGRAPHIC_MAP_SERVER_H_INCLUDED

//headers in this package
#include <osm_node.h>
#include <osm_way.h>

//headers in ROS
#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/Imu.h>

//headers in stl
#include <vector>

class geographic_map_server
{
public:
  geographic_map_server();
  ~geographic_map_server();
private:
  //members for ROS
  ros::NodeHandle nh_;
  ros::Subscriber fix_sub_,imu_sub_;
  void fix_callback(sensor_msgs::NavSatFix msg);
  void imu_callback(sensor_msgs::Imu msg);
  //members for osm
  void parse_osm();
  void get_osm_way();
  std::string osm_filepath_;
  std::vector<osm_node*> osm_nodes_;
  std::vector<osm_way*> osm_ways_;
  //members for geographic function
  double earth_radius_;
};
#endif //GEOGRAPHIC_MAP_SERVER_H_INCLUDED
