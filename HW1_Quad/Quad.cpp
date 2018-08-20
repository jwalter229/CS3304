#include "Quad.h"

Quad :: Quad(double a, double b, double c)
{
    a_= a;
    b_= b;
    c_= c;
}

Quad :: ~Quad()
{
    
}


double Quad :: Eval(double x)
{
    return (pow(x,2) * a_ + (b_ * x) + c_);
}

vector<double> Quad :: Cal_Zero()
{
    
    vector <double> zeros;
    switch (CalculateZeroCount())
    {
        // If there are no zeros, return empty vector
        case 0: return zeros;
        
        //if there is one zero calculate the zero and push into back of vector
        case 1:
        {
            zeros.push_back( -c_ / b_);
            return zeros;
        }
        case 2:
        {
            zeros.push_back((-b_ + sqrt(pow(b_,2) - (4 * a_ * c_)) / (2 * a_)));
            zeros.push_back((-b_ - sqrt(pow(b_,2) - (4 * a_* c_)) / (2 * a_)));
            return zeros;
        }
          default: return zeros;
    }
}
       

int Quad :: CalculateZeroCount()
{
    if(a_ == 0 && b_ == 0)
    {
        return 0;
    }
    
    else if(a_ == 0)
    {
        return 1;
        
    }
    else
    {
        return 2;
    }
    
   
}