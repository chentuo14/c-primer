#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string &trans(string &s)
{
    for(int p =0;p<s.size();p++) {
        if(s[p] >='A' && s[p] <='Z')
            s[p]=s[p]-('A'-'a');
        else if(s[p] == ',' || s[p] == '.')
            s.erase(p,1);
    }
    return s;
}

int main()
{
    vector<string> unique_word;
    string word;
    while(cin>>word) {
        trans(word);
        if(find(unique_word.begin(), unique_word.end(), word) == unique_word.end())
            unique_word.push_back(word);
    }

    for(auto w : unique_word)
        cout<<w<<" ";
    cout<<endl;

    return 0;
}
