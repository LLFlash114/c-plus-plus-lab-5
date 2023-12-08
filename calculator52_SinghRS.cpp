/*-------------------------------------------
// Course: COMP 150
// Last Name: Singh
// First Name: Rajveer
// Student ID: 300202522
// 
// File: calculator52_SinghRS
//
// Summary: Simulates a calculator by prompting a list of 8 different math operations to choose from
//			which operate basic arithmetic of 2 or 3 numbers inputted by the user. The math operations 
//			are coded as separate functions. The Math operation options:
//			
//			1) Addition 	  ----------->	 Performs the addition of 2 numbers inputted by the user and returns the sum.
//			
//			2) Subtraction    ----------->   Performs the subtraction of 2 numbers inputted by the user and returns the difference. 
//			
//			3) Multiplication ----------->   Performs the multiplication of 2 numbers inputted by the user and returns the difference.
//			
//			4) Division 	  ----------->	 Performs the division of 2 numbers inputted by the user and returns the quotient.
//			
//			5) Remainder      ----------->   Calculates the amount left over after the division of 2 numbers inputted by the user.
//			
//			6) Factorial 	  -----------> 	 Calculates the non-negative number entered by the user multiplied by every natural number below it.
//											 Only accepts numbers (0) - (20) due to the limits of the data type long long int.
//											 
//			7) Triangle Area  ----------->   Calculates the area of a triangle given non-negative base and height numbers inputted by the user.
//			
//			8) Custom Formula ----------->   Random formatted math formula created for fun, no real world logic behind it or the answer returned
//											 by it. Obtains 3 numbers inputted by the user to perform the calculation. 					 	             	           
//
*-------------------------------------------*/

#include<iostream>
using namespace std;

// Function prototypes
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double dividend, double divisor);
double remainder(double dividend, double divisor);
long long int factorial(long long int num);
double triangleArea(double base, double height);
double customFormula(double num1, double num2, double num3);

int main()
{
	// Storing information for user entered operands for the math operations 
	int chosen_math_operation;
	double user_num1, user_num2, triangle_base, triangle_height, custom_num1, custom_num2, custom_num3;
	long long int user_factorial;
	
	// Looping entire program until user enters 0
	// Prompting the user for the operation to use
	do {
		cout << "Choose a math operation: " << endl;
		cout << "ENTER 0 TO QUIT." << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "1) Addition        5) Remainder\n"
			 "2) Subtraction	   6) Factorial\n"
			 "3) Multiplication  7) Triangle Area\n"	
			 "4) Division        8) Fun Custom Formula" << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "\nYOUR CHOICE: ";
		cin >> chosen_math_operation;
		
		// Handling error if incorrect option entered
		while (chosen_math_operation < 0 || chosen_math_operation > 8)
		{
			cout << "Incorrect value entered. Type a number (0)-(8): ";
			cin >> chosen_math_operation;
		}
		
		
		// Prompting output and input for otions 1-5  
		if (chosen_math_operation >= 1 && chosen_math_operation <= 5)
		{
			cout << "Enter first number (integer or decimal): ";
			cin >> user_num1;
			cout << "Enter second number (integer or decimal): ";
			cin >> user_num2;
			
			// Calculating the operands based on chosen operation	
			switch(chosen_math_operation)
			{
			case 1:		// Addition operation
				cout << "-----------------------------" << endl; 
				cout << user_num1 << " + " << user_num2 << " = " << add(user_num1, user_num2) << endl;
				break;
			case 2:		// Subtraction operation
				cout << "-----------------------------" << endl;
				cout << user_num1 << " - " << user_num2 << " = " << subtract(user_num1, user_num2) << endl;
				break;
			case 3:		// Multiplication operation
				cout << "-----------------------------" << endl;
				cout << user_num1 << " * " << user_num2 << " = " << multiply(user_num1, user_num2) << endl;
				break;
			case 4:		// Division operation
				while (user_num2 == 0)		  // Handling error if divisor is 0
				{
					cout << "Divisor cannot be 0. Enter second number again: ";
					cin >> user_num2;
				}
				cout << "-----------------------------" << endl;
				cout << user_num1 << " / " << user_num2 << " = " << divide(user_num1, user_num2) << endl;
				break;
					
			case 5:		// Remainder operation
				while (user_num2 == 0)		  // Handling error if divisor is 0
				{
					cout << "Divisor cannot be 0. Enter second number again: ";
					cin >> user_num2;
				}
				cout << "-----------------------------" << endl;
				cout << user_num1 << " % " << user_num2 << " = " << remainder(user_num1, user_num2) << endl;
				break;
			}
			cout << "-----------------------------" << endl << endl;	
		}	
		
		
		// Prompting output and input for otions 6-8 
		else if (chosen_math_operation >= 6 && chosen_math_operation <= 8)
		{
			// Calculating the operands based on chosen operation
			switch(chosen_math_operation)
			{
				case 6:		// Factorial operation
					cout << "Enter a number (0)-(20) (positive integer only): ";	// Handling error if value is less than 0 or more than 20
					cin >> user_factorial;
					while (user_factorial < 0 || user_factorial > 20)
					{
						cout << "Number cannot be negative or larger than 20. Enter again: ";
						cin >> user_factorial;
					}
					cout << "-----------------------------" << endl;
					cout << user_factorial << "!" << " = " << factorial(user_factorial) << endl;
					break;
					
				case 7:		// Triangle Area operation
					cout << "Enter the base (integer or decimal): ";
					cin >> triangle_base;
					while (triangle_base <= 0)		// Handling error if base is less than 0 or less
					{
						cout << "Base cannot be negative or 0. Enter again: ";
						cin >> triangle_base;
					}
					cout << "Enter the height (integer or decimal): ";
					cin >> triangle_height;
					while (triangle_height <= 0)	// Handling error if height is less than 0 or less
					{
						cout << "Height cannot be negative or 0. Enter again: ";
						cin >> triangle_height;
					}
					cout << "-----------------------------" << endl;
					cout << "(" << triangle_base << " * " << triangle_height << ")" << " \\ 2 = " << triangleArea(triangle_base, triangle_height) << endl;
					break;
					
				case 8:		// Custom Formula operation
					cout << "The Custom Formula is (num1 * num3 * num2) + (num2 / num1 - num3)" << endl;
					cout << "Enter first number: (integer or decimal): ";
					cin >> custom_num1;
					cout << "Enter second number: (integer or decimal): ";
					cin >> custom_num2;
					cout << "Enter third number: (integer or decimal): ";
					cin >> custom_num3;
					cout << "-----------------------------" << endl;
					cout << "Custom Formula Answer: " << customFormula(custom_num1, custom_num2, custom_num3) << endl;
					break;
			}
			cout << "-----------------------------" << endl << endl;
		}
		
	} while (chosen_math_operation != 0);	// End of loop
	
	
	cout << "\nExiting program..." << endl;
	cout << "Program exited" << endl;
	return 0;
}

/*----------------------------------------------------------*/
/* This function performs the addition of 2 numbers.		*/
/* Preconditions: num1 and num2 hold a number value			*/
/* Postcondition: returns the sum of num1 and num2			*/  
double add(double num1, double num2)
{
	return num1 + num2;
}

/*----------------------------------------------------------*/
/* This function performs the subtraction of 2 numbers.		*/
/* Preconditions: num1 and num2 hold a number value			*/
/* Postcondition: returns the difference of num1 and num2	*/
double subtract(double num1, double num2)
{
	return num1 - num2;
}

/*----------------------------------------------------------*/
/* This function performs the multiplication of 2 numbers.	*/
/* Preconditions: num1 and num2 hold a number value			*/
/* Postcondition: returns the product of num1 and num2		*/  
double multiply(double num1, double num2)
{
	return num1 * num2;
}

/*------------------------------------------------------------------------------------------*/
/* This function performs the division of 2 numbers.										*/
/* Preconditions: dividend holds a value that isn't 0 and divisor holds any number value	*/
/* Postcondition: returns the quotient of dividend and divisor								*/  
double divide(double dividend, double divisor)
{
	// Handling error if divisor is 0
	if (divisor == 0)
	{
		return -1;	
	}
	else	// Divisor not 0
	{
		return dividend / divisor;
	}
}

/*------------------------------------------------------------------------------------------*/
/* This function calculates the amount left over after the division of 2 numbers.			*/
/* Preconditions: dividend holds a value that isn't 0 and divisor holds any number value	*/
/* Postcondition: returns the remainder of the dividend and divisor							*/
double remainder(double dividend, double divisor)
{
	// Storing negative number checks, calculation, and remainder 
	double result{0.0}, remainder;
	bool negative_remainder{false};
	
	// Checking if the dividend is negative
	if (dividend < 0)
	{
		dividend = 0 - (dividend);	// Converting to positive opposite to do calculation
		negative_remainder = true;	
	}
	
	// Checking if the divisor is negative
	if (divisor < 0)
	{
		divisor = 0 - (divisor);	// Converting to positive opposite to do calculation
	}
	
	// Handling error if divisor is negative
	if (divisor == 0)
	{
		return -1;
	}
	// Setting the remainder to 0 (remainder will always be 0 if dividend is 0)
	else if (dividend == 0)
	{
		remainder = 0;
	}
	// Calculating remainder if divisor or dividend is not 0
	else
	{
		while (!(result > dividend))
		{
			result += divisor;
		}
	}
	result -= divisor;
	result = dividend - result;
	remainder = result;
	
	// Converting and outputting remainder to negative if dividend was negative
	if (negative_remainder == true)
	{
		return -(remainder);
	} 
	else	// Dividend not negative
	{
		return remainder;
	}
}

/*------------------------------------------------------------------------------------------*/
/* This function calculates the factorial (the num multiplied by every natural				*/
/* number below it) of numbers 0-20. (largest factorials supported by long long int) 		*/
/* Preconditions: num holds an integer value ranging from 0 - 20							*/
/* Postcondition: returns the factorial of num												*/
long long int factorial(long long int num)
{	
	// Storing factorial calculation
	long long int factorial{1};
	
	// Handling error if num is negative
	if (num < 0)
	{
		return -1;
	}
	// Setting final factorial value to 1 if num is 0
	else if (num == 0)
	{
		factorial = 1;
	}
	// Calculating factorial if num not 0 or negative
	else
	{
		for (int number{num}; number>=1; number--)
		{
			factorial *= number;	
		}
	}
	
	return factorial;
}

/*------------------------------------------------------------------------------------------------------*/
/* This function calculates the area of a triangle.														*/
/* Preconditions: base and height hold a non-negative number representing demensions of the triangle  	*/
/* Postcondition: returns the area of a triangle														*/
double triangleArea(double base, double height)
{	
	// Handling error if base or height values are negative
	if (base <= 0 || height <= 0)
	{
		return -1;
	}
	else	// base and height not negative
	{
		return (base * height) / 2;
	}
	
}

/*------------------------------------------------------------------------------------------*/
/* This function performs the calculation of a custom created formula						*/ 
/* that uses addition, subtraction, multiplication, and division. 							*/   
/* Preconditions: num1, num2, and num3 hold a number value									*/
/* Postcondition: returns the solution of the custom created formula						*/
double customFormula(double num1, double num2, double num3)
{
	return (num1 * num3 * num2) + (num2 / num1 - num3);   
}
