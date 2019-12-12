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
//Future spreads
std::vector<int> spread1 = {1,-1,0,0,0}; //ZCH0-ZCK0
std::vector<int> spread2 = {1,0,-1,0,0}; //ZCH0-ZCN0
std::vector<int> spread3 = {1,0,0,-1,0}; //ZCH0-ZCU0
std::vector<int> spread4 = {1,0,0,0,-1}; //ZCH0-ZCZ0
std::vector<int> spread5 = {0,1,-1,0,0}; //ZCK0-ZCN0
std::vector<int> spread6 = {0,1,0,-1,0}; //ZCK0-ZCU0
std::vector<int> spread7 = {0,1,0,0,-1}; //ZCK0-ZCZ0
std::vector<int> spread8 = {0,0,1,-1,0}; //ZCN0-ZCU0
std::vector<int> spread9 = {0,0,1,0,-1}; //ZCN0-ZCZ0
std::vector<int> spread10 = {0,0,0,1,-1};//ZCU0-ZCZ0

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
	std::string ZC1 = "-ZC";

	//Reading the entire file
	while (std::getline(inFile, item)){
		if (item.compare(0,2,"ZC") == 0 && item.compare(3,1,"0") == 0) { //Classifys corn contracts from 2020
			if (item.find(ZC1) != std::string::npos){ //Creates corn spread path
				if (item.compare(8,1,"0") == 0) {  //filters 2020 corn future spreads only
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
	//Accounting for outright sells
	corn.push_back(mar1);
	corn.push_back(may1);
	corn.push_back(jul1);
	corn.push_back(sep1);
	corn.push_back(dec1);


std::cout << corn.size() << " contracts found!" << '\n'; //Denotes how many contracts were found
std::cout <<
	"--------- Displaying All Contracts Read in --------- "
		<< '\n';
	//Prints each vector contained within the corn vector on its own line
	// 1s represent buys, 0 represent DNE, and -1s represent sells
	for (unsigned i = 0; i < corn.size(); i++) {
	std::vector <int> temp1 = corn.at(i);
		for(unsigned j = 0; j < temp1.size(); j++){
			std::cout << ' ' << temp1[j];
		}
		std::cout << std::endl;
	  }
		std::cout << std::endl;
	unsigned n = (unsigned)corn.size(); //number of vectors in the corn vector

	std::cout <<
		"--------- Analyzing Trading Relationships in Sets of Three--------- "
			<< '\n';
	//Determine which trading relationships work for 3 contracts at a time
	for (unsigned i = 0; i < n-2; i++) {
	  for (unsigned j = i+1; j < n-1; j++) {
	    for (unsigned k = i+2; k < n; k++) {
	      std::vector<int> temp2;
				std::vector<int> symb1;
				std::vector<int> symb2;
				std::vector<int> symb3;
	      for(unsigned z = 0; z <= 4; z++){
	        int res = corn[i][z] + corn[j][z] + corn[k][z]; //Sum of the three vectors element by element
					temp2.push_back(res);
	      }
				//Check to see if the temp2 vector is all zeros
				if (*max_element(temp2.begin(), temp2.end()) == 0
			&& *min_element(temp2.begin(), temp2.end()) == 0) {
						// Output contract combinations that work in vector form
					 for(unsigned x = 0; x <= 4; x++){
						symb1.push_back(corn[i][x]);
						std::cout << ' ' << corn[i][x];
					 }
					 std::cout << std::endl;
					 for(unsigned x = 0; x <= 4; x++){
						symb2.push_back(corn[j][x]);
						std::cout << ' ' << corn[j][x];
					 }
					 std::cout << std::endl;
					 for(unsigned x = 0; x <= 4; x++){
						symb3.push_back(corn[k][x]);
					 	std::cout << ' ' << corn[k][x];
					 }
					 std::cout << std::endl;

				   	//Output contract combinations that work in symbol form
						if (symb1 == mar){
							std::cout << " ZCH0 (Buy)" << std::endl;
						}
						if (symb1 == mar1){
							std::cout << " ZCH0 (Sell)" << std::endl;
						}
						if (symb1 == may) {
							std::cout << " ZCK0 (Buy)" << std::endl;
						}
						if (symb1 == may1) {
							std::cout << " ZCK0 (Sell)" << std::endl;
						}
						if (symb1 == jul) {
							std::cout << " ZCN0 (Buy)" << std::endl;
						}
						if (symb1 == jul1) {
							std::cout << " ZCN0 (Sell)" << std::endl;
						}
						if (symb1 == sep) {
							std::cout << " ZCU0 (Buy)" << std::endl;
						}
						if (symb1 == sep1) {
							std::cout << " ZCU0 (Sell)" << std::endl;
						}
						if (symb1 == dec) {
							std::cout << " ZCZ0 (Buy)" << std::endl;
						}
						if (symb1 == dec1) {
							std::cout << " ZCZ0 (Sell)" << std::endl;
						}
						if (symb1 == spread1){
							std::cout << " ZCH0-ZCK0" << std::endl;
						}
						if (symb1 == spread2){
							std::cout << " ZCH0-ZCN0" << std::endl;
						}
						if (symb1 == spread3){
							std::cout << " ZCH0-ZCU0" << std::endl;
						}
						if (symb1 == spread4){
							std::cout << " ZCH0-ZCZ0" << std::endl;
						}
						if (symb1 == spread5){
							std::cout << " ZCK0-ZCN0" << std::endl;
						}
						if (symb1 == spread6){
							std::cout << " ZCK0-ZCU0" << std::endl;
						}
						if (symb1 == spread7){
							std::cout << " ZCK0-ZCZ0" << std::endl;
						}
						if (symb1 == spread8){
							std::cout << " ZCN0-ZCU0" << std::endl;
						}
						if (symb1 == spread9){
							std::cout << " ZCN0-ZCZ0" << std::endl;
						}
						if (symb1 == spread10){
							std::cout << " ZCU0-ZCZ0" << std::endl;
						}

						if (symb2 == mar){
							std::cout << " ZCH0 (Buy)" << std::endl;
						}
						if (symb2 == mar1){
							std::cout << " ZCH0 (Sell)" << std::endl;
						}
						if (symb2 == may) {
							std::cout << " ZCK0 (Buy)" << std::endl;
						}
						if (symb2 == may1) {
							std::cout << " ZCK0 (Sell)" << std::endl;
						}
						if (symb2 == jul) {
							std::cout << " ZCN0 (Buy)" << std::endl;
						}
						if (symb2 == jul1) {
							std::cout << " ZCN0 (Sell)" << std::endl;
						}
						if (symb2 == sep) {
							std::cout << " ZCU0 (Buy)" << std::endl;
						}
						if (symb2 == sep1) {
							std::cout << " ZCU0 (Sell)" << std::endl;
						}
						if (symb2 == dec) {
							std::cout << " ZCZ0 (Buy)" << std::endl;
						}
						if (symb2 == dec1) {
							std::cout << " ZCZ0 (Sell)" << std::endl;
						}
						if (symb2 == spread1){
							std::cout << " ZCH0-ZCK0" << std::endl;
						}
						if (symb2 == spread2){
							std::cout << " ZCH0-ZCN0" << std::endl;
						}
						if (symb2 == spread3){
							std::cout << " ZCH0-ZCU0" << std::endl;
						}
						if (symb2 == spread4){
							std::cout << " ZCH0-ZCZ0" << std::endl;
						}
						if (symb2 == spread5){
							std::cout << " ZCK0-ZCN0" << std::endl;
						}
						if (symb2 == spread6){
							std::cout << " ZCK0-ZCU0" << std::endl;
						}
						if (symb2 == spread7){
							std::cout << " ZCK0-ZCZ0" << std::endl;
						}
						if (symb2 == spread8){
							std::cout << " ZCN0-ZCU0" << std::endl;
						}
						if (symb2 == spread9){
							std::cout << " ZCN0-ZCZ0" << std::endl;
						}
						if (symb2 == spread10){
							std::cout << " ZCU0-ZCZ0" << std::endl;
						}

						if (symb3 == mar){
							std::cout << " ZCH0 (Buy)" << std::endl;
						}
						if (symb3 == mar1){
							std::cout << " ZCH0 (Sell)" << std::endl;
						}
						if (symb3 == may) {
							std::cout << " ZCK0 (Buy)" << std::endl;
						}
						if (symb3 == may1) {
							std::cout << " ZCK0 (Sell)" << std::endl;
						}
						if (symb3 == jul) {
							std::cout << " ZCN0 (Buy)" << std::endl;
						}
						if (symb3 == jul1) {
							std::cout << " ZCN0 (Sell)" << std::endl;
						}
						if (symb3 == sep) {
							std::cout << " ZCU0 (Buy)" << std::endl;
						}
						if (symb3 == sep1) {
							std::cout << " ZCU0 (Sell)" << std::endl;
						}
						if (symb3 == dec) {
							std::cout << " ZCZ0 (Buy)" << std::endl;
						}
						if (symb3 == dec1) {
							std::cout << " ZCZ0 (Sell)" << std::endl;
						}
						if (symb3 == spread1){
							std::cout << " ZCH0-ZCK0" << std::endl;
						}
						if (symb3 == spread2){
							std::cout << " ZCH0-ZCN0" << std::endl;
						}
						if (symb3 == spread3){
							std::cout << " ZCH0-ZCU0" << std::endl;
						}
						if (symb3 == spread4){
							std::cout << " ZCH0-ZCZ0" << std::endl;
						}
						if (symb3 == spread5){
							std::cout << " ZCK0-ZCN0" << std::endl;
						}
						if (symb3 == spread6){
							std::cout << " ZCK0-ZCU0" << std::endl;
						}
						if (symb3 == spread7){
							std::cout << " ZCK0-ZCZ0" << std::endl;
						}
						if (symb3 == spread8){
							std::cout << " ZCN0-ZCU0" << std::endl;
						}
						if (symb3 == spread9){
							std::cout << " ZCN0-ZCZ0" << std::endl;
						}
						if (symb3 == spread10){
							std::cout << " ZCU0-ZCZ0" << std::endl;
						}
						std::cout<< std::endl;
					}
				 }
				}
	    }
	return 0;
}
