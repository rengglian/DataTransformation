#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>
#include <opencv2/calib3d.hpp>

using json = nlohmann::json;

class Reader {

	public:

		Reader();
		~Reader();
		std::vector<cv::Point> JsonArray(const std::string& file);
};