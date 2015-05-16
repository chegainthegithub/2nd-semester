#ifndef POLYNOM_H
#define POLYNOM_H
#include <iostream>
#include "complexnumber.h"
using namespace std;

template <class Type>
class polynom
{
public:
    Type *polynomCoefficients;
    unsigned int polynomDegree;
    polynom(unsigned int degree,Type *coeffs)
    {
        polynomDegree = degree;
        /*delete polynomCoefficients;*/
         polynomCoefficients = new Type [degree];
        for (int i = 0 ; i < polynomDegree; i++)
            polynomCoefficients[i] = coeffs[i];
        //degreeOptimizer();
    }

    polynom(unsigned int degree,const int a)
    {
        polynomDegree = degree;
        /*delete polynomCoefficients;*/
         polynomCoefficients = new Type [degree];
         if (a>0)
             for (unsigned i = 0 ; i < polynomDegree; i++)
               polynomCoefficients[i].input();
         //degreeOptimizer();
    }

    void show()
   {
        if (polynomDegree == 0)
        {
            cout << "0"<<endl;
            return;
        }
       for (unsigned i = 0; i < polynomDegree;i++)
       {
           polynomCoefficients[i].show(); cout << "x^" << i ;
           if (i!=polynomDegree-1)
               cout<<" + ";
           else
               cout << endl;
       }
   }

   void input()
   {
       for (int i = 0 ; i < polynomDegree;i++)
           polynomCoefficients[i].input();
       //degreeOptimizer();
   }

   void degreeOptimizer()
   {
       unsigned counter = 1 ;
       while(polynomCoefficients[polynomDegree - counter] == 0 && polynomDegree>0)
           polynomDegree--;
        Type* newcoeff = new Type [polynomDegree];
        for(unsigned i = 0;i<polynomDegree;i++)
            newcoeff[i] = polynomCoefficients[i];
        polynomCoefficients = newcoeff;
   }
    void sum(polynom <Type> *incomePoly)
    {
        if (incomePoly->polynomDegree > polynomDegree)
        {
            Type *buffer = new Type [incomePoly->polynomDegree];
            for (int i = 0 ; i < polynomDegree;i++)
            {
                buffer[i] = incomePoly->polynomCoefficients[i] + polynomCoefficients[i];
            }
            for(int i = polynomDegree;i < incomePoly->polynomDegree;i++)
                buffer[i] = incomePoly->polynomCoefficients[i];
            polynomCoefficients = buffer;
            polynomDegree = incomePoly->polynomDegree;
            delete buffer;
        }
        else
            for (int i = 0 ; i < incomePoly->polynomDegree;i++)
            {
                polynomCoefficients[i] = polynomCoefficients[i] + incomePoly->polynomCoefficients[i];
            }
        degreeOptimizer();
    }
        void subtr(polynom <Type> *incomePoly)
        {
            if (incomePoly->polynomDegree > polynomDegree)
            {
                Type *buffer = new Type [incomePoly->polynomDegree];
                for (int i = 0 ; i < polynomDegree;i++)
                {
                    buffer[i] = polynomCoefficients[i] - incomePoly->polynomCoefficients[i];
                }
                for(int i = polynomDegree;i < incomePoly->polynomDegree;i++)
                    buffer[i] = buffer[i] - incomePoly->polynomCoefficients[i];
                polynomCoefficients = buffer;
                polynomDegree = incomePoly->polynomDegree;
                delete buffer;
            }
            else
                for (int i = 0 ; i < incomePoly->polynomDegree;i++)
                {
                    polynomCoefficients[i] = polynomCoefficients[i] - incomePoly->polynomCoefficients[i];
                }
            degreeOptimizer();
        }

    void prod(polynom <Type> *IncomePoly)
    {
      Type *buffer = new Type [polynomDegree+IncomePoly->polynomDegree - 1];
//      for(int i = 0 ; i < polynomDegree+IncomePoly->polynomDegree;i++)
//          buffer[i];
      for(unsigned i = 0 ;i < polynomDegree;i++)
        {
            for (unsigned j = 0 ; j < IncomePoly->polynomDegree;j++)
            {
                    buffer[i+j] = buffer[i+j] + polynomCoefficients[i]*IncomePoly->polynomCoefficients[j];
            }
        }
      polynomDegree = polynomDegree+IncomePoly->polynomDegree - 1;
       for(unsigned i =0;i<polynomDegree;i++)
           polynomCoefficients[i] = buffer[i];

      degreeOptimizer();
     }
    Type pointCalculator(Type point)
    {
        Type result;
        Type increment = point;
        for(int i = 0;i<polynomDegree;i++)
        {
            result+=increment*polynomCoefficients[i];
            increment = increment*point;
        }
        return result;
    }
    void div(polynom<Type> *incomePoly)
    {
        int difference = polynomDegree - incomePoly->polynomDegree;;
        if(difference<0)
        {
            polynomDegree = 0;
            polynomCoefficients = NULL;
            return ;
        }
        if(incomePoly->polynomDegree == 0)
        {
            cout << "0 devision!"<<endl;
                return ;
        }
        polynom<Type>result(polynomDegree,0) ;
        polynom<Type> denominator = *incomePoly;
        unsigned counter = 1;
        while  (polynomDegree>= incomePoly->polynomDegree)
        {


            Type productor = polynomCoefficients[polynomDegree-1]/denominator.polynomCoefficients[denominator.polynomDegree-1];
//            cout<<"the poly ";show();
//            cout <<"size "<<polynomDegree<<endl;
//            cout<<"productor ";productor.show();
//            cout << endl;
            for(int i = 0 ;i<incomePoly->polynomDegree;i++)
                denominator.polynomCoefficients[i]=denominator.polynomCoefficients[i]*productor;
           // cout<<"denomenator ";denominator.show();
            result.polynomCoefficients[polynomDegree - denominator.polynomDegree]=productor;
            polynom<Type> *local = new polynom<Type>(polynomDegree,0);

            for (int i = 0;i<denominator.polynomDegree;i++)
            {
                local->polynomCoefficients[i+polynomDegree - denominator.polynomDegree] = denominator.polynomCoefficients[i];

            }
            denominator = *local;
            //cout<<"denomenator ";denominator.show();
            subtr(&denominator);

             //
            counter++;
            denominator = *incomePoly;
            //cout<<"denomenator ";denominator.show();
        }

        *this = result;
    }

    void mod(Type *incomePoly)
    {
        polynom<Type>CopyPoly = *this;
        CopyPoly.div(*incomePoly);
        subtr(&CopyPoly);
    }

};
#endif // POLYNOM_H

