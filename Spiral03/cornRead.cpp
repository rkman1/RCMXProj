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

//Global declaration of month arrays
std::array<int,5> mar = {1,0,0,0,0}; //H
std::array<int,5> may = {0,1,0,0,0}; //K
std::array<int,5> jul = {0,0,1,0,0}; //N
std::array<int,5> sep = {0,0,0,1,0}; //U
std::array<int,5> dec = {0,0,0,0,1}; //Z


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
	std::string ZC1 ("-");

	//Reading the entire file
	while (std::getline(inFile, item)){

		if (item.compare(0,2,"ZC") == 0) { //Classifys corn contracts
			if (item.compare(3,1,"0") == 0){ //Classifys contracts only from 2020
				if (item.find(ZC1) != std::string::npos){ //Creates spread path
					if (item.compare(5,2,"ZC") == 0) {  //filters 2020 corn future spreads only
						if (item.compare(8,1,"0") == 0) {
							char monthSymb = item[2];
							switch (monthSymb) { //Checks fronthalf of spread
								case 'H':
									char monthSymb1 = item[7];
									switch (monthSymb1) { //Checks backhalf of spread
										case 'K':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = mar[i] - may[i];
											}
											corn.push_back(temp);
											break;
										case 'N':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = mar[i] - jul[i];
											}
											corn.push_back(temp);
												break;
										case 'U':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = mar[i] - sep[i];
											}
											corn.push_back(temp);
												break;
										case 'Z':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = mar[i] - dec[i];
											}
											corn.push_back(temp);
												break;
										}
									break;
								case 'K':
									char monthSymb1 = item[7];
									switch (monthSymb1) { //Checks backhalf of spread
										case 'N':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = may[i] - jul[i];
											}
											corn.push_back(temp);
												break;
										case 'U':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = may[i] - sep[i];
											}
											corn.push_back(temp);
												break;
										case 'Z':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = may[i] - dec[i];
											}
											corn.push_back(temp);
												break;
										}
									break;
								case 'N':
									char monthSymb1 = item[7];
									switch (monthSymb1) { //Checks backhalf of spread
										case 'U':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = jul[i] - sep[i];
											}
											corn.push_back(temp);
												break;
										case 'Z':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
												temp[i] = jul[i] - dec[i];
											}
											corn.push_back(temp);
												break;
										}
									break;
								case 'U':
									char monthSymb1 = item[7];
									switch (monthSymb1) { //Checks backhalf of spread
										case 'Z':
											std::array<int,5> temp[5];
											for (int i = 0; i < 4; i++){
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
			// std::cout << corn[0][0] << '\n';
	return 0;
}
