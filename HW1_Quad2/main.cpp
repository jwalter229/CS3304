//Jason Walters
//DS 3304
//Tues and Thurs 10am


#include<iostream>
#include"assert.h"
#include<cmath>
#include "Quad2.h"
using namespace std;

//Test program to evelaute fuctions of program Quad2

////Remember ax^2 + bx + c = 0
    //Quadratic fromula looks like x = (-b +- sqrt(b^2 - 4ac)) / (2a)
    
    // if Q = b * b - 4 * a * c  then the two roots are equal

    //To find positive root x = (-b + sqrt(b^2 - 4ac)) / (2a)
    //To find negitive root x = (-b - sqrt(b^2 - 4ac)) / (2a)
    
int main()
{
    
    Quad2 Q1(1, -2, 1);   
    cout << Q1.get_a() << "x^2 + " << Q1.get_b() << "x + " << Q1.get_c() << endl;
    cout << "Number of real zeros: " << Q1.get_the_number_of_real_zeros() << endl;
    cout << "Positive answer of the quadratic: " << Q1.get_postive_answer_of_quadratic_equation() << endl;
    
    if (Q1.get_negative_answer_of_the_quadratic_equation() > -1)
        {
            cout << "No negitive answer " << endl;
        } else {
            cout << "Negative answer of the quadratic: " << Q1.get_negative_answer_of_the_quadratic_equation() << endl;
        }

   
    cout << "Evaluate the quadratic at 0: "<< Q1.evaluate_quadratic_expession(0) << endl;
    
    return 0;
}  