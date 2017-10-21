#ifndef EX7_2_H
#define EX7_2_H

#include <string>

struct Sales_data {
    Sales_data();
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data &rhs);
    std::string bookNo;
    unsigned uints_sold;
    double revenue;         //类内部变量成员不允许在定义时初始化，必须使用构造函数
};

Sales_data::Sales_data()
{
    uints_sold = 0;
    revenue = 0.0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    uints_sold += rhs.uints_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif // EX7_2_H
