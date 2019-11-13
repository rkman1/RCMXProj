/**********************************************
* File: cornRead.cpp
* Author: Ray Kman & Connnor Grace
* Email: rkman@nd.edu, cgrace1@nd.edu
*
* This file contains the main driver function
* that reads the corn.txt file and prints out each
* symbol and whether or not it is an outright or
* a spread.
*
**********************************************/

#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::ifstream inFile;
	inFile.open("corn.txt"); // Opens the File

	//Check for Error
	if(!inFile){
		std::cout << "Error reading file in." << std::endl;
		exit(1);
	}
	std::string item;
	//Reading the entire file
	while (std::getline(inFile, item)){

		if (item.compare(0,3,"ZCF") == 0) { //Filters out non-Corn Futures
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) { //Checks for spread or outright
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCG") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCH") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCJ") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCK") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCM") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCN") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCQ") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCU") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCV") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCX") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
		if (item.compare(0,3,"ZCZ") == 0) {
			std::cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				std::cout << "Spread" << std::endl;
			} else{
				std::cout << "Outright" << std::endl;
			}
		}
	}
	inFile.close();



	return 0;

}
