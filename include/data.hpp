
#ifndef DATA
#define DTDA

class Data
{
public:
    Data(int year=0,int month=1,int day=1);
    void Print() const;
    Data& operator+=(int day);
    Data& operator-=(int day);
    Data operator+(int day) const;
    Data operator-(int day) const;
    Data& operator++();
    Data operator++(int);
    Data& operator--();
    Data operator--(int);

    bool operator>(const Data& d) const;
    bool operator>=(const Data& d) const;
    bool operator<(const Data& d) const;
    bool operator<=(const Data& d) const;
    bool operator==(const Data& d) const;
    bool operator!=(const Data& d) const;

    int operator-(const Data& d) const;
private:
    int _year;
    int _month;
    int _day;
};

#endif