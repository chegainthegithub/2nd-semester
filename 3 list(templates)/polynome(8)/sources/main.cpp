#include <iostream>
#include "polynom.h"
#include "complexnumber.h"

using namespace std;

int main()
{
    polynom <ComplexNumber> A(1,1);
    polynom <ComplexNumber> B(1,1);
    cout<<"A = ";A.show();
    cout << "B = ";B.show();
    A.div(&B);
    cout << "A/B = ";A.show();
    cout <<"====================================================="<<endl;
    cout << "B = ";B.show();
    system("pause");
    return 0;
}

