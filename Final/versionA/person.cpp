//implememtation file for struct PersonType
#include "person.h"
//add your function here for addPerson(.....)
bool addPerson(PersonType list[], int &count){
int userposition = 0;
    cout << "\nEnter your name: ";
    cin.getline(list[count].name,MAX_CHAR,'\n');
    cout << "Enter your citizenship: ";
    cin.getline(list[count].citizenship,MAX_CHAR,'\n');

    cout << "Enter your age: ";
    cin >> list[count].age;

    while((list[count].age < 1) || (list[count].age > 100)){
      cout << "Invalid input, enter age again: ";
      cin.clear();
      cin.ignore(50, '\n');
      cin >> list[count].age;
    }
   cout << "Enter position number: ";
   cin >> userposition;

    if ((userposition < 1)||(userposition > count)){
    cout << "Error! Invalid position." << endl;
        return false;
    }
 count++;
     for (int i = count; i >= userposition; i--){
        list[i] = list[i - 1];
    }
            list[userposition - 1] = list[count];
    return true;
}
