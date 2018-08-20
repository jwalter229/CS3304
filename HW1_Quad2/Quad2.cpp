//Jason Walters
//DS 3304
//Tues and Thurs 10am

#include<iostream>
#include"assert.h"
#include<cmath>
#include "Quad2.h"
using namespace std;

Quad2 :: Quad2()
{
    a = 1;
    b = 2;
    c = 3;
    
}

Quad2 :: Quad2(double A, double B, double C)
{
    a = A;
    b = B;
    c = C;
}
//Quad2 :: ~Quad2()
//{ 
    
//}
   
void Quad2 :: set_a(double A)
{
    a = A;
}

void Quad2 :: set_b(double B)
{
    b = B;
}

void Quad2 :: set_c(double C)
{
    c = C;
}

double Quad2 :: evaluate_quadratic_expession(double x)
{
    return (a * (x * x) + (b * x) + c);
}

int Quad2 :: get_the_number_of_real_zeros()
{
    double answer;
    if(a == 0 && b == 0)
    {
        return 0;
    }
    
    else 
    {
        if( a == 0)
            return 1;
    }
    
    //Q = b^2 - 4ac == (b * b) - (4 * a * c)
    double Q = (b * b) - ( 4 * a * c); //Q is this 
    
    if(Q >= 0)
    {
        answer = (((-b) + sqrt(Q)) / (2 * a));
        return answer;
    }
    
    else
        answer = (((-b) - sqrt(Q)) / (2 * a));
        return answer;
}


double Quad2 :: get_postive_answer_of_quadratic_equation()
{
    int n = get_the_number_of_real_zeros();
    
    assert(n > 0);
    double answer;
    if(a != 0)
    {
        answer = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    }
    else if(b != 0)
    {
        answer = - c / b;
    }
    
    return answer;
    
}

double Quad2 :: get_negative_answer_of_the_quadratic_equation()
{
    int n = get_the_number_of_real_zeros();
    
    assert( n > 0);
    double answer;
    if(a != 0)
    {
        answer = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
    }
    else if(b != 0)
    {
        answer = - c / b;
    }
    
    return answer;
    
}
 