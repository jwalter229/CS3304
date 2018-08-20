#include <iostream>

using namespace std;

//Function Declarations
void function_call(int current, int last);
double sumover(unsigned int number);
void reverseArray(char data[], int fBound, int lBound);

int main()
{	// creating an unsigned int 
	// and uing the int for user input
	unsigned int userInput;
	
	// prompting user for input
	// taking user input
	cout << "Please enter an unsigned integer for problem 1: ";
	cin >> userInput;
	
	// invoke function to print all calls
	function_call(1, userInput);
	
	cout << "Please enter an unsigned integer for problem 2: ";
	
	cin >> userInput; // using userInput
	cout << sumover(userInput) << endl;
	
	// creating an array size 9 
	// fill array with A through E
	char data[9] = {'A', 'B', 'C', 'D', 'E', '\0'};
	
	cout << "Array before reverse order" << endl;
	// looping through array to display its contents
	for(int idx = 0; idx < 9; idx++)
	{
		cout << data[idx]; // displaying the contents of the array
	}
	cout << endl; // blank line to create spacing
	
	reverseArray(data, 1, 4); // calling reverseArray function
	cout << "Array after reverse order" << endl;
	// looping through array to display its contents
	for(int idx = 0; idx < 9; idx++)
	{
		cout << data[idx]; // displaying the contents of the reversed array
	}
	cout << endl; // blank line to create spacing

}// end of main()

// start of function_call
// function to print all calls
void function_call(int current,int last)
{
	// creating a temp string
	// to track spacing
	string temp = "";
	
	// Depending on current
	// add spaces to temp ""
	for (int i = 0; i < current; i++)
	{
		temp+= " ";
	}
	
	// if current less than or equal to last
	// invoke the recursive calls
    if (current <= last)
    {
		// printing first numbers
        cout << temp << "This was written by call number " << current << "." << endl;
		
		// adding one to current and 
		// call function again
        function_call(current+1,last);
		
		// printing last statements
        cout << temp << "This ALSO written by call number " << current << "." << endl;
    }
}// end of function_call


// start of sumover
double sumover(unsigned int number)
{
	// if the number is equal to 1, 
	// return 1.0
	if (number == 1)
	{
		return double(1.0);
	}
	// if number is 0
	// return 0
	else if (number == 0)
	{
		return double(0.0);
	}
	
	else{
		// eeturn 1 / double(number) + sumover(number - 1)
		return 1 / double(number) + sumover(number - 1);
	}
}// end of sumover


// start of reverseArray
void reverseArray(char data[], int first_Bound, int last_Bound)
{
	// if first bound is greater than or equal to the last bound
	if (first_Bound >= last_Bound)
        return;
	// creating a temp char
	char temp = data[first_Bound];
	
	data[first_Bound] = data[last_Bound]; 
	data[last_Bound] = temp;
	
	reverseArray(data, first_Bound + 1, last_Bound - 1);
	
}// end of reverseArray
