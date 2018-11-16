
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>
#include "pcl_tools/pcd_viewer.h"

namespace pcl_tools
{
	template<typename PointT>
	int PointCloudDataViewer<PointT>::id = 0;
	
	template<typename PointT>
	PointCloudDataViewer<PointT>::PointCloudDataViewer(const std::string& filename)
	 : pc(new PointCloud)
	{
		++id;
		std::string topic_name = "/pointcloud/fromPCD" + std::to_string(id);

		pub = n.advertise<sensor_msgs::PointCloud2>(topic_name, 10);

		if(pcl::io::loadPCDFile<PointT>(filename, *pc) < 0){
			std::cerr << "cant read " << filename << std::endl;
			return;
		}

		sensor_msgs::PointCloud2 pc2;
		pcl::toROSMsg(*pc, pc2);
		pc2.header.stamp = ros::Time::now();
		pc2.header.frame_id = "/map";
		ros::Rate roop(5);

		for(int i = 0; i != 3; ++i){
			pub.publish(pc2);
			roop.sleep();
		}

		std::cout << "published " << filename
				  << " (" << pc->points.size() << " points)" << std::endl;
		std::cout << "topic: " << topic_name;
		std::cout << ", frame_id: /map\n" << std::endl;
	}

	// template<typename PointT>
	// void PointCloudDataViewer<PointT>::publish()
	// {
	// }

	// pricate
} // namespace pcl_tools

