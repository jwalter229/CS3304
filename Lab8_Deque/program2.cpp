#include "stack_pair.h"

int main()
{
	stack_pair<int> s1;
	
	cout << "Populating both 'a' and 'b' stacks to their maximum. " << endl;
	for (int i = 0; i <= 15; i++)
	{
		s1.push_a(i);
	}
	
	for (int i = 16; i <= 29; i++)
	{
		s1.push_b(i);
	}
	
	cout << endl;
	cout << "Checking if the stack full functions return true. " << endl;
	
	if (s1.is_full_a() && s1.is_full_b())
	{
		cout << "True: Stacks 'a' and 'b' are full." << endl;
	}
	
		else
		{
			cout << "False: Stacks 'a' and 'b' are not full. " << endl;
		}
}
