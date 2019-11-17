/**********************************************
* File: cornRead.cpp
* Author: Ray Kman & Connor Grace
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
#include <vector>

int main() {
//	int cornCount1 = 1; //counter for number of times the contract appears
	// int cornCount2 = 1;
	int Jan = 0;
	int Feb = 1;
	std::vector< unsigned int > corn;
	for (unsigned int i=0; i <= 1; i++){
		corn.push_back(i); //initialize vector for 2 different contracts
	}
	std::ifstream inFile;
	inFile.open("corn.txt"); // Opens the File

	//Check for Error
	if(!inFile){
		std::cout << "Error reading file in." << std::endl;
		exit(1);
	}
	std::string item;
	std::string ZC1 ("-ZC");
	std::string ZCF0 ("ZCF0");
	std::string ZCG0 ("ZCG0");
	//Reading the entire file
	while (std::getline(inFile, item)){

		if (item.compare(0,2,"ZC") == 0) { //Classifys corn contracts
			if (item.find(ZC1) != std::string::npos){ //Classifys corn spreads
				if (item.find(ZCF0) != std::string::npos){
									corn[(unsigned int)Jan] += 1;

				}
				if (item.find(ZCG0) != std::string::npos){
								corn[(unsigned int)Feb] += 1;
				}
			} else{ //Checks for only corn outrights
					if (item.find(ZCF0) != std::string::npos){
								corn[(unsigned int)Jan] += 1;
					}
				}
			} //closes original if loop
		}
		for (unsigned int i = 0; i < corn.size(); i++) {
			std::cout << corn[(unsigned int)i] << std::endl;
		}

		return 0;
	}
