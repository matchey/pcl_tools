
#ifndef __PCD_VIEWER_H
#define __PCD_VIEWER_H

#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace pcl_tools
{
	template<typename PointT>
	class PointCloudDataViewer
	{
		public:
		using PointCloud = pcl::PointCloud<PointT>;
		using PointCloudPtr = typename PointCloud::Ptr;

		PointCloudDataViewer(const std::string&);

		private:
		// void publish();

		static int id;
		ros::NodeHandle n;
		ros::Publisher pub;

		PointCloudPtr pc;
	};

	template class PointCloudDataViewer<pcl::PointXYZ>;
	template class PointCloudDataViewer<pcl::PointXYZI>;
	template class PointCloudDataViewer<pcl::PointNormal>;
	template class PointCloudDataViewer<pcl::PointXYZINormal>;
} // namespace pcl_tools

#endif

