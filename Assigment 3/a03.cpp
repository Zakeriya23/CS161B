/******************************************************************************
# Author:      Zakeriya Muhumed
# Assignment:  Assignment 3
# Date:        April 22, 2022
# Description:  This program  is a menu driven program to build a customized membership that works for the user. You will give the user a menu with some choice. Based on the choice they pick,
#              you will ask them some questions and give them results. This process will repeat until they choose to quit the program. The purpose of this assignment is to modularize your program.
# Input:       char clubType, int numMonth, int numTrain
# Output:      membership cost, training cost,total cost
# Sources:     Assignment 03 Document https://www.w3schools.com/cpp/cpp_switch.asp for switchs
#******************************************************************************/
// libray
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// prototypes
void welcome();
void displayMenu();
void getInfo(char &clubType, int &numMonth, int &numTrain);
void calcCost(char clubType, int numMonth, int numTrain, double totalCost);
char readChar(string prompt);
int readInt(string prompt);
// main function
int main() {
  char userChoice = '\0';
  char clubType = '\0';
  int numMonth = 0, numTrain = 0;
  double totalCost = 0.00;

  cout << fixed << setprecision(2) << endl;
  welcome();

  do {
    displayMenu();
    do{
    userChoice = readChar(">>");
      }while(userChoice != 'Q' && userChoice != 'C');
    switch (userChoice){
      case 'C':
        getInfo(clubType, numMonth, numTrain);
        calcCost(clubType, numMonth, numTrain, totalCost);
        break;
      case 'Q':
        cout << "Thank you for using the Fitneess Club Program!! ";
        cout << "See you next time!" << endl;
        break;
      }
  } while (userChoice != 'Q');
  return 0;
}

//Name: welcome()
//Desc: This function displays the welcome message
//input: None
//output: None
//return: None
void welcome() {
  cout << "\nWelcome to my fitClub program!!" << endl;
  cout << "The cost to become a member of the fitClub center is as follows:";
  cout << endl;
  cout << "\nThe membership fee per month for Sports Club is $20.00" << endl;
  cout << "\nThe membership fee per month for Ultra Sports Club is $30.00";
  cout << endl;
  cout << "\nIf the membership is bought and paid for 12 or more months,";
  cout << "\nthe discount is 10% off membership cost" << endl;
  cout << "\nPersonal training session are $10.00 per session" << endl;
  cout << "\nIf more than five personal training session ";
  cout << "are bought and paid for,";
  cout << "\nthe discount on each session is 20%" << endl;
}

//Name: displayMenu()
//Desc: This function displays a message with the users choices
//input: None
//output: None
//return: None
void displayMenu() {
  cout << "\nPlease pick one of the following options: " << endl;
  cout << "\n      (C/c) Calculate membership costs." << endl;
  cout << "      (Q/q) quit this program." << endl;
  cout << ">> ";
}

//Name: getInfo()
//Desc: This function gets input from user and displays prompts
//input: clubType, numMonth, and numTrain by reference
//output: Input message
//return: None
void getInfo(char &clubType, int &numMonth, int &numTrain) {
  do{
  clubType = readChar("Would you prefer (S)ports or (U)ltra Sports Club: ");
    } while (clubType != 'S' && clubType != 'U');
  numMonth = readInt("How many months's of membership would you like? ");
  numTrain = readInt("How many personal training sessions would you like? ");
  cout << endl;
}

//Name: calcCost(char clubType, int numMonth, int numTrain, double totalCost)
//Desc: This function calculates the cost of membership with discounts
//input: clubType, numMonth, and numTrain
//output: All the cost and discounts
//return: None
void calcCost(char clubType, int numMonth, int numTrain, double totalCost) {
  double membershipCost = 0.00;
  double trainCost = numTrain * 10.00;
  double discount1 = 0.00;
  double discount2 = 0.00;

  switch (clubType) {
    case 'S':
      membershipCost = numMonth * 20.00;
      break;
    case 'U':
      membershipCost = numMonth * 30.00;
      break;
    }
  if (numTrain > 5) {
    discount2 = trainCost * 0.20;
    trainCost = trainCost - discount2;
  }
  if (numMonth >= 12) {
    discount1 = membershipCost * 0.10;
    membershipCost = membershipCost - discount1;
    cout << "Your membership cost after 10% discount was applied: $";
    cout << membershipCost << endl;
  }
  totalCost = membershipCost + trainCost;
  cout << "Your personal training cost for " << numTrain << " session(s) is $";
  cout << trainCost << endl;
  cout << "Your total cost is: $";
  cout << totalCost << endl;
}

//Name:     readChar()
//Desc:     This function reads the clubType, validates and returns it
//input:    None
//output:   Possibly a error message
//return:   tempChar
char readChar(string prompt) {
  char tempChar = '\0';
  cout << prompt;
  cin >> tempChar;
  tempChar = toupper(tempChar);

  while (!cin) {
    cout << "Invalid membership type, Please try again!" << endl;
    cout << prompt;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> tempChar;
    tempChar = toupper(tempChar);
  }
  cin.ignore(10, '\n');
  return tempChar;
}

//Name:   readInt(string prompt)
//Desc:   This function reads an int, validates and returns it
//input:  None
//output: Possibly a error message
//return: int tempVar
int readInt(string prompt) {
  int tempInt = 0;
  cout << prompt;
  cin >> tempInt;
  while (!cin || tempInt < 0) {
    cout << "Invalid input! Please try again!!!" << endl;
    cout << prompt;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> tempInt;
  }
  cin.ignore(10, '\n');
  return tempInt;
}
