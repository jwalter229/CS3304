#include "stack_pair.h"

int main()
{
	stack_pair<int> s1;
	
	cout << "Creating a new stack pair and then push numbers (1, 2, 3) on the 'a' stack and numbers (4, 5, 6) on the 'b' stack" << endl;
	s1.push_a(1);
	s1.push_a(2);
	s1.push_a(3);
	
	s1.push_b(4);
	s1.push_b(5);
	s1.push_b(6);
	
	cout << endl;
	cout << "Popping all the numbers from stack 'a': " << endl;
	for (int i = s1.size_a(); i >= 1; i--)
	{
		cout << s1.pop_a() << " " << endl;
	}
	
	cout << endl;
	cout << "Popping all the numbers from stack 'b': " << endl;
	for (int i = s1.size_b(); i >= 1; i--)
	{
		cout << s1.pop_b() << " " << endl;
	}
	
}
