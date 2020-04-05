#include "config.hpp"

Config::Config(std::string fileName) {
    std::ifstream i(fileName);
    json j;
    i >> j;
    
    data_path =  j.at("data"); 
    target_path = j.at("target"); 
}

Config::~Config() {

}