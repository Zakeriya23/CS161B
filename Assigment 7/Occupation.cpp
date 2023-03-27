//implementation file for struct  Occupation
#include "Occupation.h"

//Name:  loadData
//Description: loads data from file
//input params:  infile, occupation occupations[], rows
//output:    none
//return:    none
void loadData(ifstream &inFile,Occupation occupations[],int &rows){
	inFile.getline(occupations[rows].occupation, MAXCHAR, ';');
	while(!inFile.eof()){
		//read the next 2 int data 
		inFile >> occupations[rows].employed;
		inFile.ignore(5, ';');
		inFile >>occupations[rows].automation;
		inFile.ignore(5, '\n');
		//increment rows for next  Occupation
		rows++;
		//read next  Occupation occupation from the next line in the text file
		inFile.getline(occupations[rows].occupation, MAXCHAR, ';');
	}
}

// name:  printData
// Desc: This function print out the occupation name, employed, automation, percent and tier also counting each tier
// input:  none 
// output: occupation name, employed, automation, percent, and tier
// percent return: none
void printData(Occupation occupations[],int rows, int &low, int &medium, int &high){
  double percent;
  cout << fixed <<setprecision(4);
  cout << left;
  cout << setw(25) << "Occupation Name " << setw(10) << "Employed"<< setw(15) << "Automation" << setw(15) << "Percent %" << "Tier"<<endl << endl;
  
  for(int i = 0; i < rows; i++){
    percent = static_cast<double>(occupations[i].automation) / static_cast<double>(occupations[i].employed) *100;
cout << setw(25) << occupations[i].occupation << setw(10) << occupations[i].employed << setw(15)<< occupations[i].automation; 
cout  <<  percent <<setw(8)<< "%";
   
//CHALLENGE
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
// Name: findHigh (int rows, Occupation occupation[])
// Desc:   This function is going to look for the highest percentage and reurns it
// input:  none
// output: The highest percent and the occupation name 
// return: none
Occupation findHigh(int rows, Occupation occupations[]){
  double highPercent = 0;
  double percent;
  int i = 0;
  for(int k = 0; k < rows; k++){
    percent = static_cast<double>(occupations[k].automation) / static_cast<double>(occupations[k].employed) *100;
    
    if(k == 0){
      highPercent = percent;
    }
    if (highPercent <= percent) {
      highPercent = percent;
      i = k;
    }
}
  return occupations[i];
  }
// Name: findlow (int rows, char occupation[])
// Desc:   This function is going to look for the lowest percentage and returns it
// input:  none
// output: the lowest percent and the occupation name
// return: none
Occupation findLow(int rows, Occupation occupations[]){
  double lowPercent = 0, percent;
  int i=0;
  for(int k = 0; k < rows; k++){
    percent = static_cast<double>(occupations[k].automation) / static_cast<double>(occupations[k].employed) *100;
    if(k == 0){
      lowPercent = percent;
    }
    if (lowPercent >= percent){
      lowPercent = percent;
      i =k;
    }
}
   return occupations[i];
}