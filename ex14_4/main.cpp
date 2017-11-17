#include <iostream>

using namespace std;

class Date {
    Date() { }
    Date(int y,int m, int d) { year = y; month = m; day = d;}
    friend std::ostream & operator <<(std::ostream &os,const Date &dt);

private:
    int year;
    int month;
    int day;
};

ostream &Date::operator <<(ostream &os, const Date &dt)
{
    const char sep = '\t';
    os<<"year:"<<dt.year<<sep<<"month:"<<dt.month<<sep<<"day:"<<dt.day<<endl;
    return os;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

