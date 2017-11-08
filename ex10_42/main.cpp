#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;

void elimDups(list<string> &words)
{
    words.sort();

    words.unique();
}



int main()
{
    string word;
    list<string> ls;

    while(cin>>word)
        ls.push_back(word);
    elimDups(ls);

    for(auto iter=ls.begin();iter!=ls.end();iter++)
        cout<<*iter<<endl;

    return 0;
}
