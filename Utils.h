#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using std::string;

typedef enum _MEAL_TYPE
{
	VEG_MEAL_ORDER = 1,
	NONVEG_MEAL_ORDER = 2,
	VEG_MEAL_READY = 3,
	NONVEG_MEAL_READY = 4,
} MEAL_TYPE;

class FileClass
{
public:
	static void writeToFile(string str);
};

void FileClass::writeToFile(string str)
{
	ofstream myfile;
	myfile.open("logs.txt", ios::app);
	myfile << str << endl;
	myfile.close();
}