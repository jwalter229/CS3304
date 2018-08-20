#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include "node2.h"
#include "bag5.h"

using namespace std;



// PROTOTYPE for a function used by this demonstration program
template <class Item, class SizeType, class MessageType>
void get_items(bag<Item>& collection, SizeType n, MessageType description)
// Postcondition: The string description has been written as a prompt to the
// screen. Then n items have been read from cin and added to the collection.
// Library facilities used: iostream, bag4.h
{
    Item user_input; // An item typed by the program's user
    SizeType i;

    cout << "Please type " << n << " " << description;
    cout << ", separated by spaces.\n";
    cout << "Press the <return> key after the final entry:\n";
    for (i = 1; i <= n; ++i)
    {
        cin >> user_input;
        collection.insert(user_input);
    }
    cout << endl;
}// end of get_items

int main()
{
    //demostrate how to use set template class
    set <string> actors1;
    set <string> actors2;
    set <string> result;
    set<string>::iterator role;
    actors1.insert("moe");
    actors1.insert("curly");
    actors2.insert("larry");
    actors2.insert("curly");
    
    for(role = actors1.begin(); role != actors1.end(); ++role)
        cout << *role << " ";
    cout<<endl;
    
    for(role = actors2.begin(); role != actors2.end(); ++role)
        cout << *role << " ";
    cout<<endl;
    
    // Notice how we create the output iterator for the fifth argument:
    set_union(actors1.begin(), actors1.end(),
              actors2.begin(), actors2.end(),
              inserter(result, result.begin()));
    for (role = result.begin(); role != result.end(); ++role) {
        cout << *role << " ";
    }
    cout << endl;
    
    
    // demonstrating how to use node iterator for node template class
    node<int> *head_ptr = new node<int>();
    list_head_insert(head_ptr, 42); // goes in first
    list_head_insert(head_ptr, 13); // goes in second
    list_head_insert(head_ptr, 67); // goes in third		NEW head now in first postion
										//	order look like 67, 13, 42 
    
    node_iterator<int> start(head_ptr);
    node_iterator<int> finish;
    node_iterator<int> position;
    
    for (position = start; position != finish; ++position)
        cout << *position << " ";
    cout << endl;  
    
    
    //demonstrate bag template class
    bag<int> bag_of_int;
    bag<string> bag_of_string;

	bag_of_int.insert(3); // inserting a 3 into bag_of_int


    bag_of_string.insert("hello");
    bag_of_string.insert("goodbye");
    bag_of_string.insert("auf wiedersehen");
    bag_of_string.insert("goodbye");
    bag_of_string.insert("hello");
    bag_of_string.insert("goodbye");
	
    cout << "count of goodbye: " << bag_of_string.count("goodbye") << endl;
    cout << "count of guten morgen: " << bag_of_string.count("guten morgen") << endl;
    cout << "count of 3: " << bag_of_int.count(3) << endl;
    

    for(bag<string>::iterator cursor = bag_of_string.begin(); cursor != bag_of_string.end(); ++cursor)
        cout << *cursor << " ";
    cout << endl;  
    cout << endl;
	
	cout<<"Checking the range of the function by providing some values: " <<endl;
	bag<int> second_bag_of_int;
	second_bag_of_int.insert(7);
	second_bag_of_int.insert(6);
	second_bag_of_int.insert(5);
	second_bag_of_int.insert(4);
	second_bag_of_int.insert(3);
	second_bag_of_int.insert(2);
	second_bag_of_int.insert(1);
	second_bag_of_int.print_value_range(2 ,5);
	cout << endl;
	second_bag_of_int.print_value_range(2 ,78);
	cout << endl;
	second_bag_of_int.print_value_range(2 ,1);
	cout << endl;
	second_bag_of_int.print_value_range(8 ,5);
	cout << endl;
	
	cout << "Checking the repetitions function by removing all repetitions from bag_of_string: " << endl;
	bag_of_string.remove_repetitions();
	cout << endl;
	
	cout << "Checking the repetitions function by removing all repetitions from bag_of_int: " << endl;
	bag_of_int.remove_repetitions();
	cout << endl;
	
	cout << "Adding a few numbers in the bag_of_int bag and removing all repetitions: " << endl;
	bag_of_int.insert(2);
	bag_of_int.insert(7);
	bag_of_int.insert(2);
	bag_of_int.insert(7);
	bag_of_int.insert(3);
	bag_of_int.insert(5);
	bag_of_int.insert(2);
	bag_of_int.insert(8);
	
	cout << "Checking the repetitions functions by removing all repetitions from bag_of_int: " << endl;
	bag_of_int.remove_repetitions();
	return EXIT_SUCCESS;
}
