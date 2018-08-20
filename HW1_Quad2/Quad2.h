//Jason Walters
//DS 3304
//Tues and Thurs 10am


#include<iostream>
#include<cmath>

#ifndef Quad2_H
#define Quad2_H

class Quad2
{
public:
    Quad2();
    Quad2(double first, double second, double third);
   // ~Quad2();
   
   //creating getters 
   
    double get_a(){return a;};
    double get_b(){return b;};
    double get_c(){return c;};
   
   //creting the setters
   void set_a(double a2);
   void set_b(double b2);
   void set_c(double c2);
   
   //creating the 
   double evaluate_quadratic_expession(double x);
   int get_the_number_of_real_zeros();
   double get_postive_answer_of_quadratic_equation();
   double get_negative_answer_of_the_quadratic_equation();
   
private:
 double a;
 double b;
 double c;
};

#endif // QUADRATICEQUATIONS_H
