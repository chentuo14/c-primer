#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class date {
public:
    date() = default;
    date(string &ds);

    unsigned y() const { return year; }
    unsigned m() const { return month; }
    unsigned d() const { return day; }

private:
    unsigned int year, month, day;
};

const string month_name[] = {"January", "February", "March",
                            "April", "May", "June", "July", "Auguest", "September",
                            "October", "November", "December"};
const string month_abbr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                             "Aug", "Sep", "Oct", "Nov", "Dec"};
const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#endif // DATA_H
