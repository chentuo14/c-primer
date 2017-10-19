#include <iostream>

using namespace std;

int main()
{
    string s1 = "sjdsljdlasjda";
//    for(decltype(s1.size()) i=0;i<s1.size();i++)
//        s1[i] = 'X';
    decltype(s1.size()) i=0;
    while(i<s1.size())
    {
        s1[i] = 'X';
        i++;
    }
    cout << s1 << endl;
    return 0;
}
