#include <iostream>

using namespace std;

int main()
{
    string s1 = "String,This,Hello";
    string ret;

    for(auto c : s1)
    {
        if(!ispunct(c))
            ret += c;
    }
    cout << ret <<endl;


    return 0;
}
