/*		Jason Walters
		Data Structures
		Tuesday - Thursday
		10 - 1215
*/

#include <cstdlib>
#include <iostream>
#include "set.h"

using namespace std;

void print_groups(const set& groupA, const set& groupB)
{
    cout << "Group A size: " << groupA.size() << endl;
    cout << "Group B size: " << groupB.size() << endl;
}

int main()
{
    set groupA, groupB;
    //populating the array 0 thru 19
    for (int i = 0; i < 20; ++i)
    {
        groupA.insert(i);
    }
    //printing to show size of array
	//should be == 20
    print_groups(groupA, groupB);
    
	
	//trying to insert 5 into the array
	groupA.insert(5);
    //sets do not allow for duplicates
	//printed set again to make sure size
	//did not change and was still 20
	print_groups(groupA, groupB);
    //checking to see if groupA size is equal to 20
	cout << ((groupA.size() == 20)? "Passed" : "Falied") << endl;
	
	
	//setting groupB equal to groupA
	//copying the groupA to fill groupB
    groupB = groupA;
    print_groups(groupA, groupB);
	//chekcing to see if groupB is equal to groupA in size
	cout << ((groupB.size() == groupA.size())? "Passed" : "Falied") << endl;
	
	
	//checking to see if groupB conatins 5
    cout << ((groupB.includes(5))? "Good Copy" : "Bad Copy") << endl;
	//clearing the 5 index from the groupB array
    groupB.clear(5);
    //printing groupA and groupB
	//groupA should be 20
	//groupB should be 19
	print_groups(groupA, groupB);
    
}//end of main()