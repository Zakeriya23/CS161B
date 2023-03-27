//libray
#include <iostream>
#include <ios>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
//DELCARE Varibles
double totalCost;
double planCost;
double overCharge;
double upgrade;
double gigBit;
char choice;
//Display menu
cout << fixed << setprecision(2);
cout << "****Welcome to Mint Mobile! ******" << endl << endl;
cout << "Let's calculate your monthly bill! " << endl << endl;
cout << "S:  2GB $35/mo* " << endl;
cout << "M:  4GB $50/mo* " << endl;
cout << "L:  8GB $70/mo* " << endl;
cout << "U:  Unlimited $70/mo* " << endl << endl;
cout << "*Overcharge charges $15 per GB" << endl;
cout << "\nWhich plan are you on? (S/M/U) : ";

cin >> choice;
while(choice!= 's' && choice != 'S'&& choice !='M' && choice != 'm' && choice != 'L' && choice != 'l' && choice != 'u' && choice != 'U'){
    cout << "Invaild plan! Pick again: ";
    cin >> choice;
}
cout << "How many GB did you use last month? ";
cin >> gigBit;
gigBit = ceil(gigBit);
  
//Switch statement for choices
switch (toupper(choice)){
case 'S':
  planCost = 35;
  gigBit = gigBit - 2;
  break;
case 'M':
  planCost = 50;
  gigBit= gigBit - 4;
  break;
case 'L' :
  planCost = 70;
  gigBit= gigBit- 8;
  break;
case 'U':
  planCost = 75;
  totalCost = 75;
  gigBit= 0;
  break;
}

//overcharge calc
if (gigBit > 0){
  overCharge = gigBit * 15;
  totalCost= overCharge + planCost;
}
else {
totalCost = planCost;
}
//print values
cout << "\nPlan charge: $" << planCost << endl;
if (overCharge > 0){
 cout << "Overcharges: $";
 cout << overCharge << endl;
}
cout << "Total Cost: $" << totalCost << endl;
//Upgrade feature
if (totalCost > 75){
  upgrade = totalCost - 75;
  cout << "\nUgrade to Unlimited and save $" << upgrade << " !!!\n";
}
cout << "\nThank you for choosing Mint Mobile.\n" << "GoodBye!!\n" <<endl;
return 0;
}