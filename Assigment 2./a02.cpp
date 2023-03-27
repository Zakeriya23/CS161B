/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A02 Sample (CS161B)
# Date:             April 17, 2022
# Description:     Simple and compounding interest rate calc
# Input:            (userChoice, principalAmount, intersetRate, timeYear, compounding Period)
# Output:           (Displays interestAccrued and totalAmount)
# Sources:         Assignment 2
#                      www.calculatorsoup.com/calculators/financial/compound-interest-calculator.php
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


//function prototypes
void welcome();
void displayMenu();
double readOption();
double readNow(string prompt);
int readInt(string promt);
double exeOption(int userChoice);
double simpleCal(double principalAmount, double interestRate, double timeYear);
double compoundCal(double principalAmount, double interestRate, double timeYear, double compundingPeriod);

//main function
int main()
{
  //declare variables for input
    int userChoice = 0;
  //declare variables for all output and support structure
    double totalAmount;
  //call welcome function
  welcome();
  //do while loop for menu
do
  {
    displayMenu();
    userChoice = readOption();
    //data validation loop
    while(userChoice < 1 || userChoice > 3){
      cout << "Invalid Choice! Please choose 1-3." << endl;
      userChoice = readOption();
    }
    totalAmount = exeOption(userChoice);
//priniting values and setting them to 2 decimal points
      cout << fixed << setprecision(2);
      cout << "Total Accrued Amount (principal + interest): $" << totalAmount << endl << endl;
}while (userChoice != 3);

  //print Thank you message
  cout << "Thank you for using my program!" << endl;
  //end program
  return 0;
}

//Name: welcome()
//Desc: This function displays the welcome message
//input: None
//output: None
//return: None
void welcome()
{
  cout << "Welcome to my Interest Calculation program! " << endl;
}

//Name: displayMenu()
//Desc: This function displays the menu to the user
//input: None
//output: None
//return: None
void displayMenu()
{
  cout << "What would you like to do today?" << endl;
  cout << "Pick an option from below:" << endl;
  cout << "         1. Simple Interest" << endl;
  cout << "         2. Compound Interest" << endl;
  cout << "         3. Quit" << endl;
}

//Name: readOption()
//Desc: This function reads the userChoice and returns it
//input: None
//output: None
//return: double userChoice
double readOption()
{
  //get user input from user first
  //call readInt to do data validation
  int userChoice = readInt(">>");

  return userChoice;
}

//Name: readNow(string prompt)
//Desc: This function reads an double, validates and returns it
//input: None
//output: Maybe error message
//return: double option
double readNow(string prompt)
{
 //DElCARE double option and INPUT into option
  double option = 0;
  cout << prompt;
  cin >> option;
// try again and clears
  while(!cin)
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> option;
  }
  cin.ignore(10, '\n');
  return option;
}
//Name: readInt(string prompt)
//Desc: This function reads an Int, validates and returns it
//input: None
//output: Maybe error message
//return: Int option
int readInt(string prompt)
{
 //DElCARE int option and input into option
  int option = 0;
  cout << prompt;
  cin >> option;
// try again and clears
  while(!cin)
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> option;
  }
  cin.ignore(10, '\n');
  return option;
}


//Name: exeOption(double userChoice)
//Desc: This function takes the userChoice and reads the principlesAmounts, interest rate, timeYear, and compoundPeriod exercised from the user. Then it calls an equation to calcuate the total Amount based on the the users choice And before returns the totalAmount to main() it print the interestAccured.
//input: double principalAmount, interestRate, timeYear, compoundPeriod, totalAmount,
//output: Maybe error message, print interestAccured
//return: double totalAmount
double exeOption(int userChoice)
{
// DELCARING Varibles
   double principalAmount = 0, interestRate = 0, timeYear = 0, compoundPeriod = 0, totalAmount = 0;
    //checking for userchoice and exe the option that choice
    if(userChoice == 3){
     return 0;
      }
    else{
    principalAmount = readNow("Enter the Principal Amount: ");
    interestRate = readNow("Enter the interest rate: ");
    timeYear = readNow("Enter the time in years: ");
    if (userChoice == 1 ){
        totalAmount = simpleCal(principalAmount, interestRate, timeYear);
    }
    else if (userChoice == 2){
        compoundPeriod = readNow("Enter the number of compounding period: ");
        totalAmount = compoundCal(principalAmount, interestRate, timeYear, compoundPeriod);
    }
    }
    double interestAccured = totalAmount - principalAmount;
    cout << "\nInterest accrued: $" << interestAccured << endl;
    return totalAmount;
}

//Name: simpleCal(principalAmount, interestRate, timeYear)
//Desc: This function takes principalAmount, interestRate, timeYear and returns calculated totalAmount using simple interest formula (A= P(1+(r/100)*t ), it returns it to function exeOptions()
//input: principalAmount, interestRate, timeYear
//output: None
//return: double TotalAmount
double simpleCal(double principalAmount, double interestRate, double timeYear){
  //returns calculated totalAmount using the simple formual
    return principalAmount *(1 + ((interestRate/100) * timeYear));
}

//Name: compoundCal(principalAmount, interestRate, timeYear, compoundingPeriod)
//Desc: This function takes principalAmount, interestRate, timeYear, compoundingPeriod and returns calculated totalAmount using compounding interest formula (A= P(1+(r/100)/n)^n*t),returns it to function exeOption()
//input: principalAmount, interestRate, timeYear, compoundingPeriod
//output: None
//return: totalAmount
double compoundCal(double principalAmount, double interestRate, double timeYear, double compundingPeriod){
    //returns calculated totalAmount using the compounding interest formuala
    return principalAmount * pow((1 + interestRate / 100 / compundingPeriod), (compundingPeriod *timeYear));
}
