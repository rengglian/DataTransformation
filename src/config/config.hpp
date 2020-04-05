#pragma once
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Config {

	public:

		Config(std::string fileName);
		~Config();
		
		void Read();

		const std::string GetDataFile() {return data_path;};
		const std::string GetTargetFile() {return target_path;};
		

	private:

	std::string data_path;
	std::string target_path;
};