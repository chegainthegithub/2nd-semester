#include <iostream>
#include <longnum.h>

using namespace std;

int main()
{
    LongNum a(2,9,1);
    LongNum b(2,9,1);
    LongNum c = a+b;
    c.show();
    b.show();
    return 0;
}

