// Occupation.h
//struct file for  Occupation type
#pragma once
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//constant for number of characters
const int MAXCHAR = 101;

//struct  Occupation
struct  Occupation {
char occupation[MAXCHAR];
int employed;
int automation;
};

//function prototypes
void loadData(ifstream &inFile,Occupation occupations[],int &rows);
//function to print the  Occupations
void printData(Occupation occupation[],int rows, int &low, int &medium, int &high);
Occupation findHigh(int rows, Occupation occupation[]);
Occupation findLow(int rows, Occupation occupation[]);