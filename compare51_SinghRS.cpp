/*-------------------------------------------
// Course: COMP 150
// Last Name: Singh
// First Name: Rajveer
// Student ID: 300202522
// 
// File: compare51_SinghRS
//
// Summary: Prompts 2 numbers from the user and returns the larger (maximum) one
//			and detects if the 2 numbers have the same value.
//			       	          
*-------------------------------------------*/

#include <iostream>
using namespace std;

// Function prototypes
int maximum(int num01, int num02);

int main()
{
	// Storing user inputs and the maximum of the 2 inputs
	int input01, input02;
	int answer;
	
	// Outputting and prompting 
	cout << "Please type two numbers to compare.\n";
	cout << "First number: ";
	cin >> input01;
	cout << "Second number: ";
	cin >> input02;
	
	// Calculating and outputting the maximum between the input01 and input02
	answer = maximum(input01, input02);
	if (input01 == input02)		// Checking if the values entered are the same
	{
		cout << "The two numbers are the same." << endl;
	}
	else	// Values aren't the same
	{
		cout << "The maximum between two numbers " << input01 << " and " << input02 << " is " << answer << endl;	
	}
	
	return 0;
}

/*---------------------------------------------------------------*/
/* This function finds the maximum between 2 numbers.			 */
/* Preconditions: num01 and num02 hold an integer value			 */
/* Postcondition: returns the larger number of the two (maximum) */  
int maximum(int num01, int num02)
{
	// Storing the uncalculated maximum number
	int answerMax;
	
	// The two numbers are the same value
	if (num01 == num02)	
	{
		answerMax = num01;		// answerMax will have the same value whether it's assigned to num1 or num2
	}
	// Number 1 is larger
	else if (num01 > num02)
	{
		answerMax = num01;
	}
	// Number 2 is larger
	else
	{
		answerMax = num02;
	}
	
	return answerMax;
}
