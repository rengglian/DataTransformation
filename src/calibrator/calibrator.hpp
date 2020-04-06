#pragma once

#include <opencv2/calib3d.hpp>
#include <numeric>
#include <iostream>

class Calibrator {

	public:

		Calibrator();
		~Calibrator();
		cv::Mat affine(const std::vector<cv::Point>& data, const std::vector<cv::Point>& target);
		std::vector<cv::Point> center(const std::vector<cv::Point>& data);
};