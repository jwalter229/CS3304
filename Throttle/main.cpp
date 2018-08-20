#include <iostream>
#include <cstdlib>
#include <throttle.h>

using namespace std;

const int DEMO_SIZE = 5; // Number of positions in a demonstration throttle

int main()
{
    throttle control;
    int user_input;
   
    control.shut_off();
    cout << "Please type a number from 0 to 6: ";
    cin >> user_input;
    control.shift(user_input);
    if (control.is_on( ))
        cout << "The flow is " << control.flow( ) << endl;
    else
        cout << "The flow is now off" << endl;
        
        
    throttle sample(DEMO_SIZE); // A throttle to use for our demonstration
    // Set the sample throttle to a position indicated by the user.
    cout << "I have a throttle with " << DEMO_SIZE << " positions." << endl;
    cout << "Where would you like to set the throttle?" << endl;
    cout << "Please type a number from 0 to " << DEMO_SIZE << ": ";
    cin >> user_input;
    sample.shift(user_input);
    // Shift the throttle down to zero, printing the flow along the way.
    while (sample.is_on()) {
        cout << "The flow is now " << sample.flow() << endl;
        sample.shift(-1);
    }
    cout << "The flow is now off" << endl;
        
    return EXIT_SUCCESS;
}
