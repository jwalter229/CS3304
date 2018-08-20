#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "bag.h"

using namespace std;

int main()
{
    
    bag x; //instance of class
    x.insert(20);
    x.insert(14.3);  // will fail the compiler ???????????????
    cout << "bag size is " << x.size() << endl;
    cout<<"bag capacity is " << bag :: CAPACITY <<endl;
    
    bag bag1;
    bag bag2;
    int data1[] = {1,2,3,1,2,3,3};
    int data2[] = {3,4,5,3,4,5};
    for(int i = 0; i < 7; i++ ) {
        bag1.insert(data1[i]);
    }
    for(int i = 0; i < 6; i++ ) {
        bag2.insert(data2[i]);
    }
    cout << "size of bag1 is " << bag1.size() << endl;
    cout << "size of bag2 is " << bag2.size() << endl;
    cout << "count of 3's in bag1: " << bag1.count(3) << endl;

    bag1 += bag2;
    cout << "size of bag1 is " << bag1.size() << endl;
    cout << "size of bag2 is " << bag2.size() << endl;
    cout << "count of 3's in bag1: " << bag1.count(3) << endl;

    bag bag3 = bag1 + bag2;
    cout << "size of bag3 is " << bag3.size() << endl;
    
	return EXIT_SUCCESS;
}
