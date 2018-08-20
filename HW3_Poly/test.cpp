/*		Jason Walters
		Data Structures
		Tuesday - Thursday
		10 - 1215
*/

// FILE: polytest0.cxx
// An Interactive test program for the polynomial ADT
// Written by: Kenneth R. Glover - gloverk@colorado.edu

#include <cctype>          // Provides toupper
#include <iostream>        // Provides cout and cin
#include <cstdlib>         // Provides EXIT_SUCCESS
#include "poly0.h"         // Provides the polynomial class

using namespace std;
using namespace main_savitch_3;

//three polynomials are allowed
//in the test program
const unsigned int MANY = 3;

// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: The menu has been written to cout.


size_t set_current( );
// Postcondition: Return value is index for a new current polynomial.


char get_command();
// Postcondition: The user has been prompted for a character.
// The entered charatcer will be returned, translated to upper case.


void view(const polynomial& test);
//Postcondition:  The polynomial passed has been sent to cout.


void view_all(const polynomial a[]);
//Postcondition:  All polynomials has been written to cout.


void test_add(polynomial& test);
// Postcondition: The user has been prompted for a coefficent and degree of
// the term added.  The resulting polynomial has been written to cout.


void test_assign(polynomial& test);
// Postcondition: The user has been prompted for the degree and the coeffinient
// to be set.  The resulting polynomial has been written to cout.


void test_clear(polynomial& test);
// Postcondition: test.clear( ) has been activated.
// to be set.  The resulting polynomial has been written to cout.


void test_gif(const polynomial& test);
// Postcondition:  The user has been prompted for the range of the gif file.
// The gif file of the graph of the polynomial has been written to disk.


void test_eval(const polynomial& test);
// Post conditon:  The user has been prompted for the x value.  The evaluation
// of the polynomial is written to cout.


void test_np(const polynomial& test);
// Post conditon:  The user has been prompted for the e value.  The
// value of test.next_term(e) and test.previous_term(e) are written to cout.


int main()
{
    polynomial p[MANY];
    size_t current_index = 0;
    char command;

    size_t i;

    cout << "Polynomials ";

    for (i = 0; i < MANY; ++i)
		cout << char('A' + i) << ' ';
		cout << "All Are Initialized." << endl;

    do	//start of do this
	{	//print_menu method
        print_menu();
        command = toupper(get_command());
		
		//start of switch statements
        switch(command)
		{
			
	case 'S':  current_index = set_current( );
	    break;

	case '1':  test_assign(p[current_index]);
	    break;

	case '2':  test_add(p[current_index]);
	    break;

	case 'C':  test_clear(p[current_index]);
	    break;

	case 'V':
	    cout << char(current_index + 'A') << ": ";
	    view(p[current_index]);
	    break;

	case 'A':  view_all(p);
	    break;

//	case 'D':
//	    cout << char(current_index + 'A') << ".derivative: ";
//	    view(p[current_index].derivative( ));
//	    break;

	case 'E':  test_eval(p[current_index]);
	    break;

//	case 'G':  test_gif(p[current_index]);
//	    break;

	case 'N':  test_np(p[current_index]);
	    break;

	case '+':
	    cout << "A + B: ";
	    view(p[0] + p[1]);
	    break;

	case '-':
	    cout << "A - B: ";
	    view(p[0] - p[1]);
	    break;

//	case '*':
//	    cout << "A * B: ";
//	    view(p[0] * p[1]);
//	    break;

	case 'Q':  // Do nothing..
	    break;

	default:   cout << "Invalid command." << endl;
	    break;

        }//end of switch statements

    }//end of do

    while(command != 'Q');
    return (EXIT_SUCCESS);

}//end of main()


//start of print_menu
void print_menu()
{
    cout << "----------------- The Commands -----------------" << endl;
    cout << "S - set the current Polynomial to work on" << endl;
    cout << "  -   -   -   -   -   -   -   -   -   -   -   -" << endl;
    cout << "1 - use the assign_coef function" << endl;
    cout << "2 - use the add_to_coef function" << endl;
    cout << "C - use the clear function" << endl;
    cout << "V - view the current polynomial by using <<" << endl;
    cout << "A - view all polynomials by using <<" << endl;
    cout << "D - view derivative of current polynomial" << endl;
    cout << "E - evaluate current polynomial by using () op" << endl;
    cout << "G - use the gif function" << endl;
    cout << "N - use the next_term and previous_term functions" << endl;
    cout << "+ - view A + B" << endl;
    cout << "- - view A - B" << endl;
    cout << "* - view A * B" << endl;
    cout << "  -   -   -   -   -   -   -   -   -   -   -   -" << endl;
    cout << "Q - quit this interactive test program" << endl;
    cout << "-------------------------------------------------" << endl;
}//end of print menu


//start of get_command function test
char get_command()
{
    char command;

    cout << ">";
    cin >> command;
    
    return (toupper(command));
}//end of get_command 


//start of view function test
void view(const polynomial& test)
{
    cout << test
	 << " (degree is " << test.degree( ) << ")" << endl;
}//end of view function


//start of set_current function
size_t set_current( )
{
    size_t i;
    char command;
	
    do
    {
	cout << "Polynomials ";
	for (i = 0; i < MANY; ++i)
	    cout << char('A' + i) << ' ';
	cout << "." << endl;
	//prompting user to enter the polynomial for evaluation
	//taking input from user
	cout << "Please Enter the Polynomial for Evaluation: ";
	command = toupper(get_command());
    }
    while ((command < 'A') || (command >= char('A' + MANY)));
    return command - 'A';
}//end of set_current function test


//start to test_add function test
void test_add(polynomial& test)
{
    double coefficient;
    unsigned int exponent;

	//prompting user to enter exponent value
	//taking user input
    cout << "Please Enter Exponent Value: ";
    cin >> exponent;
	//Prompting user to enter the coefficient value
	//taking input from user
    cout << "Please Enter Coefficient Value: ";
    cin >> coefficient;
    
	test.add_to_coef(coefficient, exponent);
    cout << "After adding: ";
    view(test);
}//end of test_add function


//start of test_assign function test
void test_assign(polynomial& test)
{
    double coefficient;
    unsigned int exponent;
	//prompting the user to enter the exponent value
	//taking input from user
    cout << "Please Enter Exponent Value: ";
    cin >> exponent;
	//prompting the user to enter the coefficient
	//taking input from user
    cout << "Please Enter Coefficient Value: ";
    cin >> coefficient;

    test.assign_coef(coefficient, exponent);
    cout << "After assigning: ";
    view(test);
}//end of test_assign function test


//start of test_gif function
//void test_gif(const polynomial& test)
//{
//	char file_name[20];
//	double high_x, low_x, high_y, low_y;
//
//	cout << "Enter File Name to Write: ";
//	cin >> file_name;
//	cout << "Please Enter Upper X Bound: ";
//	cin >> high_x;
//
//	cout << "Please Enter Lower X Bound: ";
//	cin >> low_x;
//
//	cout << "Please Enter Upper Y Bound: ";
//	cin >> high_y;
//
//	cout << "Please Enter Lower Y Bound: ";
//	cin >> low_y;
//
//	make_gif(test, file_name, low_x, high_x, low_y, high_y);
//	cout << "The file has been written" << endl;
//}//end of test_gif function


//start of test_eval function test
void test_eval(const polynomial& test)
{
    double x_value;
	//prompting the user to enter the X value
	//taking input from user
    cout << "Please Enter the X Value: ";
    cin >> x_value;

    cout << "For the Polynomial: ";
    view(test);
    cout << "The evaluation returned is " << test(x_value) << endl;
}//end of test_eval funcion test


//start of view_all function test
void view_all(const polynomial p[])
{
    size_t i;
    cout << endl;
    for (i = 0; i < MANY; ++i)
    {
		cout << char(i + 'A') << ": ";
		view(p[i]);
    }
}//end of view_all function test


//start of test_clear function test
void test_clear(polynomial& test)
{
    test.clear( );
	//diplaying after claring data
    cout << "After clearing: ";
    view(test);
}//end of test_clear function test


//start of test_np function test (next polynomial)
void test_np(const polynomial& test)
{
    unsigned int exponent;
	//Prompting user to enter exponent
	//reading user input
    cout << "Please Enter the Exponent: ";
    cin >> exponent;
	//displaying polynomial
    cout << "For polynomial: ";
    view(test);
	//displaying the next_term
    cout << "The next_term(" << exponent << ") = "
	 << test.next_term(exponent) << endl;
	//displaying the previous_term
    cout << "The previous_term(" << exponent << ") = "
	 << test.previous_term(exponent) << endl;
}//end of next polynmial function