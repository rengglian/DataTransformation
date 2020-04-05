#include "reader.hpp"


Reader::Reader(){
}

Reader::~Reader() {}

std::vector<cv::Point> Reader::JsonArray(const std::string& file) {
	std::vector<cv::Point> array;
    std::ifstream f(file);
    if(!f) {
        std::cout << "Failed to open file: " << file << std::endl;
        array.push_back(cv::Point(0, 0));
    } else {
        json j = json::parse(f);
        for (auto& element : j) {
            std::string str = element;
            std::replace(str.begin(), str.end(), ',',' ');
            std::stringstream ss(str);
            cv::Point pt{0, 0};
            ss >> pt.x >> pt.y;       
            array.push_back(pt);   
        }
    }
	return array;
}