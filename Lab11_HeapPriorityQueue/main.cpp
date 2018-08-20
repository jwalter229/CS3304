

#include "Heap.h"
#include <iostream>
#include <ctime>
#include "priority_queue_heap.h"
#include "priority_queue_simple.h"

// Insert some elements into a neap and remove them
// one by one and see if we get them in the right order.

using namespace std;

void test_heapsort(int length);
// start of test1()
int test1() 
{

	cout << "First we will test the priority_queue_heap." << endl;
    priority_queue_heap<int> hp;
	// inserting into the
	// priority queue heap
    hp.insert(1);
    hp.insert(2);
    hp.insert(3);
    hp.insert(4);
    hp.insert(5);
	// displaying what in the
	// priority gueue heap
	cout << "The priority_queue_heap contains: ";
	hp.print();
	cout << endl;
	
	// calling remove() method/function
    int x = hp.remove();
    cout << "removed: " << x << endl;
    x = hp.remove();
    cout << "removed: " << x << endl;
    x = hp.remove();
    cout << "removed; " << x << endl;
    x = hp.remove();
    cout << "removed: " << x << endl;
    x = hp.remove();
    cout << "removed: " << x << endl;
	cout << endl;
    cout << "empty? " << hp.is_empty()<<endl;
}// end of test one


// start of test2()
void test2() 
{
	srand(time(NULL));
	cout << "Now testing the priority_queue_simple by inserting random values." << endl;
    priority_queue_simple<int> hp;

    for(int idx = 0; idx < 30; idx++) 
	{
        hp.insert(rand() % 101);
    }
	cout << "These numbers are removed in order: ";
	// while 
    while(!hp.is_empty()) 
	{
        int x = hp.remove();
        cout << x <<" ";
    }// end of while

	cout << endl;
	cout << endl;

	cout << "empty? " << hp.is_empty() << endl;
}// end of test2()


// start of main()
int main() 
{
	srand(time(NULL));

	cout << "Testing the test_heapsort function. " << endl;

	test_heapsort(7);
	// calling test1()
    test1();

	cout << endl;
	cout << endl;
	// calling test2()
    test2();

}// end of main()


// start of test_heapsort
void test_heapsort(int length)
{
	int data [length];

	cout << "Creating an array with these random values: ";

	for (int idx = 0; idx < length; idx++)
	{
		data[idx] = rand();
		cout << data[idx] << " ";
	}

	cout << endl;
	cout << endl;

	cout << "Creating a heap out of this array and sort it using the heap_sort function. " << endl;
	heap<int> h1;
	h1.heap_sort(data, 7);

	cout << "After adding all the removed vales from the heap to the array.  We are testing if the array is a heap. " << endl;
	cout << endl;
	h1.test_sorted(data, 7);

	cout << endl;
	cout << endl;

}// end of test_heapsort

