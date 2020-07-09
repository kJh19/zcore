
#include "ros/ros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include <std_srvs/Empty.h>

#include "tf/transform_broadcaster.h"

int main(int argc, char **argv)
{

    ros::init(argc, argv, "trans");

    ros::NodeHandle trans;

    ros::Rate loop_rate(1000);

    while (ros::ok()) {


        while (1) {

            static tf::TransformBroadcaster br;
            tf::Transform transform;
            transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
            tf::Quaternion q;
            q.setRPY(0, 0, 0);
            transform.setRotation(q);
            //br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "odom", "base_footprint"));
            //br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_footprint", "base_link"));
            //br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link", "base_laser_link"));

            ros::spinOnce();

            loop_rate.sleep();
        }
    }

    return 0;
}