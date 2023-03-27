/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A07 (CS161B)
# Date:             June 10, 2022
# Description:      In this assignment, you will modify the program you wrote for Assignment 6 to use an array of structs. Each struct will hold the occupation name, the total number employed, and the number of employed susceptible to automation in that occupation.
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Assignment 7 specifications
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include "Occupation.h"

//function to open file and return true or false
bool openFile(ifstream &inFile);

//main function that will call openFile, loadData, printData, highPercent, low percent functions
int main()
{
	ifstream inFile;
	int rows = 0,total = 0, low=0 , medium = 0, high = 0;
  Occupation occupations[MAXCHAR],lowPercent, highPercent;
  
	if(!openFile(inFile))
	{
		cout << "File did not open! Program terminating!!" << endl;
		exit(0);
	}
	loadData(inFile,occupations,rows);
  printData(occupations, rows, low, medium, high);

  cout << fixed << setprecision(0);
  cout << "\nHighest/Lowest Occupations Susceptible to Automation:" << endl;
  highPercent=findHigh(rows, occupations);
  cout << highPercent.occupation << " has the highest share ("<< static_cast<double>(highPercent.automation) / static_cast<double>(highPercent.employed) *100<< "%)" << endl;
  lowPercent = findLow(rows, occupations);
  cout<< lowPercent.occupation << " has the lowest shares ("<<static_cast<double>(lowPercent.automation) / static_cast<double>(lowPercent.employed) *100 << "%)\n"<<endl;

  total = low + medium+ high;
  cout <<setw(3)<<  "\n#Highly susceptible: " << high << "  " << "("<< (high*100)/total << "%)"<< endl;
  cout << setw(3)<< "#Medium susceptible: "<< medium << " "<<"(" << (medium * 100)/total<< "%)" << endl;
  cout << setw(3)<< "#Low susceptible: " <<setw(6) << low << "("<<(low*100)/total <<  "%)" << endl;
	return 0;
}

//Name:		openFile
//Description:	opens the file and returns true or false
//input params:	file stream variable
//ouput:		none
//return:		true or false
bool openFile(ifstream &inFile)
{
	inFile.open("data.txt");
	if(!inFile)
	{
		return false;
	}
	return true;
}


		