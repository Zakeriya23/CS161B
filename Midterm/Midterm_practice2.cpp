/*This is the starter file for Midterm Practice 2.
You will write a function name keepUnique that accepts an array of integers
numbers and it's length as parameters and removes multiple occurences of an element
in the array and returns the count of unique values that occur in the array.
An element is "removed" by shifting all subsequent elements one index to the left 
to cover it up, placing a 0 into the last index.  
The original ordering of number's elements should be retained or remain the same.
Please see examples in the midterm practice 2 document.*/
#include <iostream>

using namespace std;
void keepUnique(int numbers[], int count, int &num);

int main()
{
        int num=0;
        int numbers[] = {7, 7, 2, 2, 1, 2, 2, 7};
  //                    [7, 2, 1, 0, 0, 0, 0, 0]
  cout << "Array numbers before: [7, 2, 1, 0, 0, 0, 0, 0]"<< endl;
  keepUnique(numbers, 8,num);
  cout << "Unique values =" << num <<endl;
  cout << "Array after: [";
  for(int i = 0; i < 7; i++)
   {
  cout << numbers[i] << ", ";
  }
  cout<< numbers[7];
cout << "]"<< endl;
  

  return 0;
}
void keepUnique(int list[], int size,int &num)
{
  int pos = 0;
  int counter = 0; 
  for(int i = 0; i < size; i++){
  for(int j = i + 1; j < size; j++){
      if(list[j] == list[i]){
        pos = i;
        counter++;
        for(int o = pos;o < size-1 ; o++){      
          list[o] = list[o+1];
          }
        list[size-counter] = 0;
       i++;
      }   
    }
}
for(int j = 0; j < size; j++){
  if(list[j]!=0){
    num++;
  }
}

}