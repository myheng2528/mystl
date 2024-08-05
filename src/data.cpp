
#include <iostream>
#include "data.hpp"

using namespace std;
inline int GetMonthDay(int year,int month){
    static int dayArray[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int day = dayArray[month];
    if(month==2&&((year%4==0&&year%100!=0)||year%400==0)){
        day=29;
    }

    return day;
}


Data::Data(int year, int month, int day){
    if (year>0&&month>0&&month<=12&&day>0&&day<=GetMonthDay(year,month))
    {
    _year = year;
    _month = month;
    _day = day;
    }else{
        cout<<"非法日期"<<endl;
        cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl; 
    }

}

void Data::Print() const{
    cout<<_year<<"年"<<_month<<"月"<<_day<<"日"<<endl; 
}

Data& Data::operator+=(int day){
    if(day<0){
        *this -= -day;
    }
    else{
        _day += day;
        while (_day>GetMonthDay(_year,_month))
        {   
            _day -= GetMonthDay(_year,_month);
            _month++;
            if (_month>12)
            {
                _year++;
                _month=1;
            }
        }
    }
    return *this;
}

Data& Data::operator-=(int day){
    if(day<0){
        *this += -day;
    }
    else{
        _day -= day;
        while (_day<1)
        {   
            _month--;
            _day += GetMonthDay(_year,_month);
            if (_month<1)
            {
                _year--;
                _month=12;
            }
        }
    }
    return *this;
}
Data Data::operator+(int day) const{
    Data temp(*this);
    temp+=day;
    return temp;
}
Data Data::operator-(int day) const{
    Data temp(*this);
    temp-=day;
    return temp;
}
Data& Data::operator++(){
    *this+=1;
    return *this;
}
Data Data::operator++(int){
    Data temp(*this);
    *this+=1;
    return temp;
}
Data& Data::operator--(){
    *this-=1;
    return *this;
}
Data Data::operator--(int){
    Data temp(*this);
    *this -= 1;
    return temp;
}

bool Data::operator>(const Data& d) const{
    if (_year>d._year)
    {
        return true;
    }else if(_year==d._year){
        if (_month>d._month)
        {
            return true;
        }else if (_month==d._month)
        {   if(_day>d._day){
                return true;
            }
        }
    }
    return false;
    
}
bool Data::operator>=(const Data& d) const{
    return *this>d||*this==d;
}
bool Data::operator<(const Data& d) const{
    return d>*this;
}
bool Data::operator<=(const Data& d) const{
    return d>=*this;
}
bool Data::operator==(const Data& d) const{
    if(_year==d._year&&_month==d._month&&_day==d._day){
        return true;
    }else{
        return false;
    }
}
bool Data::operator!=(const Data& d) const{
    return !(*this==d);
}

int Data::operator-(const Data& d) const{
    Data max = *this;
    Data min = d;
    int flag = 1;
    if (*this<d)
    {
        max = d;
        min = *this;
        flag = -1;
    }
    int count=0;
    while (max!=min)
    {
        min++;
        count++;
    }
    return flag*count;
    
}