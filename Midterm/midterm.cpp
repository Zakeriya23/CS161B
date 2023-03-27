//libray
#include <iostream>

using namespace std;

int pop(int stack[], int &size, int &val);
void printStack(int stack[], int size);

const int MAX = 3; // maximum size of stack

int main() {
    int stack[MAX] = {8, -2, 3}; // integer array for stack
    int size = 3;   // contains number of elements in stack
    char userChoice='\0'; 
  int Val;
  cout << "Welcome to the FIFO Queue Program!" <<endl;
 do{
  do{
    cout << "\nEnter Option: ";
    cin >> userChoice;
  }while(userChoice!='p' && userChoice!='-' &&userChoice!='q');
if (userChoice == 'p'){
  printStack(stack,size);
}
if(userChoice=='-'){
  cout << "Integer: ";
  cin >> Val;
  pop(stack,size,Val);
  printStack(stack,size);
}
if(userChoice=='q'){
  cout << "GoodBye!!";
}
  }while(userChoice!='q');
    return 0;
}

//name:                 pop(stack, &size, &val)
//description:         take array stack, size and val and compare val with stack
//input params:         int array and its size
//output:                   does stakc pop modifiction to list if val is in stack
//return:                   o - if stack is empty, 2 if number is not found, 0 if everything went well
int pop(int stack[], int &size, int &val){
int i=0,pos=0;
if(!size){
  cout << "Stack is empty" << endl;
  return 1;
}
for(int i=0;i<size; i++){
    if(stack[i]==val){
      pos=i;
      break;
    }
  }
if(i==size){
  cout << "Number not found!!"<< endl;
  return 2;
  }
else {
  for(int j = pos ; j < size; j++){
       stack[j] =0;
     }
       size=pos;
  }
  return 0;
}

// Call this function to print the stack
void printStack(int stack[], int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << stack[i];
        
       	if (i != size - 1)
            cout << ", " ;
    }
    cout << "]" << endl;
}

