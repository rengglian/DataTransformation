#include "calibrator.hpp"


Calibrator::Calibrator(){
	
}

Calibrator::~Calibrator() {}

cv::Mat Calibrator::affine(const std::vector<cv::Point>& data, const std::vector<cv::Point>& target) {


	std::vector<uchar> inliers(target.size(), 0);
	return cv::estimateAffine2D(data, target, inliers, cv::RANSAC);
}

std::vector<cv::Point> Calibrator::center(const std::vector<cv::Point>& data) {
	const cv::Point avg_data = std::accumulate(data.begin(), data.end(), cv::Point(0,0), std::plus<cv::Point>()) / static_cast<int>(data.size());

	std::vector<cv::Point> centered;
	for (const auto& pt : data)
    {  
		centered.push_back(pt-avg_data);
    }
	return centered;
}
