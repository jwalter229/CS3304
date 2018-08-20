/*  Jason Walters
    Data Structures
    Tues Thurs 10am
 */

#include <Account.h>
#include <iostream>

int main()
{ 
    cout << "Account One " << endl;
    Account account1(" Matt Stafford ", 1000);
    account1.currentOwner();
    account1.balance();
    account1.withdrawal(500);
    account1.deposit(100);
    account1.balance();
    account1.nameChange(" Alex Smith ");
    cout << endl;
    
    cout << "Account Two " << endl;
    Account account2(" Matt Ryan ", 5000);
    account2.currentOwner();
    account2.balance();
    account2.withdrawal(500);
    account2.balance();
    cout << endl;
    
    cout << "Account Three " << endl;
    Account account3( " Bobby Lee ", 15000);
    account3.currentOwner();
    account3.balance();
    account3.deposit(5000);
    account3.balance();
    cout << endl;
    
    cout << "Account Four " << endl;
    Account account4(" Tom Brady ", 500);
    account4.currentOwner();
    account4.balance();
    account4.withdrawal(100);
    account4.balance();
    account4.deposit(200);
    account4.balance();
    
	return 0;
}// end of main
