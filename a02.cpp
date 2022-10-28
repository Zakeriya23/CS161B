/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A02 (CS162) Finished
# Date:             October 19, 2022
# Description:      This program help user generate at stronger passoword
# Input:            first name, last name, email and the password;
# Output:           Echo back the users input and a modifty verision with a choice to redo or not.
# Sources:          Assignment 2  instruction
#******************************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>
#include<string>
#include <iomanip>
using namespace std;

//const int for the size of the struct arrays
const int MAX = 101;

//struct for the user and all the important information
struct user{
	char first[MAX]; //store the user first name
	char last[MAX]; // store the user last name 
	char email[MAX]; //store the users email.
	char pass[MAX]; // store the password.
};

void input(user list[]); //This function get the users input.
void mod(user list[]); //This function modifty the password using the assignment instructions
void change(user list[]);//This function compare the user first and last name to the passoword for similitry.
void print(user list[]);//This function print out the user information.
			//Main function
int main(){

	char option;
	int count =0;
	user list[MAX];

	while(toupper(option) != 'Q'){
		cout << "\nWelcome to the Password Generator" << endl;
		cout << "\t(C) to use program." << endl;
		cout << "\t(Q) quit this program." << endl;
		cout << "\t\t--->";	
		cin>> option;
		cin.ignore();
		option = toupper(option);

		while(option!= 'Q' && option != 'C'){
			cin >> option;
			cin.ignore();
			option = toupper(option);
		}
		if(toupper(option)=='C'){
			input(list); change(list);  mod(list); print(list); 
		}
	}
	return 0;
}
//Name:        input(userlist[]);
//Description:   This function get the information
//input params:   user list struct
//ouput:        none
//return:       none
void input(user list[]){                                
	cout << "Enter your first name"<< endl<< "\t--->";
	cin.getline(list[0].first,MAX,'\n');
	cin.clear();

	cout << "Enter your last name"<< endl<< "\t--->";
	cin.getline(list[0].last,MAX,'\n');
	cin.clear();

	cout << "Enter your Email address"<< endl<< "\t--->";
	cin.getline(list[0].email,MAX,'\n');
	cin.clear();

	cout << "Enter a password"<< endl<< "\t--->";
	cin.getline(list[0].pass,MAX,'\n');
	cin.clear();
}
//Name:        mod(userlist[]);
//Description:   This function modifty the information followiing the instruction 
//input params:   user list struct
//ouput:        none
//return:       none
void mod(user list[]){
	// we want it to lower case all of the letters

	int vowels = 0;
	int upper=0;	
	int pos=0;
	int size = strlen(list[0].pass);
	char temp[size];
	strcpy(temp,list[0].pass);
	int size2= size+vowels+upper+3;	

	//Counting the vowels and uppercase to create the size for the new array
	for(int i =0;i<=size;++i){
		if(isupper(temp[i])){
			upper= upper+1;	
		}
		if(temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u'){
			vowels = vowels+1;
		}		
	}

	//Creating a new array to modifty with the instructions.
	char arr[size2];
	int position=0;
	for(int p=0;p<=strlen(temp);p++){
		if(temp[p] == 'a' || temp[p] == 'e' || temp[p] == 'i' || temp[p] == 'o' || temp[p] == 'u'){
			arr[position]=temp[p];
			arr[position+1]=temp[p];
			position=position+1;
		}
		if(isupper(temp[p])){
			arr[position]='_';
			arr[position+1]=temp[p]+32;
			position=position+2;	
		}
		else{
			arr[position]=temp[p];
			position=position+1;	
		}
	}	

	//copying the modified array to the list struct of password.
	strcpy(list[0].pass,arr);
}
//Name:        change(user list[])
//Description:    This funciton check if the name and password are similar, If they are it prompts user to enter new password
//input params:   user list struct
//ouput:        none
//return:	none
void change(user list[]){

	int bad=strlen(list[0].pass)/2;
	int count=0;
	int size1 = strlen(list[0].pass);
	char temp1[size1];
	strcpy(temp1, list[0].pass);
	int size2 = strlen(list[0].first);
	char temp2[size2];
	strcpy(temp2, list[0].first);

		for(int i=0; i< size1; i++){
			if(temp1[i]==temp2[i]){
				count++;
			}
		}
		if(count>=bad){	
			cout << "\nWEAK password, Please try again!!!" << endl;
			cout << "\tEnter a stronger password" << endl<< "\t--->";
			cin.getline(list[0].pass,MAX,'\n');
			cin.clear();
		}
}
//Name:        print(userlist[]);
//Description:   This function print the information
//input params:   user list struct
//ouput:        user information
//return:       none
void print(user list[]){

	int size = strlen(list[0].pass);
	char temp[size];
	strcpy(temp, list[0].pass);
	char c= temp[size-1];
	int i= int(c);

	cout << "Name: " << list[0].first << " " << list[0].last << endl;
	cout << "Email: " << list[0].email << endl;
	cout << "Password: "; 
	for(int i= 0;i<size-1;++i){ 
		cout << temp[i];
	}
	cout << i;
	cout << endl;
}
