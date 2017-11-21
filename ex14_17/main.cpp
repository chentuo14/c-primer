#include <iostream>

using namespace std;

class Date
{
    friend bool operator ==(const Date &d1, const Date &d2);
    friend bool operator !=(const Date &d1, const Date &d2);
};

bool operator ==(const Date &d1, const Date &d2)
{
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator !=(const Date &d1, const Date &d2)
{
    return !(d1 == d2);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
