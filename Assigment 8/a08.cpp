/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A08 (CS161B)
# Date:             June 14, 2022
# Description:      In this assignment, you will create a single source code file that uses pointer variables and functions.
# Input:            user input *x and *y
# Output:           none
# Sources:          Assignment 8 instruction
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//function pro
void swapArgs(int *, int *);
void divideArgs(int *, int *);
void powerArgs(int *, int *);

int main() {

int *x=new int;
int *y=new int;

cout << "Enter integer 1: ";
cin >> *x;
cout << "\nEnter integer 2: ";
cin >> *y;


if(*x== *y){
  cout << "No operations performed!" << endl;
 return 0;
}

cout << "\nBefore call to swapArgs a:" << *x << " b:" << *y << endl;
swapArgs(x, y);
cout << "\nAfter call to swapArgs a:"<< *x <<" b:" << *y << endl;

divideArgs(x, y);
  cout << "\nAfter call to divideArgs a:"<< *x <<" b:" << *y << endl;

powerArgs(x, y);
cout << "\nAfter call to powerArgs a:"<< *x <<" b:" << *y << endl;

cout <<"\nGoodbye!";
  return 0;
}

//Name:        void swapArgs(int *x, int *y
//Description:		swaps *x and *y
//input params:    *x and * y
//ouput:        none
//return:        none
void swapArgs(int *x, int *y){
  int tempVal= *x;
  *x= *y;
  *y= tempVal;
}

//Name:        void divideArgs(int *x, int *y
//Description:          Muliples *x and *y using temp variables
//input params:    *x and * y
//ouput:        none
//return:        none
void divideArgs(int *x, int *y){
  int temp1 = *x;
  int temp2 = *y;

  *x= (temp1 / temp2);
  *y= (temp1 % temp2);
}

//Name:        void powersArgs(int *x, int *y
//Description:	powers *x and *y
//input params:    *x and * y
//ouput:        none
//return:        none
void powerArgs(int *x, int *y){
int tempVal = *x;

if (*y == 0) {
*x = 1;
}
else if (*y < 0) {
 for (int i = 0; i < *y - 1; i++) {
 *x = 1 / (*x*tempVal);
}
}
else {
  for (int i = 0; i < *y - 1; i++) {
  *x *= tempVal;
  }
}
}

