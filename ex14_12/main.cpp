#include <iostream>

using namespace std;

class Date
{
public:
    Date() {}
    Date(int y, int m, int d) {year = y; month = m; day =d;}
    friend istream &operator >>(istream &is, Date &dt);
    friend ostream &operator <<(ostream &os, Date &dt);

private:
    int year;
    int month;
    int day;
};

istream &operator >>(istream &is, Date &dt)
{
    is>>dt.year>>dt.month>>dt.day;
    if(!is)
        dt = Date(0,0,0);
    return is;
}

ostream &operator <<(ostream &os, Date &dt)
{
    cout<<dt.year<<" "<<dt.month<<" "<<dt.day<<endl;
}

int main()
{
    Date dt;
    cin>>dt;
    cout<<dt;
    return 0;
}




