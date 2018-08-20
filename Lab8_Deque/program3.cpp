#include "stack_pair.h"

int main()
{
	stack_pair<int> s1;
	
	cout << "Populating both 'a' and 'b' stacks to their maximum." << endl;
	for (int i = 0; i <= 15; i++)
	{
		s1.push_a(i);
	}
	
	for (int i = 16; i <= 29; i++)
	{
		s1.push_b(i);
	}
	
	cout << endl;
	
	cout << "Attempting to add one more value to stack 'a'. The program should end. " << endl;
	s1.push_a(4);
}
