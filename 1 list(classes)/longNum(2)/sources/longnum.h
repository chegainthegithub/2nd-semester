#ifndef LONGNUM_H
#define LONGNUM_H
#include <iostream>

using namespace std;

class LongNum
{

public:
    bool isUpperZero;
    int *numbers = new int;
    unsigned size;
    LongNum()
    {
        isUpperZero = true;
        size = 0;
        numbers = new int[0];
    }
    LongNum(const unsigned _size,const bool sign)
    {
        numbers = new int[_size];
        size = _size;
        input_numbers();
        for (unsigned i = 0 ;i<size;i++)
            if(!sign)
                numbers[i]=-numbers[i];
        isUpperZero = sign;
    }
//    LongNum(unsigned _size, unsigned *_arr)
//    {
//        numbers = new unsigned(_size);
//        for (unsigned i = 0;i<_size;i++ )
//            numbers[i] = _arr[i];
//    }
    LongNum(unsigned _size,int num,bool sign)
    {
        size = _size;
        numbers = new int[size];
        for (unsigned i = 0;i<_size;i++ )
        {
            numbers[i] = num%10;
            if (!sign)
                numbers[i] = -numbers[i];
        }
        isUpperZero = sign;
    }

    void input_numbers()
    {
        int buffer = 0;
        for(unsigned i =0;i<size;i++)
            numbers[i] = buffer%10;
    }
    void show()
    {
        OptimizeBySize();
        if(!isUpperZero)
            cout << "-";
        for(unsigned i =1;i<=size;i++)
        {
            if(!isUpperZero)
                cout<<-numbers[size-i];
            else
                cout << numbers[size-i];
        }
        cout<<endl;

    }
    bool operator>(LongNum second)
    {
        if (!isUpperZero)
        {
            if (second.isUpperZero)
                return false;
            if(size > second.size)
                return false;
            if(size < second.size)
                return true;
            for(int i=size-1;i>=0;i--)
            {
                if(numbers[i]>second.numbers[i])
                    return false;
                if(numbers[i]<second.numbers[i])
                    return true;
            }
            return false;
        }
        if(size < second.size)
            return false;
        if(size > second.size)
            return true;
        for(int i=size-1;i>=0;i--)
        {
            if(numbers[i]>second.numbers[i])
                return true;
            if(numbers[i]<second.numbers[i])
                return false;
        }
        return false;
    }
    void operator =(LongNum second)
    {
        size = second.size;
        numbers = new int [size];
        for (unsigned i =0;i<size;i++)
            numbers[i] = second.numbers[i];
        isUpperZero = second.isUpperZero;
    }
    void optimize()
    {
        for(unsigned i = 0;i<size-1;i++)
        {
            numbers[i+1] += numbers[i]/10;
            numbers[i] %=10;
        }
    }
    void OptimizeBySize()
    {
        int buffer = numbers[size-1];
        unsigned i = size-2;
        while(buffer==0&&i>0)
        {
            buffer = numbers[i];
            size--;
            i--;
        }
    }

};
LongNum abs(LongNum Number)
{
    LongNum result(Number.size,0,1);
        for(unsigned i = 0;i<Number.size;i++)
        {
            result.numbers[i] = Number.numbers[i];
            if(!Number.isUpperZero)
                result.numbers[i] = result.numbers[i]*(-1);
        }
    return result;
}

LongNum operator + (LongNum first,LongNum second)
{
    unsigned MaxSize;
    if (first.size>second.size)
        MaxSize = first.size+1;
    else
        MaxSize = second.size+1;
    LongNum result(MaxSize,0,1);
    LongNum firstABS = abs(first);
    LongNum secondABS = abs(second);
    if(firstABS > secondABS)
        result.isUpperZero = first.isUpperZero;
    else
        result.isUpperZero = second.isUpperZero;
    if (MaxSize == first.size+1)
    {
        for(unsigned i = 0 ; i<second.size;i++)
        {
            result.numbers[i+1] = (result.numbers[i] + first.numbers[i] + second.numbers[i])/10;
            result.numbers[i] = (result.numbers[i] + first.numbers[i] + second.numbers[i])%10;

        }
        for(unsigned i = second.size;i<first.size;i++)
        {
            result.numbers[i] = (result.numbers[i] +first.numbers[i]);
            result.numbers[i+1] = (result.numbers[i] +first.numbers[i])/10;
            result.numbers[i] %=10;

        }
    }
    else
    {
        for(unsigned i = 0 ; i<first.size;i++)
        {
            result.numbers[i+1] = (result.numbers[i] + first.numbers[i] + second.numbers[i])/10;
             //result.show();
            result.numbers[i] = (result.numbers[i] + first.numbers[i] + second.numbers[i])%10;
            //result.show();
        }
        for(unsigned i = first.size;i<second.size;i++)
        {
            result.numbers[i] = (result.numbers[i] + second.numbers[i]);
             //result.show();
            result.numbers[i+1] = (result.numbers[i] + second.numbers[i])/10;
             //result.show();
            result.numbers[i] %=10;
            //result.show();
        }
    }
    if (result.numbers[result.size-1]==0)
        result.size -=1;
    return result;
}
LongNum operator - (LongNum first,LongNum second)
{


    if(first.isUpperZero != second.isUpperZero)
    {
        LongNum second1 = second;
        second1.isUpperZero = !(second.isUpperZero);
        for(unsigned i=0;i<second.size;i++)
            second1.numbers[i] = -second.numbers[i];
        return first + second1;
    }
    LongNum result;
    LongNum decriment;
    bool sign = true;
    LongNum first1 = abs(first);
    LongNum second1 = abs(second);
    if (first1.size>second1.size)
    {
        result = first1;
        decriment = abs(second);
        sign = first.isUpperZero;
    }
    else
    {
        result = second1;
        decriment = abs(first);
        sign = !second.isUpperZero;
    }
    for(unsigned i = 0 ;i<decriment.size;i++)
    {
        result.numbers[i] -=decriment.numbers[i];
        if (result.numbers[i]<0)
        {
            result.numbers[i]+=10;
            result.numbers[i+1]-=1;
        }
    }
    result.isUpperZero = sign;
    if (!sign)
        for(unsigned i =0;i<result.size;i++)
            result.numbers[i] *=-1;
    return result;
}
LongNum operator * (LongNum first , LongNum second)
{
    LongNum first1 = abs(first);
    LongNum second1 = abs(second);
    LongNum result;
    unsigned size_buffer = 0;
    LongNum productor;
    if(first.size>second.size)
    {
        size_buffer = first.size;
        size_buffer += 1;
        size_buffer *=2;
        result = LongNum (size_buffer,0,true);
        result = first1+result;
        productor = second1;
    }
    else
    {
        size_buffer = second.size;
        size_buffer += 1;
        size_buffer *=2;
        result= LongNum(size_buffer,0,1);
        result = second1+result;
        productor = first1;
    }
    LongNum result_buffer;
    LongNum result_comebacker = result;
    //cout<<"BACKER ";result_comebacker.show();
    result = LongNum(result.size,0,1);
    //result.show();
    for(int i=0;i<productor.size;i++)
    {
        result_buffer = result_comebacker;
        unsigned lastnum = (size_buffer-1)/2-1;

        for(int j = lastnum;j >= 0;j--)
            swap(result_buffer.numbers[j+i],result_buffer.numbers[j]);
        //cout<<"buffer = ";result_buffer.show();
        for(int j=i;j<lastnum+i+1;j++)
            result_buffer.numbers[j] *=productor.numbers[i];
        //cout<<"buffer = ";result_buffer.show();

        result = result+result_buffer;
        //result.show();
        //cout<<"BACKER ";result_comebacker.show();
    }
    if (first.isUpperZero != second.isUpperZero)
    {
        for(unsigned i =0;i<result.size;i++)
            result.numbers[i] *=(-1);
        result.isUpperZero = false;
    }
        return result;
}
LongNum operator ^(LongNum income, unsigned degree)
{
    LongNum result = income;
    for(unsigned i = 1;i<degree;i++)
        result = result * income;
    return result;
}



#endif // LONGNUM_H

