
#include "pcl_tools/pcd_viewer.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "show_pcd_for_rviz");

	cout << "show pcd for rviz" << endl;
	cout << "\e[1m";
	cout << "open rviz and add topics to visualization before run" << endl;
	cout << "\e[0m";

	for(int i = 1; i != argc; ++i){
		pcl_tools::PointCloudDataViewer<pcl::PointXYZINormal> pcd_viewer(argv[i]);
	}

	return 0;
}

