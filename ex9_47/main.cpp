#include <iostream>

using namespace std;

int main()
{
    string str = "ab2c3d7R4E6";
    string num("1234567890");
    string notOf;
    string::size_type pos = 0;
    while((pos=str.find_first_of(num, pos))!=string::npos)
    {
        cout<<"found number at index: "<<pos
           <<" element is "<<str[pos]<<endl;
        ++pos;
    }

    cout<<endl;
    pos = 0;
    while((pos=str.find_first_not_of(num,pos))!=string::npos)
    {
        notOf.insert(notOf.end(), str[pos]);
        ++pos;
    }
    pos=0;
    while((pos=str.find_first_not_of(notOf, pos))!=string::npos)
    {
        cout<<"found number at index: "<<pos
           <<" element is "<<str[pos]<<endl;
        ++pos;
    }

    return 0;
}
