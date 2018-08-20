#include "Quad.h"
#include <iostream>
#include <string>

using namespace std;

//testing Getters
bool Test_Gets()
{
    //Declare Objects
    //Passing 1,2,3 as parameters
    Quad test(1,2,3);
    
    bool passed = true;
    
    //GetA Test
    if(test.GetA() != 1)
    { 
       cout << "Get A failed" << endl;
       passed = false;
    }
    
    //GetB Test
    if(test.GetB() != 2)
    { 
       cout << "Get B failed" << endl;
       passed = false;
    }
    
    //GetC Test
    if(test.GetC() != 3)
    { 
       cout << "Get C failed" << endl;
       passed = false;
    }
    
    return passed;
}
 
//Testing x = 2 
//for x^2 + 2x + 3 = 11    
bool Test_Eval()
{
    Quad test(1,2,3);
    if(test.Eval(2) != 11)
    {
        cout << "Evaluate Failed Output. Expected 11." << endl;
        return false;
    }
    
    return true;
}  

//Testing to see how
//many zeros there are
bool Test_Cal_Number_Of_Zeros()
{
    bool passed = true;
    
    //Testing for 
    //no zeros
    Quad test1(0,0,5);
    if(!test1.Cal_Zero().empty())
    {
        cout << "Failed Calculate zeros at 0 zeros!" << endl;
        passed = false;
    }
    
    //Testing the Quad 
    //for one zero
    Quad test2(0,1,1);
    {
          if(test2.Cal_Zero().size() != 1)
        {
        cout << "Failed Calculate zeros at 1 zero" << endl;
        passed = false;
    }
        }
    
    //Testing the Quad 
    //for two zeros 
    Quad test3(1,0,-4);
    {
          if(test3.Cal_Zero().size()!=2)
    {
        cout << "Failed Calculate zeros at 2 zeros" << endl;
        passed = false;
    }
        return passed;
    }
}
    //Determing the zeros 
    //of the Quad
    bool Test_Cal_Zero()
    {
        Quad test (1,0,-4);
        vector <double> output = test.Cal_Zero();
        if(output[0] != 2 && output[0] != -2)
        {
            return false;
        }
        if(output[1] != 2 && output[1] != -2)
        {
            return false;
        }
        
        return true;
    }

    
int main(int argc, char **argv)
{
	if(Test_Gets() == true)
    {
        cout << "Passed Test_Gets!" << endl;
    }
    else
    {
        cout << "Failed Test_Gets!" << endl;
    }
    
    if(Test_Eval() == true)
    {
        cout << "Passed Test_Eval!" << endl;
    }
    
    else
    {
        cout << "Failed Test_Eval!" << endl;
    }
    
    if(Test_Cal_Number_Of_Zeros() == true)
    {
        cout << "Passed Test_Cal_Number_Of_Zeros!" << endl;
    }
    
    else
    {
        cout << "Failed Test_Cal_Number_Of_Zeros!" << endl;
    }
    
    if(Test_Cal_Zero() == true)
    {
        cout << "Passed Test_Zeros!" << endl;
    }
    
    else
    {
        cout <<"Failed Test_Zeros" << endl;
    }
}
