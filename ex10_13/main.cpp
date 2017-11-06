#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void outputWords(vector<string>::iterator beg, vector<string>::iterator end)
{
    for(auto iter = beg;iter != end; iter++)
        cout<<*iter<<" ";
    cout<<endl;
}

bool fiveOrMore(string &s)
{
    return s.length() >= 5;
}

int main()
{
    vector<string> words;
    string word;
    while(cin>>word)
        words.push_back(word);

    outputWords(words.begin(),words.end());

    auto iter = partition(words.begin(), words.end(), fiveOrMore);
    outputWords(words.begin(), iter);


    return 0;
}
