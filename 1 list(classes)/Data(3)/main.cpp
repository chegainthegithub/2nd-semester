#include <iostream>

#include "data.h"

using namespace std;

int main()
{
    Date *A = new Date(17,5,2014,"A.C.");
    Date *B = new Date(23,8,1996,"B.C.");
    A->show();
    B->show();
    unsigned a = DateInDays(A);
    unsigned b = DateInDays(B);
    cout << "a = "<<a<<" = "<<a/365<<endl;
    cout<<"b = "<<b<<" = "<<b/365<<endl;
    cout << difference(A,B)<<" = " << difference(A,B)/365<<endl;
    delete A;
    delete B;
    Date C ;
    string init = "17.5.2014 A.C.";
    C = init;
    C.show();
    Date D;
    D = init;
    D.Day++;
    D--;
    D.show();
    C.show();
    for(;C<&D;C++)
        cout<<"if you see it ,postfix increment works"<<endl;
    return 0;
}

