#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

class Draw {

	public:

		Draw();
		~Draw();
		void addPoints(const cv::Mat& src, const std::vector<cv::Point>& points, const cv::Scalar& color);
	private:

};