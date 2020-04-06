
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core/hal/interface.h>
#include <iostream>
#include <algorithm>

#include "config/config.hpp"
#include "reader/reader.hpp"
#include "calibrator/calibrator.hpp"
#include "draw/draw.hpp"

int main( int argc, char** argv )
{
	//Config config;
	std::unique_ptr<Config> config_ = std::make_unique<Config>(argc >=1 ? argv[1] : "./config.json");
	std::unique_ptr<Calibrator> calibrator_ = std::make_unique<Calibrator>();
	std::unique_ptr<Reader> reader_ = std::make_unique<Reader>();
	std::unique_ptr<Draw> draw_ = std::make_unique<Draw>();

	auto data = reader_->JsonArray(config_->GetDataFile());
	auto target = reader_->JsonArray(config_->GetTargetFile());

	auto centered = calibrator_->center(data);
	auto matrix = calibrator_->affine(centered, target);
	

	std::vector<double> euclideanDist;
	for (int i = 0; i < target.size(); i++)
	{
		double xDiff = target[i].x - centered[i].x;
    	double yDiff = target[i].y - centered[i].y;
		double result = std::sqrt((xDiff * xDiff) + (yDiff * yDiff));
		
    	euclideanDist.push_back(result);
	}

	std::sort(euclideanDist.begin(), euclideanDist.end(),std::greater<int>());

	std::cout << matrix << std::endl;
	std::cout <<  "mean: " << std::accumulate( euclideanDist.begin(), euclideanDist.end(), 0.0) / euclideanDist.size() << " min: " << *std::min_element(euclideanDist.begin(), euclideanDist.end()) << " max: " << *std::max_element(euclideanDist.begin(), euclideanDist.end()) <<std::endl;

	cv::Mat img(500, 500, CV_8UC3, cv::Scalar(255,255,255));

	draw_->addPoints(img, target, cv::Scalar(0,0,255));
	draw_->addPoints(img, centered, cv::Scalar(255,0,0));
	cv::imshow("centered", img);

	cv::waitKey();
	
    return 0;
}