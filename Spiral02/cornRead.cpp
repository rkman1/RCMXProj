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
#include <map>

int main() {
	// for (unsigned int i=Jan; i <= Mar; i++){
	// 	corn.push_back(i); //initialize vector for 3 different contracts
	// }
	std::ifstream inFile;
	inFile.open("corn2.txt"); // Opens the File

	//Check for Error
	if(!inFile){
		std::cout << "Error reading file in." << std::endl;
		exit(1);
	}
	std::string item;
	std::string ZC1 ("-ZC");
	unsigned int H = 0;
	unsigned int K = 1;
	unsigned int N = 2;
	unsigned int U = 3;
	unsigned int Z = 4;
	int vecCount = 1;
	//Reading the entire file
	while (std::getline(inFile, item)){

		if (item.compare(0,2,"ZC") == 0) { //Classifys corn contracts
			if (item.compare(8,1,"0") == 0){ //Classifys contracts only from 2020
				if (item.find(ZC1) != std::string::npos){
					std::cout << "";	 //Classifys corn spreads. Two logic streams outright and spreads
}
				//Classify outrights next
				else{
					if (item.compare(2,1,"H") == 0){
						for (int i = vecCount; i <= vecCount; i++) {
							std::vector< unsigned int > cornTradei; //Create vector for each trade
							for (unsigned int j = 0; j <= 4; j++){
								cornTradei.push_back(j); //initialize vector for 5 different contracts
							}
							cornTradei[H] = 1;
							}
							vecCount++;
						}
					else if (item.compare(2,1,"K") == 0){
						for (int i = vecCount; i <= vecCount; i++) {
							std::vector< unsigned int > cornTradei; //Create vector for each trade
							for (unsigned int j = 0; j <= 4; j++){
								cornTradei.push_back(j); //initialize vector for 5 different contracts
							}
							cornTradei[K] = 1;
							}
							vecCount++;
						}
					else if (item.compare(2,1,"N") == 0 ){
						for (int i = vecCount; i <= vecCount; i++) {
							std::vector< unsigned int > cornTradei; //Create vector for each trade
							for (unsigned int j = 0; j <= 4; j++){
								cornTradei.push_back(j); //initialize vector for 5 different contracts
							}
							cornTradei[N] = 1;
							}
							vecCount++;
						}
					else if (item.compare(2,1,"U") == 0){
						for (int i = vecCount; i <= vecCount; i++) {
							std::vector< unsigned int > cornTradei; //Create vector for each trade
							for (unsigned int j = 0; j <= 4; j++){
								cornTradei.push_back(j); //initialize vector for 5 different contracts
							}
							cornTradei[U] = 1;
							}
							vecCount++;
						}
					else if (item.compare(2,1,"Z") == 0){
						for (int i = vecCount; i <= vecCount; i++) {
							std::vector< unsigned int > cornTradei; //Create vector for each trade
							for (unsigned int j = 0; j <= 4; j++){
								cornTradei.push_back(j); //initialize vector for 5 different contracts
							}
							cornTradei[Z] = 1;
							}
							vecCount++;
							}
						}
					}
				}
			}
				for (int i = 1; i <= vecCount; i++) {
					for (unsigned int j = 0; j < cornTradei.size(); j++) {
						std::cout << cornTradei[j] << std::endl;
					}
				}
				return 0;
			}
