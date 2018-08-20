#include <deque.h>
#include <iostream>

using namespace std;

int main()
{
	
	cout << "Creating one empty deque and we will check if this deque is empty." << endl;
	
	deque<int> d1;
	
	if (d1.empty())
		{
			cout << "The deque is empty." << endl;
		}
		
		else
		{
			cout << "The deque is not empty." << endl;
		}
		
	cout<<endl;
	
	cout << "Adding a few values (3, 4, 5) to the front of the deque. (5 is the front). " << endl;
	d1.push_front(3);
	d1.push_front(4);
	d1.push_front(5);
	
	cout << endl;
	cout << "Testing to see what size the deque is. " << endl;
	cout << "This deque has the size of: " << d1.size() << endl;
	cout<<endl;
	
	cout << "Popping the front value and then checking the front value.  The front value should be 4 after popping." << endl;
	d1.pop_front();
	cout << "The front value after popping is: " << d1.front() << endl;
	
	cout << endl;
	cout << "Adding some values to the back of the deque (9, 7, 6, 2) (2 is the back)." << endl;
	d1.push_back(9);
	d1.push_back(7);
	d1.push_back(6);
	d1.push_back(2);
	
	cout << endl;
	
	cout << "Popping two values from the back and checking the back value. After popping two of the back values, the new back value should be 7." << endl;
	d1.pop_back();
	d1.pop_back();
	cout << "After poping 2 values from the back, the back value is now: " << d1.back() << endl;
	
	cout << endl;
	cout << "Checking the size of the deque and check whether or not it is full." << endl;
	
	if (d1.full())
	{
		cout << "This deque is full and the size is: " << d1.size() << endl;
	}
		else
		{
			cout << "This deque is not full and the size is: " << d1.size() << endl;
		}
		
		cout << endl;
		
		cout << "Displaying all the values in this deque from front to back. " << endl;
		cout << d1;
		
		cout << endl;
		
		cout << "Creating another deque, filling it with numbers and displaying the contents. The deque will be exactly like the first. " << endl;
		deque<int> d2;
		d2.push_front(3);
		d2.push_front(4);
		d2.push_front(5);
		
		d2.pop_front();
		
		d2.push_back(9);
		d2.push_back(7);
		d2.push_back(6);
		d2.push_back(2);
		
		d2.pop_back();
		d2.pop_back();	
		cout<<d2;
		cout<<endl;
		
		bool c = d2 == d1;
		
		if (c)
		{
			cout << "Deque d2 and Deque d1 have the same contents and are the same size. " << endl;
		}
		
			else
			{
				cout << "This Deque d2 is not the same as d1." << endl;
			}
		
		cout << endl;
		
		cout << "Adding a number to the back of the second deque to test if it is still equal to the first deque. " << endl;
		d2.push_back(1);
		
		c = d2 == d1;
		
		if (c)
		{
			cout << "Deque d2 and Deque d1 have the same contents and are the same size. " << endl;
		}
		
			else
			{
				cout << "This Deque d2 is not the same as d1. " << endl;
			}
		
		cout << endl;
		
		cout << "Creating a third deque and filling it with numbers 1 through 10 (1 is in the front). " << endl;
		deque<int> d3;
		
		for (int i = 10; i >= 1; i--)
		{
			d3.push_front(i);
		}
		
		cout << d3;
		cout << endl;
		
		cout << endl;
		cout << "Checking to see of the third deque is full." << endl;
		c = d3.full();
		
		if (c)
		{
			cout << "This deque is full." << endl;
		}
		
			else
			{
				cout << "This deque is not full." << endl;
			}
		
		cout << endl;
		cout << "We will now test the next function. Checking to see what the value is after index 2 of this deque." << endl;
		cout << "The value after index 2 is: " << d3.get_next(2) << endl;
		
		cout << endl;
		cout << "We will now test the previous function. Checking to see what the value is before index 8." << endl;
		cout << "The value before index 8 is: " << d3.get_prev(8) << endl;
		
		cout << endl;
		cout << "Declaring a const instance of deque using the parameter constructor (front: 3, and back: 2), " <<
		"so that we can call the const front and const back function." << endl;
		
		const deque<int> d4(3, 2);
		cout << "Front: " << d4.front() <<" and back: " << d4.back() << endl;
		cout << endl;
}
