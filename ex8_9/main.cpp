#include <iostream>
#include <sstream>

using namespace std;

istream & function(istream &is)
{
    std::string s;
    while(is>>s)
        std::cout<<s<<" ";
    return is;
}

void function1(const string &string)
{
    istringstream record(string);
    std::string buf;
    while(record>>buf) std::cout<<buf<<" ";
    return;
}

int main()
{
    std::istringstream iss("hello");
    function(iss);
    function1("ssssss");
    return 0;
}
