/**********************************************
* File: sortedlldriver.cpp
* Author: Ray Kman
* Email: rkman@nd.edu
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

using namespace std;


int main() {

	ifstream inFile;
	inFile.open("corn.txt"); // Opens the File

	//Check for Error
	if(!inFile){
		cout << "Error reading file in." << endl;
		exit(1);
	}
	string item;
	string cornSymb;
	//Reading the entire file
	while (inFile != EOF){
		getline(inFile, item); //Reads in whole line as one string

		if (item.compare(0,3,"ZCF") == 0) { //Filters out non-Corn Futures
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) { //Checks for spread or outright
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCG") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCH") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCJ") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCK") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCM") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCN") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCQ") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCU") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCV") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCX") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) {
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
		if (item.compare(0,3,"ZCZ") == 0) {
			cout << item << " ";
			if (item.compare(4,1,"-") == 0) { 
				cout << "Spread" << endl;
			} else{
				cout << "Outright" << endl;
			}
		}
	}
	inFile.close();



	return 0;

}
