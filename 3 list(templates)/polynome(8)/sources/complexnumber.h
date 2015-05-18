#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include <iostream>

using namespace std;
struct numeral
{
    float RE;
    float IM;
};

class ComplexNumber
{
public:
    numeral Z;
    ComplexNumber(){Z.RE = 0;Z.IM = 0;}
    ComplexNumber(float a , float b)
    {
        Z.RE = a;
        Z.IM = b;
    }

    void input()
    {
         cin >> Z.RE;
         cin >> Z.IM;
    }
    void show()
    {
        cout<<"("<<Z.RE<<" + " << Z.IM << "i)";
    }
    void operator+=(ComplexNumber second)
    {
        Z.RE += second.Z.RE;
        Z.IM += second.Z.IM;
    }
    bool operator==(int second)
    {
        if (Z.RE == second && Z.IM == second)
            return 1;
        else
            return 0;
    }
};

ComplexNumber operator+(ComplexNumber first , ComplexNumber second)
{
    ComplexNumber Result;
    Result.Z.RE = first.Z.RE + second.Z.RE;
    Result.Z.IM = first.Z.IM + second.Z.IM;
    return Result;
}

ComplexNumber operator-(ComplexNumber first , ComplexNumber second)
{
    ComplexNumber Result;
    Result.Z.RE = first.Z.RE - second.Z.RE;
    Result.Z.IM = first.Z.IM - second.Z.IM;
    return Result;
}
//ComplexNumber operator-(ComplexNumber argument)
//{
//    argument.Z.RE = -argument.Z.RE;
//    argument.Z.IM = -argument.Z.IM;
//    return argument;
//}
ComplexNumber operator*(ComplexNumber first,ComplexNumber second)
{
   ComplexNumber Result;
   Result.Z.RE = first.Z.RE*second.Z.RE - first.Z.IM * second.Z.IM ;
   Result.Z.IM = first.Z.RE*second.Z.IM + first.Z.IM*second.Z.RE;
   return(Result);
}
ComplexNumber operator/(ComplexNumber first,ComplexNumber second)
{
    ComplexNumber Result;
    Result.Z.RE = first.Z.RE*second.Z.RE + first.Z.IM*second.Z.IM;
    Result.Z.IM = first.Z.IM*second.Z.RE - first.Z.RE*second.Z.IM;
    Result.Z.RE /=(second.Z.IM*second.Z.IM + second.Z.RE*second.Z.RE);
    Result.Z.IM /=(second.Z.IM*second.Z.IM + second.Z.RE*second.Z.RE);
    return Result;
}


#endif // COMPLEXNUMBER_H

