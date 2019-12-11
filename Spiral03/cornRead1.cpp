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
#include <algorithm>
#include <functional>

//Global declaration of month vectors
std::vector<int> mar = {1,0,0,0,0}; //H
std::vector<int> may = {0,1,0,0,0}; //K
std::vector<int> jul = {0,0,1,0,0}; //N
std::vector<int> sep = {0,0,0,1,0}; //U
std::vector<int> dec = {0,0,0,0,1}; //Z
//Negative outrights
std::vector<int> mar1 = {-1,0,0,0,0}; //-H
std::vector<int> may1 = {0,-1,0,0,0}; //-K
std::vector<int> jul1 = {0,0,-1,0,0}; //-N
std::vector<int> sep1 = {0,0,0,-1,0}; //-U
std::vector<int> dec1 = {0,0,0,0,-1}; //-Z


int main() {
	std::ifstream inFile;
	inFile.open("corn.txt"); // Opens the File

	//Check for Error
	if(!inFile){
		std::cout << "Error reading file in." << std::endl;
		exit(1);
	}

	//Variable Declaration
	std::vector <std::vector<int>> corn;
	std::string item;
	std::string ZC1 = "-";

	//Reading the entire file
	while (std::getline(inFile, item)){
		if (item.compare(0,2,"ZC") == 0) { //Classifys corn contracts
			if (item.compare(3,1,"0") == 0){ //Classifys contracts only from 2020
				if (item.find(ZC1) != std::string::npos){ //Creates spread path
					if (item.compare(5,2,"ZC") == 0) {  //filters 2020 corn future spreads only
						if (item.compare(8,1,"0") == 0) {
							char monthSymb = item[2];
							char monthSymb1 = item[7];
							std::vector<int> temp (5);
							switch (monthSymb) { //Checks fronthalf of spread
								case 'H':
									switch (monthSymb1) { //Checks backhalf of spread
										case 'K':
											for (unsigned i = 0; i <= 4; i++){
												temp[i] = mar[i] - may[i];
											}
											corn.push_back(temp);
											break;
										case 'N':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = mar[i] - jul[i];
										}
											corn.push_back(temp);
											break;
										case 'U':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = mar[i] - sep[i];
										}
											corn.push_back(temp);
											break;
										case 'Z':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = mar[i] - dec[i];
										}
											corn.push_back(temp);
											break;
										}
									break;
								case 'K':
									switch (monthSymb1) { //Checks backhalf of spread
										case 'N':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = may[i] - jul[i];
											}
											corn.push_back(temp);
											break;
										case 'U':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = may[i] - sep[i];
										}
											corn.push_back(temp);
											break;
										case 'Z':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = may[i] - dec[i];
										}
											corn.push_back(temp);
											break;
										}
									break;
								case 'N':
									switch (monthSymb1) { //Checks backhalf of spread
										case 'U':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = jul[i] - sep[i];
										}
												corn.push_back(temp);
												break;
										case 'Z':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = jul[i] - dec[i];
										}
												corn.push_back(temp);
												break;
										}
									break;
								case 'U':
									switch (monthSymb1) { //Checks backhalf of spread
										case 'Z':
										for (unsigned i = 0; i <= 4; i++){
											temp[i] = sep[i] - dec[i];
										}
											corn.push_back(temp);
											break;
										}
									break;
								}
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
}

	corn.push_back(mar1);
	corn.push_back(may1);
	corn.push_back(jul1);
	corn.push_back(sep1);
	corn.push_back(dec1);

//	std::cout << corn.size() << '\n'; /denotes how many contracts were found

	//Print each vector contained within the corn vector on its own line
	// 1s represent buys, 0 represent DNE, and -1s represent sells
	for (unsigned i = 0; i < corn.size(); i++) {
	std::vector <int> temp1 = corn.at(i);
		for(unsigned j = 0; j < temp1.size(); j++){
			std::cout << ' ' << temp1[j];
		}
		std::cout << std::endl;
	  }
		std::cout << std::endl;
	unsigned n = 20; //number of vectors in the corn vector

	//Determine which trading relationships work for 3 contracts at a time
	for (unsigned i = 0; i < n-2; i++) {
	  for (unsigned j = i+1; j < n-1; j++) {
	    for (unsigned k = j+1; k < n; k++) {
	      std::vector<int> temp2;
	      for(unsigned z = 0; z <= 4; z++){
	        int res = corn[i][z] + corn[j][z] + corn[k][z];
					temp2.push_back(res);
	      }
				if (*max_element(temp2.begin(), temp2.end()) == 0
			&& *min_element(temp2.begin(), temp2.end()) == 0) {
					for(unsigned x = 0; x <= 4; x++){
						std::cout << ' ' << corn[i][x];
					}
					std::cout << std::endl;
					for(unsigned x = 0; x <= 4; x++){
						std::cout << ' ' << corn[j][x];
					}
					std::cout << std::endl;
					for(unsigned x = 0; x <= 4; x++){
						std::cout << ' ' << corn[k][x];
					}
					std::cout << std::endl;
					std::cout << std::endl;
				  }
				}
	    }
	  }


	return 0;
}
