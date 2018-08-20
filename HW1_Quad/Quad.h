#ifndef Quad_H
#define Quad_H
#include <vector>
#include <cmath>

using namespace std;

class Quad
{
public:
    //constructor. Takes in a,b, and c and sets the new object members variable a_,b_,C_
    Quad(double a, double b, double c);
    ~Quad();
    
    // Getters. return the varaible
    double GetA() {return a_;};
    double GetB() {return b_;};
    double GetC() {return c_;};
    
    //Examines the expression with x as the parameter 
    //and returns result as a double
    double Eval(double x);
    
    //Calculates the zeros in the expression 
    //Returns the value of the zeros in the vector. 
    vector<double> Cal_Zero();
    
    // Returns the number of zeros in the expression
    int CalculateZeroCount();
    
private:
double a_;
double b_;
double c_;

};

#endif // Quad_H
