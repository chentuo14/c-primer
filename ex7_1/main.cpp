#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Sales_data {
    Sales_data();
    string bookNo;
    unsigned uints_sold;
    double revenue;         //类内部变量成员不允许在定义时初始化，必须使用构造函数
};

Sales_data::Sales_data()
{
    uints_sold = 0;
    revenue = 0.0;
}

int main()
{
    Sales_data total;       //此部分和第一章21页的内容相同
    if(std::cin >> total.bookNo >> total.uints_sold >> total.revenue) {
        Sales_data trans;
        while(std::cin >> trans.bookNo >> trans.uints_sold >> trans.revenue) {
            if(total.bookNo == trans.bookNo) {
                total.uints_sold += trans.uints_sold;
                total.revenue += trans.revenue;
            }
            else {
                cout<<total.bookNo<<" "<<total.uints_sold<<" "<<total.revenue<<endl;
                total = trans;
            }
        }
        cout<<total.bookNo<<" "<<total.uints_sold<<" "<<total.revenue<<endl;
    }
    else {
        cerr<<"No data?!"<<endl;
        return -1;
    }
    return 0;
}
