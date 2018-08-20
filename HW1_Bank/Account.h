/*  Jason Walters
    Data Structures
    Tues Thurs 10am
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;

class Account
{
public:
    //creating constructers building objects
    Account();
    Account(string name, double amount);
    
    void withdrawal(double amount);
    void deposit(double amount);
    void nameChange(string name);
    void balance();
    void currentOwner();
    
private:
    double bal;
    string owner;
};

#endif // ACCOUNT_H
