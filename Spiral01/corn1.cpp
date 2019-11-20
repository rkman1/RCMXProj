#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	unsigned int Jan = 0;
	unsigned int Feb = 1;
	std::vector< unsigned int > corn;
	for (unsigned int i=Jan; i <= Feb; i++){
		corn.push_back(i); //initialize vector for 3 different contracts
	}
	std::ifstream inFile;
	inFile.open("corn2.txt"); // Opens the File

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
		corn[Jan] = 0;
		corn[Feb] = 0;
	while (std::getline(inFile, item)){

		if (item.compare(0,2,"ZC") == 0) { //Classifys corn contracts
			if (item.find(ZC1) != std::string::npos){ //Classifys corn spreads
				if (item.find(ZCF0) != std::string::npos){
									corn[Jan] += 1;
				}
				else if (item.find(ZCG0) != std::string::npos){
								corn[Feb] += 1;
				}
			}
		} else{ //Checks for only corn outrights
				if (item.find(ZCF0) != std::string::npos){
								corn[Jan] += 1;
				}
				else if (item.find(ZCG0) != std::string::npos){
								corn[Feb] += 1;
				}
			}
		} //closes original if loop
		for (unsigned int i = 0; i < corn.size(); i++) {
			std::cout << corn[(unsigned int)i] << std::endl;
		}
		return 0;
	}
