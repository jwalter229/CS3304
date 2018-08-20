#include "deque.h"

int main()
{
	cout << "Creating one empty deque. We will check if this deque is empty." << endl;
	
	deque<int> d1;
	
	if (d1.empty())
		{
			cout << "This deque is empty." << endl;
		}
		else
		{
			cout << "This deque is NOT empty." << endl;
		}
		
	cout << endl;
	
	cout << "Adding values (3, 4, 5) to the front of the deque (5 is the front )." << endl;
	d1.push_front(3);
	d1.push_front(4);
	d1.push_front(5);
	
	cout << endl;
	cout << "Testing to see the size of the deque. " << endl;
	cout << "The size of this deque is: " << d1.size() << endl;
	cout << endl;
	
	cout << "Popping the front value and then checking what the front value is now. After popping the front value should be 4." << endl;
	d1.pop_front();
	cout << "The front value after popping is: " << d1.front() << endl;
	
	cout << endl;
	cout << "Adding some values (9, 7, 6, 2) to the back of the deque (2 is the back). " << endl;
	d1.push_back(9);
	d1.push_back(7);
	d1.push_back(6);
	d1.push_back(2);
	cout << endl;
	
	cout << "Popping 2 values from the back and checking the new back value. After popping two of the back values, the back value should now be 7." << endl;
	d1.pop_back();
	d1.pop_back();
	
	cout << "After poping 2 values from the back, the back value is now: " << d1.back() << endl;
	
		cout << endl; // endln for spacing
		
		cout << "Printing all values of the deque from front to back. " << endl;
		cout << d1;
		
		cout << endl;
		cout << endl;
		
		cout << "Testing the copy constructor by making a new copied deque out of the first deque." << endl;
		deque<int> d2(d1);
		cout << endl;
		
		cout << "Testing if this deque is equal to the first deque." << endl;
		
		bool c = d1 == d2;
		if (c)
        {
			cout << "This deque is equal to the first deque." << endl;
		}
		
		else {
			cout << "This deque is NOT equal to the first deque." << endl;
		}
		cout << endl;
		
		cout << "Now we will create another deque, this time we'll add numbers 5, 2, 1 (1 is in the back)." << endl;
		deque<int> d3;
		d3.push_front(1);
		d3.push_front(2);
		d3.push_front(5);
		
		cout << "Front is: " << d3.front() << " back is: " << d3.back() << endl;
		cout << endl;
		
		cout << "Now we'll create another deque and set it equal (= operator) to this deque." << endl;
		deque<int> d4;
		d4 = d3;
		
		cout << "Printing this new deque. It should have the SAME values as the previous deque."<<endl;
		cout<<d4;
		
		cout << endl;
		cout << endl;
		
		cout << "Checking if this deque is equal to our first deque. They should NOT be equal." << endl;
		if (d4 == d1){
			cout << "They are equal." << endl;
		}
		else {
			cout << "They are NOT equal." << endl;
		}
		cout << endl;
		
		cout << "Now we will test our const front and back functions by creating a const instance of deque with 4 and 3 as parameters." << endl;
		cout << "4 will be the front and 3 will be the back." << endl;
		
		const deque<int> d5(4, 3);
		cout << "Front: " << d5.front() << " and back: " << d5.back() << endl;
}
