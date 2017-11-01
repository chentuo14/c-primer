#include <iostream>

using namespace std;

istream & function(istream &is)
{
    std::string s;
    while(is>>s)
        std::cout<<s<<" ";
    return is;
}

int main()
{
    function(cin);
    return 0;
}
