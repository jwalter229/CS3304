/*  Jason Walters
    Data Structures
    Tues Thurs 10am
 */
#include "Account.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;


Account :: Account()
{
    bal = 0;
    owner = "Default Name";
}
    
    Account :: Account(string name, double amount)
    {
        bal = amount;
        owner = name;
    }
    
    
    //start of balance method
    void Account :: balance()
    {
        cout << "Current Balance: " << bal << endl;
    }//end of balance mehtod
    
    
    //start of withdrawl method
    void Account :: withdrawal(double amount)
    {
        //asserting balance has to be
        //greater than or equal
        //to the amount of withdrawal
        assert(bal >= amount);
        
        //displaying Withdrawl Amount
        cout << "Withdrawal Amount: " << amount << endl;
        
        //diplaying bal after withdrawal 
        bal = bal - amount;
    }//end of withdrawal method
    
    
    //start of deposit method
    void Account :: deposit(double amount)
    {
        //displaying Deposit Amount
        cout << "Deposit Amount: " << amount << endl;
        
        //diplaying bal after deposit
        bal = bal + amount;
    }//end of deposit method
    
    
    //start of name change method
    void Account :: nameChange(string name)
    {
        //owner of account equals name
        owner = name;
        cout << "New Account Owner: " << owner << endl;
    }//end of name change method
    
    
    //start of current owner method
    void Account :: currentOwner()
    {
        cout << "Current Owner: " << owner << endl;
    }//end of current owner method