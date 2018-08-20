#include <iostream>
#include <string>

using namespace std;

void numbers(ostream& outs, const string& prefix, unsigned int levels);
void pattern(ostream& outs, unsigned int n, unsigned int i);

int main()
{
	// call the funcitons with defalt parameters.
	// parameters can be changed and functions
	// funcitons will print based on that change
	numbers(cout, "THERBLIG", 2);
	pattern(cout, 8, 0);
}// end of main

// start of numbers function
// this function will print out sections
void numbers(ostream& outs, const string& prefix, unsigned int levels)
{
	// if levels is equal to 0.
	if (levels == 0) 
	{
        outs << prefix << endl;
        return;
    }
	// continue to print out sections
	for (int idx = 1; idx <= 9; idx++)
	{
        string dot = (levels == 1 ? "" : "."); 
        string s = prefix +  char('0'  + idx)  + ".";
        numbers(outs, s, levels - 1);
   }
}// end of numbers function


// start of pattern function
// used to print pattern
void pattern(ostream& outs, unsigned int n, unsigned int idx)
{
		// this is the base case
		if (n == 1)
		{
			for (int kdx = 0; kdx < idx; kdx++)
				outs << " ";

				outs << "*";
		}
		else{
			// call the function with
			// n / 2, power of 2
			pattern(outs, n / 2, idx);
			outs<<endl;
			
			for (int kdx = 0; kdx < idx; kdx++)
			{
				outs << " ";
			}
			
			for (int kdx = 0; kdx < n; kdx++)
			{
				outs << "* ";
			}
			outs << endl;
			pattern(outs, n / 2, idx + n);
		}
}// end of patteren function
