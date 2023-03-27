/******************************************************************************
# Author:      Zakeriya Muhumed
# Assignment:  Assignment 4
# Date:        April 22, 2022
# Description:  You will be writing a function that will remove all occurrences of one or more numbers by shifting the values in the array.
#
# Input:    a1 and a2
# Output:   modify list
# Sources:  Assignment 4 instructions
#******************************************************************************/
// libray
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// prototypes
void printOld(int a1[], int size);
void printNew(int a1[], int size);
void banish(int a1[], int size1, int a2[], int size2);
void deleteNum(int a1[],  int size1, int position);
// main function
int main() {
  //Builds the list of numbers
  int a1[] = {42, 3, 9, 42, 42, 0, 42, 9, 42, 42, 17, 8, 2222, 4, 9, 0, 1};
  //List of banish numbers
  int a2[] = {42, 2222, 9};
  //Printing Orign number
  printOld(a1,17);
  // Calling on functions
  banish(a1, 17, a2, 3);
  printNew(a1, 17);
  cout << "\nThank you for using this program";
  
  return 0;
}
  
//Name:   banish(int a1[], int size)
//Desc:   This function finds all repeating and a2 number from the list a1
//input:  a1,a2,size1,size2
//output: Maybe error message
//return: None
void banish(int a1[], int size1, int a2[], int size2){

  for (int i= 0; i < size2;i++) {
    for (int j= 0; j < size1;j++){
      if( a1[j] == a2[i]){
        int position = 0;
        position = j;
        deleteNum(a1,size1, position);
        j--;
        }
      }
    }
  }
//Name:   deleteANum(int list[], int &count, int deletePos)
//Desc:   This function takes a list, its size and a position and deletes the number from that position
//input:  int list[], int size, int position
//output: Maybe error message
//return: None
void deleteNum(int a1[], int size1, int position){
  for(int i= position; i < size1- 1; i++){
    a1[i]= a1[i+1];
    a1[i+1] = 0;
  }
  size1--;
}
//Name:   printOld/printNew(int a1[], int size)
//Desc:   This function prints the elements in the list.
//input:  a1 and the size
//output: Maybe error message
//return: None
void printOld(int a1[], int size1){
  int i;
  cout << "Your old Array: " ;
  for (i=0; i < size1; i++){
    cout << a1[i] << " ";
  }
  cout << endl;
}
void printNew(int a1[], int size1) {
  int i;
  cout << endl << "Your new Array: ";
  for (i=0; i < size1; i++){
    cout << a1[i] << " ";
  }
  cout << endl;
}
