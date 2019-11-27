/**********************************************
* File: cornRead.cpp
* Author: Ray Kman & Connor Grace
* Email: rkman@nd.edu, cgrace1@nd.edu
*
* This file contains the main driver function
* that reads the corn.txt file and sorts the corn
* futures for 2020
**********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>

//Global declaration of month arrays
std::array<int,5> mar = {1,0,0,0,0};
std::array<int,5> may = {0,1,0,0,0};
std::array<int,5> jul = {0,0,1,0,0};
std::array<int,5> sep = {0,0,0,1,0};
std::array<int,5> dec = {0,0,0,0,1};

int main() {
	std::ifstream inFile;
	inFile.open("corn2.txt"); // Opens the File

	//Check for Error
	if(!inFile){
		std::cout << "Error reading file in." << std::endl;
		exit(1);
	}

	//Variable Declaration
	std::vector <std::array<int,5>> corn;
	std::string item;
	std::string ZC1 ("-ZC");

	//Reading the entire file
	while (std::getline(inFile, item)){

		if (item.compare(0,2,"ZC") == 0) { //Classifys corn contracts
			if (item.compare(8,1,"0") == 0){ //Classifys contracts only from 2020
				if (item.find(ZC1) != std::string::npos){ //Creates spread path
					char monthSymb = item[2];
					switch (monthSymb) {
						case 'H':
							corn.push_back(mar);
							break;
						case 'K':
							corn.push_back(may);
							break;
						case 'N':
							corn.push_back(jul);
							break;
						case 'U':
							corn.push_back(sep);
							break;
						case 'Z':
							corn.push_back(dec);
							break;
					}
				}
			}
			else{ //Creates outright path
				char monthSymb = item[2];
				switch (monthSymb) {
					case 'H':
						corn.push_back(mar);
						break;
					case 'K':
						corn.push_back(may);
						break;
					case 'N':
						corn.push_back(jul);
						break;
					case 'U':
						corn.push_back(sep);
						break;
					case 'Z':
						corn.push_back(dec);
						break;
				}
			}
		}
	}
			// std::cout << corn[0][0] << '\n';
	return 0;
}
