#include <iostream>

using namespace std;

#include "my_strblob.h"

int main()
{
    StrBlob b;
    string s;
    while(cin>>s)
        b.push_back(s);

    for(auto it= b.begin(); neq(it, b.end());it.incr())
        cout<<it.deref()<<endl;

    return 0;
}
