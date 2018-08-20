#include <iostream>
#include "node.h"
#include <bits/stdc++.h> // would not work on MAC used window desktop
using namespace std;

// I built this on my windows desktop

bool bears(int n);

int main()
{
	// start of problem one
	//The problem statement example of (3 + 7) * 14 = 140
    node *root = new node("*");
    root->left = new node("+");
    root->left->left = new node("3");
    root->left->right = new node("7");
    root->right = new node("14");
	
    cout << "While evaluating (3 + 7) * 14 using an expression tree, we get: " << eval(root) << endl;

	// deleting the root to use for next
    delete(root);
	
	// expression tree for (6 + 2) * (5 - 2) = 24
    root = new node("*");
    root->left = new node("+");
    root->left->left = new node("6");
    root->left->right = new node("2");
    root->right = new node("-");
    root->right->right = new node("2");
    root->right->left = new node("5");
	
    cout << "When evaluating (6 + 2) * (5 - 2) using an expression tree, we get: " << eval(root) << endl;
	delete(root);
	
	// expression tree for 5 * 6 = 30
	root = new node("*");
    root->left = new node("5");
    root->right = new node("6");
	
    cout << "When evaluating 5 * 6 using an expression tree, we get: " << eval(root) << endl;
	
	// creating new int
	int number;
	cout << endl;
	
	// starting problem 2
	cout << "Now looking at problem 2" << endl;
	 
	cout << endl;
	
	do
	{
		// prompting user to enter number of bears
		cout << "Enter the amount of bears (press 0 to stop the program): ";
		cin >> number;
		// if bears returns true, 
		// the user they have reached the goal
		if (bears(number))
		{
			cout << "You have reached the goal!" << endl;
		}
		// else 
		// the user they has not reached the goal
		else{
			cout << "Sorry, you have not reached the goal." << endl;
		}
	}
	// while number not equal to 0
	while(number != 0);
}// end of main


// start of bears
bool bears(int n)
{
	// creating integers one and two
	int one;
	int two;
	
	// get last digit
	one = n % 10;
	
	// get second to last digit
	two = (n % 100) / 10;
	
	// get product of the two numbers
	int multiplier = one * two;
	
	// checking if number is less than 42
	if (n < 42)
	{
		return false;
	}
	
	// checking if number is 42
	else if (n == 42)
	{
		return true;
	}
	// else 
	// let's continue to evaluate the entered number
	else{
		// checing if number is divisible by 5
		if (n % 5 == 0)
		{
			return bears(n - 42);
		}
		// checking if number is divisible by 4 or 3 
		// also checking if multiplier is not equal to 0
		else if(multiplier != 0 && (n % 4 == 0 || n % 3 == 0))
		{
			return bears(n - one * two);
		}  
		// checing if number is divisible by 2
		else if(n % 2 == 0)
		{
			return bears(n / 2);
		}
		// if no rules apply, then return false
		else{
			return false;
		}
	}
}// end of bears
