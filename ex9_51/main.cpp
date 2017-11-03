#include <iostream>
#include <vector>

using namespace std;

class MyDate {
public:
    MyDate(std::string strDate);
    void show() {std::cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;}
    unsigned int year,month,day;
};

MyDate::MyDate(string strDate)
{
    string number = "0123456789";
    vector<string> vecMonth = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                               "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string coma = ",";
    string::size_type pos = 0;
    string::size_type posDay = 0;
    int flag = 0;
    string strMonth;
    int i=1;

    if((pos = strDate.find_first_not_of(number)) == string::npos)
    {
        flag = 1;
    }
    if((pos = strDate.find_first_of(coma)) != string::npos)
    {
        flag = 2;
    }

    switch(flag)
    {
    case 0:     //处理Jan 1 1900
        pos = strDate.find_first_of(number);

        for(auto iter=vecMonth.begin();iter!=vecMonth.end();++iter,++i)
        {
            if(*iter==strDate.substr(0, pos-1))
                month = i;
        }
        posDay = strDate.find_first_of(number,pos);
        day = stoi(strDate.substr(pos, posDay));
        year = stoi(strDate.substr(posDay, strDate.size()));


        break;
    case 1:     //处理1/1/1990
        break;
    case 2:     //处理January 1,1900
        break;
    default:
        break;
    }
}

int main()
{
    MyDate mdate("Jan 1 1900");
    mdate.show();
    return 0;
}


