#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	// using cout to diplay lines of text
	cout << "hello world in C++" << endl;
	cout << "Strating Program..." << endl;
	cout << "This is some text." << endl;
	cout << "Banana." << "Apple." << "Orange." << endl;
	cout << "This is some more text." << endl;
	cout << endl;

	// setting int variables
	int numberCats = 5;
	int numberDogs = 7;
	// using int variables to create total number of animals
	int numberAnimals = numberCats + numberDogs;
	
	// using cout to diplay int variables
	cout << "Number of Cats: " << numberCats << endl;
	cout << "Number of Dogs: " << numberDogs << endl;
	cout << "Total number of animals: " << numberAnimals << endl;
	cout << "New Dog acquired! " << endl;
	cout << endl;
	
	// adding 1 to the total number of dogs
	numberDogs = numberDogs + 1;
	
	// finding total number of all animals
	numberAnimals = numberCats + numberDogs;
	
	// displaying number of dogs 
	// displaying total number of animals
	cout << "Number of Dogs: " << numberDogs << endl;
	cout << "Number of Animals: " << numberAnimals << endl;
	cout << endl;
	
	// creating a string named text1 and setting its content
	// displayig text1 string
	string text1 = "Hello, this is a String.";
	cout << text1 << endl;
	
	// creating string text2
	// creating string text3
	string text2 = "Hello ";
	string text3 = "Fred ";
	
	// displaying text2 and text3
	cout << text2 << text3 << endl;
	
	// creating string text4
	// setting it contents to text2 + text3
	string text4 = text2 + text3;
	// displaying text2 + text3
	cout << text4 << endl;
	cout << endl;
	
//	//prompting user for input
//	cout << "Enter Your First Name: " << flush;
//	string input; // creating an empty string for user input
//	cin >> input; // taking user input
//	cout << "You Entered: " << input << endl;
//	
//	// taking user input for int
//	// displaying user input for int
//	cout << "Enter a Int Value: " << flush;
//	int value;// declare int vaule
//	cin >> value;// taking in value
//	cout << "You Entered: " << value << endl;	
//	cout << endl;
	
	// signed int allows you to have a - int
	int value2 = -54656;
	cout << "The Value is: " << value2 << endl;
	
	// displaying max int value
	cout << "Max int Value: " << INT_MAX << endl;
	// displaying min int value
	cout << "Min int Value: " << INT_MIN << endl;
	cout << endl;
	
	// creating a long int value
	long lValue = 2345235345345;
	cout << "The long int value is: " << lValue << endl;
	// creating a shorgt int value
	short sValue = 23434;
	cout << "The short int value is: " << sValue << endl;
	
	// using sizeof operator
	// checking to see the size of an int
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of Value: " << sizeof(value2) << endl;// still 4 because value is delcared as an int
	
	// checking the size of a short int
	cout << "Size of short int: " << sizeof(short int) << endl;
	cout << "Size of sValue: " << sizeof(sValue) << " bits." << endl;
	
	// checking the size of a long int
	cout << "Size of long int: " << sizeof(long int) << endl;
	cout << "Size of lValue: " << sizeof(lValue) << " bits." << endl;
	cout << endl;
	
	// unsigned int means
	// you can only have a postive numbers
	unsigned int uValue = 2342343;
	cout << "The unsigned int value is: " << uValue << endl;
	
	// creating a float 
	// declaring its value
	float fValue = 76.4;
	cout << "The Float Value is: " << fValue << endl;
	// using fixed to show true value
	cout << "The Fixed Float Value is: " << fixed << fValue << endl;
	// using scientific to show scientific value
	cout << "The Scientific Float Value is: " << scientific << fValue << endl;
	// using setpercision to 20
	cout << "Using Set percision to 20 for float value: " << setprecision(20) << fixed << fValue << endl;
	cout << "Size of a float is: " << sizeof(float) << endl;
	cout << "Size of fValue is: " << sizeof(fValue) << endl;
	cout << endl;
	
	// another example of a float value
	cout << "This is another example of a float." << endl;
	float fValue2 = 123.456789;
	cout << "The Float Value is: " << fValue2 << endl;
	// using fixed to show true value
	cout << "The Fixed Float Value is: " << fixed << fValue2 << endl;
	// using scientific to show scientific value
	cout << "The Scientific Float Value is: " << scientific << fValue2 << endl;
	// using setpercision to 20
	cout << "Using Set percision to 20 for float value: " << setprecision(20) << fixed << fValue2 << endl;
	cout << "Size of a float is: " << sizeof(float) << endl;
	cout << "Size of fValue is: " << sizeof(fValue2) << endl;
	cout << endl;
	
	// creating a double value
	// delcaring its value
	double dValue = 123.456789;
	cout << "The Double Value is: " << dValue << endl;
	// using fixed to show true value
	cout << "The Fixed Double Value is: " << fixed << dValue << endl;
	// using scientific to show scientific value
	cout << "The Scientific Double Value is: " << scientific << dValue << endl;
	// using setpercision to 20
	cout << "Using Set percision to 20 for float value: " << setprecision(20) << fixed << dValue << endl;
	cout << "Size of a double is: " << sizeof(double) << endl;
	cout << "Size of fValue is: " << sizeof(dValue) << endl;
	cout << endl;
	
	// creating a double value
	// delcaring its value
	long double ldValue = 123.456789876543210;
	cout << "The Long Double Value is: " << ldValue << endl;
	// using fixed to show true value
	cout << "The Fixed Long Double Value is: " << fixed << ldValue << endl;
	// using scientific to show scientific value
	cout << "The Scientific Long Double Value is: " << scientific << ldValue << endl;
	// using setpercision to 20
	cout << "Using Set percision to 20 for float value: " << setprecision(20) << fixed << ldValue << endl;
	cout << "Size of a long double is: " << sizeof(long double) << endl;
	cout << "Size of ldValue is: " << sizeof(ldValue) << endl;
	cout << endl;
	
	// creating a bool bValue
	// true = 1 false = 0
	bool bValue = true;
	cout << "The bool value is: " << bValue << endl;
	
	bool bValue2 = false;
	cout << "The bValue2 is: " << bValue2 << endl;
	cout << endl;
	
	// creating a char
	char cValue = 55; // will display 55 from the ascii table which is 7
	cout << "The char value is: cValue is set to 55, will show what the ascii value is " << cValue << endl;
	
	char cValue2 = '7'; // the ' ' will display the character inside them
	cout << "The char value is: " << cValue2 << endl;
	
	char cValue3 = '7'; // casting cValue3 as an int.....
						// (int)cValue3 will display the real value of the 7 value on the ascii table
	cout << "The char value is: (cValue3 set '7' (int)cValue3)" << (int)cValue3 << endl;
	cout << "Size of cValue: " << sizeof(cValue) << endl;
	cout << "Size of cValue2: " << sizeof(cValue2) << endl;
	cout << "Size of cValue3: " << sizeof(cValue3) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << endl;
	
	wchar_t wValue = 'i'; // can store more characters in wchar_t, it is larger than char
	cout << "The wchar_t vlue of wvalue is: " << wValue << endl;
	cout << "Size of wchar_t: " << sizeof(wchar_t) << endl;
	cout << "Casting wValue as char: " << char(wValue) << endl;// will give you the actual character.
	cout << endl;
	
	//creating a program that takes user input
	//of a password and checks if it is correct
	
	string password = "hello"; // creating a string named password setting it eqaul to hello
	cout << "Please Enter Your Password  (example: 'hello') > " << flush;
	
	string input;// creating a string named input to hold input from user
	cin >> input;// taking users input
	
	//cout << "'" << input << "'" <<endl;// using single quotes around input to make sure I am getting right output
	
	if(input == password)// checking if input equals password
	{
		cout << "Password Good" << endl;
	}
	if(input != password)// checking if input is not equal to password
	{
		cout << "Password Denined" << endl;
	}
	
	cout << endl;
	string password1 = "12ab";// creating a string named password1 setting it equal to 1234abcde
	cout << "Please Enter your Password1 (example: '12ab') > " << flush;
	
	string input1;// creating a string named input1 to hold input from user
	cin >> input1;// takin users input
	
	cout << "'" << input1 << "'" << endl;
	
	if(input1 == password1)
	{
		cout << "Password1 is good" << endl;
	}
		else{
			cout << "Password1 is no good" << endl;
		}
	
	
	
	
	return 0;
}// end of main()
