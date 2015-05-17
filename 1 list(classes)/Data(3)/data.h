#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

class Date
{

public:
    bool isBC;
    int *MonthInDays = new int [12];
    int Day;
    int Month;
    int Year;
    Date()
    {
        Day = 1;
        Month = 1;
        Year = 1;
        isBC = false;
        int buffer_for_table[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        for (int i =0;i<12;i++)
            MonthInDays[i] = buffer_for_table[i];
    }


    Date(int D,int M,int Y,string era)
    {
        Day = D;
        Month = M;
        Year = Y;
        if(Year%400==0||(Year%4==0&&Year%100!=0))
        {
           int buffer_for_table[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
                for (int i =0;i<12;i++)
                    MonthInDays[i] = buffer_for_table[i];
        }
        else
        {
            int buffer_for_table[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
                 for (int i =0;i<12;i++)
                     MonthInDays[i] = buffer_for_table[i];
        }
        if (era == "B.C.")
            isBC = true;
        else
            isBC = false;
    }
    void show()
    {
        cout<<Day<<"."<<Month<<"."<<Year;
        if(isBC)
            cout<< " B.C."<<endl;
        else
            cout<< " A.C."<<endl;
    }
    Date& operator++()  //prefix ++Date
    {
        ++Day;
        if (Day>MonthInDays[Month-1])
        {
            Day = 0;
            ++Month;
            if(Month==13)
            {
                Month = 0;
                if(isBC)
                    --Year;
                else
                    ++Year;
                if (Year == 0)
                {
                    isBC = false;
                    ++Year;
                }
             }
        }
        if(Year%400==0||(Year%4==0&&Year%100!=0))
            MonthInDays[1]=29;
        return *this;
    }
    Date operator++(int)  //postfix Date++
    {
        Date copy = *this;
        ++Day;
        if (Day>MonthInDays[Month-1])
        {
            Day = 0;
            ++Month;
            if(Month==13)
            {
                Month = 0;
                if(isBC)
                    --Year;
                else
                    ++Year;
                if (Year == 0)
                {
                    isBC = false;
                    ++Year;
                }
             }
        }
        if(Year%400==0||(Year%4==0&&Year%100!=0))
            MonthInDays[1]=29;
        return copy;
    }
    Date operator--(int)  //postfix Date--
    {
        Date copy = *this;
        --Day;
        if (Day==0)
        {
            --Month;
            if(Month!=0)
            Day = MonthInDays[Month-1];
            if(Month==0)
            {
                Month = 12;
                if(isBC)
                    ++Year;
                else
                    --Year;
                if (Year == 0)
                {
                    isBC = false;
                    --Year;
                }
             }
        }
        if(Year%400==0||(Year%4==0&&Year%100!=0))
            MonthInDays[1]=29;
        return copy;
    }
    Date& operator--()  //prefix --Date
    {
        --Day;
        if (Day==0)
        {
            --Month;
            if(Month!=0)
                Day=MonthInDays[Month-1];
            if(Month==0)
            {
                Month = 12;
                if(isBC)
                    ++Year;
                else
                    --Year;
                if (Year == 0)
                {
                    isBC = false;
                    --Year;
                }
             }
        }
        if(Year%400==0||(Year%4==0&&Year%100!=0))
            MonthInDays[1]=29;
        return *this;
    }

    void operator = (Date *second)
    {
        Day = second->Day;
        Month = second->Month;
        Year  = second->Year;
        isBC = second->isBC;
    }
    void operator =  (string income)
    {
        const string initializer = income;
        string buffer;
        int j = 0;
        while(initializer[j]!='.')
        {
             buffer+=initializer[j];
             j++;
        }
        Day = atoi(buffer.c_str());

        string buffer1 ;
        j++;
        while(initializer[j]!='.')
        {
             buffer1+=initializer[j];
             j++;
        }
        Month=atoi(buffer1.c_str()) ;

        string buffer2;
        ++j;
        while(initializer[j]!=' ')
        {
             buffer2+=initializer[j];
             j++;
        }
        Year  = atoi(buffer2.c_str());

        string buffer3;
        ++j;
        for(j;j<initializer.size();j++)
        {
             buffer3+=initializer[j];
        }
        if(buffer3 == "B.C.")
                    isBC = true;
        else
            isBC = false;
        if(Year%400==0||(Year%4==0&&Year%100!=0))
            MonthInDays[1]=29;
    }
    bool operator<=(Date*);
    bool operator<(Date*);
};
Date Maxdate(Date *first,Date *second)
{
    if(first->Year>second->Year)
        return *first;
    if(second->Year>second->Year)
        return *second;
    if (first->Month>second->Month)
        return *first;
    if(second->Month>first->Month)
        return *second;
    if(first->Day>second->Day)
        return *first;
    else
        return *second;
}
unsigned DateInDays(Date *target)
{
   int result=0;
   if(target->isBC)
   {
       for (int i = 0;i<target->Year;i++)
       {
           if(i%400==0||(i%4==0&&i%100!=0))
               result+=366;
           else
               result+=365;
       }
       for(int i =1;i<target->Month;i++)
           result-=target->MonthInDays[i-1];
       result-=target->Day;
   }
   else
   {
       for (int i = 1;i<target->Year;i++)
       {
           if(i%400==0||(i%4==0&&i%100!=0))
               result+=366;
           else
               result+=365;
       }
       for(int i =1;i<target->Month;i++)
           result+=target->MonthInDays[i-1];
       result+=target->Day;

   }
   return result;
}

unsigned difference(Date *first,Date *second)
{
    if(first->isBC != second->isBC)
        return DateInDays(first)+DateInDays(second);
    else
        return max(DateInDays(first),DateInDays(second))-min(DateInDays(first),DateInDays(second));

}
bool Date::operator <(Date*second)
{
    if(!isBC)
    {
        if(second->isBC)
            return false;
        else
        {
            if(DateInDays(this)<DateInDays(second))
                return true;
            else
                return false;
        }
    }
    else
    {
        if(!second->isBC)
            return true;
        else
        {
            if(DateInDays(this)>DateInDays(second))
                return true;
            else
                return false;
        }
    }
}
bool Date::operator <=(Date *second)
{
    if(!isBC)
    {
        if(second->isBC)
            return false;
        else
        {
            if(DateInDays(this)<=DateInDays(second))
                return true;
            else
                return false;
        }
    }
    else
    {
        if(!second->isBC)
            return true;
        else
        {
            if(DateInDays(this)>=DateInDays(second))
                return true;
            else
                return false;
        }
    }
}

#endif // DATA_H

