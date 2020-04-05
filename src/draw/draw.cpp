#include "draw.hpp"

Draw::Draw() {}

Draw::~Draw() {}

void Draw::addPoints(const cv::Mat& src, const std::vector<cv::Point>& points, const cv::Scalar& color){
    
    cv::Mat tmp = src;

    cv::Rect r = cv::boundingRect(points);
  
    for (const auto& spot : points)
    {
            cv::Point pt = spot;
  
            pt.x = pt.x * (tmp.cols*0.75) / r.width;
            pt.x += tmp.cols/2;
            pt.y = pt.y  * (tmp.rows*0.75) / r.height;
            pt.y += tmp.rows/2;
            cv::circle( tmp, pt, 2, color, 1, cv::LINE_4);
    }
}