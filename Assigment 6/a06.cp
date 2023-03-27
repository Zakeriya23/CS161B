/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A06
# Date:             5/26/2022
# Description:     reads in information from a file that includes total employment numbers and the number of employees susceptible for automation for each major occupation as defined by the Bureau of Labor Statistics. The program will output the occupations with the highest and lowest percentages of jobs susceptible to automation 
# Input:            data.txt
# Output:       A table with all the percent and display highest percent and lowest percent and tier with count
# Sources:         assigment 6 instructions
#******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

//constant for number of rows
const int ITEMS = 30;
//constant for number of characters
const int MAXCHAR = 20;

//function prototypes
bool openFile(ifstream &inFile);
void loadData(ifstream &infile, char occupations[][20], int nums[][2], int &rows);
void printData(char occupations[][20], int nums[][2], int rows, int &low, int &medium,int &high);
void findHigh(char occupations[][20], int nums[][2], int rows, char occupation[], double &highPercent);
void findLow(char occupations[][20], int nums[][2], int rows, char occupation[], double &lowPercent);

//main function
int main(){
  ifstream inFile;
  int rows = 0, low = 0, medium = 0, high = 0, total = 0;
  double highPercent = 0, lowPercent =0;
  char occupations[ITEMS][20];
  char occupation[ITEMS];
  int nums[ITEMS][2] = {0};

    if(!openFile(inFile)){
        cout << "File did not open! Program terminating!!" << endl;
        exit(0);
    }

    loadData(inFile,occupations, nums,rows);
    printData(occupations, nums, rows, low, medium, high);

  //High and lows function and printing
  cout << fixed << setprecision(0);
  cout << "\nHighest/Lowest Occupations Susceptible to Automation:" << endl;
  findHigh(occupations, nums, rows, occupation, highPercent);
  cout << occupation << " has the highest share (" << highPercent << "%)" << endl;
  findLow(occupations, nums, rows, occupation, lowPercent);
  cout<< occupation << " has the lowest shares ("<< lowPercent << "%)\n"<<endl;

  //Challenge
  total = low + medium+ high;
  cout <<setw(3)<<  "\n#Highly susceptible: " << high << "  " << "("<< (high*100)/total << "%)"<< endl;
  cout << setw(3)<< "#Medium susceptible: "<< medium << " "<<"(" << (medium * 100)/total<< "%)" << endl;
  cout << setw(3)<< "#Low susceptible: " <<setw(6) << low << "("<<(low*100)/total <<  "%)" << endl;

    return 0;
}
//Name:        openFile(ifstream &inFile)
//Description:    opens the file and returns true or false
//input params:    file stream variable
//ouput:        none
//return:        true or false
//
bool openFile(ifstream &inFile)
{
    inFile.open("data.txt");
    if(!inFile)
    {
        return false;
    }
    return true;
}

//Name:  loadData(ifstream &inFile, char occupations[][20], int nums[][2], int &rows)
//Description: loads data from file
//input params:  char array for occupation, and int array for num (2 dim arrays) and rows to count
//output:    none
//return:    none
void loadData(ifstream &inFile, char occupations[][20], int nums[][2], int &rows){
   int j = 0, k = 1;
    //read the first item name outside to check if the file is empty
    inFile.getline(occupations[rows], MAXCHAR, ';');
    while(!inFile.eof()){
        //read the next 2 int data into the int 2 dim array
        inFile >> nums[rows][j];
        inFile.ignore(5, ';');
        inFile >> nums[rows][k];
        inFile.ignore(5, '\n');
        //increment count for next item
      rows++;
        //read next occipation from the next line in the text file
        inFile.getline(occupations[rows], MAXCHAR, ';');
    }
    }

// Name:  printData(char occupations[][20], int nums[][2], int rows, int &low, int &medium, int &high)
// Desc: This function print out the occupation name, employed, automation, percent and tier also counting each tier
// input:  none
// output: occupation name, employed, automation, percent, and tier
// percent return: none
void printData(char occupations[][20], int nums[][2], int rows, int &low, int &medium, int &high){
  int j = 0, k = 1, i =0;
  double percent;
  cout << fixed <<setprecision(4);
  cout << left;
  cout << setw(25) << "Occupation Name " << setw(10) << "Employed"<< setw(15) << "Automation" << setw(15) << "Percent %" << "Tier"<<endl << endl;

  for(i=0; i < rows ; ++i){
  percent = (static_cast<double>(nums[i][1])/nums[i][0]) * 100;
  cout << setw(25) << occupations[i] << setw(10) << nums[i][j] << setw(15)<< nums[i][k];
  cout  <<  percent  <<setw(8)<< "%";

    //challenge
    if(percent>=70){
      cout << "High" << endl;
      high++;
    }
    else if (percent>=30 && percent <=70){
      cout << "Medium" << endl;
      medium++;
    }
    else if (percent <30){
      cout << "Low" <<endl;
      low++;
    }
  }
  }

// Name: findHigh(char occupations[][20], int nums[][2], int rows, char occupation[], double &highPercent)
// Desc:   This function looks for the highest percentage and copies down the name from one array to new
// input:  none
// output: The highest percent and the occupation name
// return: none
void findHigh(char occupations[][20], int nums[][2], int rows, char occupation[], double &highPercent){
   int i =0;
for(i = 0; i< rows; ++i){
  int percent= (nums[i][1]*100) /nums[i][0];
  if (i== 0){
    highPercent = percent;
    strcpy(occupation, occupations[i]);
  }
  if(highPercent<= percent){
    highPercent = percent;
    strcpy(occupation, occupations[i]);
  }
}
}

// Name: findlow(char occupations[][20], int nums[][2], int rows, char occupation[], double &lowPercent)
// Desc:   This function looks for the lowest percentage
// input:  none
// output: the lowest percent and the occupation name
// return: none
void findLow(char occupations[][20], int nums[][2], int rows, char occupation[], double &lowPercent){
    int i =0;
  for(i = 0; i< rows; ++i){
  int percent = (nums[i][1]*100) /nums[i][0];
  if (i== 0){
    lowPercent = percent;
    strcpy(occupation, occupations[i]);
  }
  if(lowPercent>= percent){
    lowPercent = percent;
    strcpy(occupation, occupations[i]);
  }
}
}
