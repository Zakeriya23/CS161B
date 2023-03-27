/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A05 CS161B
# Date:             5/20/2022
# Description:      This program will print out the number of occurance of a word 
# Input:            int number of wordCount char userString 
# Output:            char userString and the numList for countWords count 
of occurance of every word # Sources:          zybooks
#******************************************************************************/
#include <cctype>
#include <cstring>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
// prototypes
void readStrings(char userString[][20], int numList[], int &wordCount);
void printWordCount(char userString[][20], int numList[], int wordCount);
void countWords(char userString[][20], int numList[], int &wordCount);
void remove(int row, int &wordCount, char userString[][20], int numList[]);
void menu();
  

int main() {
  // DECLARE VARIABLE
  int wordCount;
  char userString[10][20];
  int numList[10] = {0};
  menu();
  readStrings(userString, numList, wordCount);
  cout << "\nYour list before deletes and counts:\n";
  printWordCount(userString, numList, wordCount);
  countWords(userString, numList, wordCount);
  for (int i = 0; i < wordCount; i++) {
    if (numList[i] > 1) {
      for (int j = i + 1; j < wordCount; j++) {
        if (strcmp(userString[i], userString[j]) == 0) {
          remove(j, wordCount, userString, numList);
          i--;
        }
      }
    }
  }
  cout << "\nThe frequency counts and list with unique words are as below:\n";
  printWordCount(userString, numList, wordCount);
cout << "\nThank you for using my frequency counter! " <<endl;
  return 0;
}// Name:   menu()
// Desc:   This function print out the main and welcoming 
// input:  none
// output: welcome message 
// return: none
 void menu(){
   cout << "Welcome to my Word Frequency Counter!!" << endl; 
   cout << "\nThis frequency will count the number of occurrences of each word. The number of words in your list must be entered first followed by the list of words separated by space. These are the rules of this frequency counter!" << endl;
     }

// Name:   readString(char userString[][20], int numList[], int &wordCount)
// Desc:   This function gets the inputs from the user
// input:  numList, char userString and char wordCount
// output: Maybe error message 
// return: none
void readStrings(char userString[][20], int numList[], int &wordCount) {
  cout << "\nEnter the count of words first (as a whole number) and the list of words separated by space: " << endl << endl;
  cin >> wordCount;
  while ((wordCount < 0) || (wordCount > 10)) {
    cout << "\nInvalid input please try again: ";
    cin >> wordCount;
  }
  for (int i = 0; i < wordCount; i++) {
    cin >> userString[i];
  }
}

// Name:   remove(int row, int &wordCount,char userString[][20], int numList[])
// Desc:   This function copies down the corresponding element that is in the numList 
// input:  none 
// output: numList 
// return: none
void remove(int row, int &wordCount, char userString[][20], int numList[]) {
  for (int i = row; i < wordCount; i++) {
    strcpy(userString[i], userString[i + 1]);
    numList[i] = numList[i + 1];
  }
  wordCount--;
}

// Name:   printWordCount(char userString[][20],int numList[], int wordCount)
// Desc:   This function prints out the list of the numbers and their occurance
// input:  none
// output: prints userString and numList
// return: none
void printWordCount(char userString[][20], int numList[], int wordCount) {
  for (int i = 0; i < wordCount; i++) {
  if(numList[i] == 0){
    cout << userString[i] << endl;
  }
    else{
    cout << userString[i] << '\t' << numList[i] << endl;
      }
  }
}

// Name:   countWords(char userString[][20],int numList[], int &wordCount)
// Desc:   This function does a frequencies test on userString and stores # in numList
// input:  none
// output: none
// return: none
void countWords(char userString[][20], int numList[], int &wordCount) {
  for (int i = 0; i < wordCount; i++) {
    for (int j = 0; j < wordCount; j++) {
      if (strcmp(userString[i], userString[j]) == 0) {
        numList[i]++;
      }
    }
  }
}