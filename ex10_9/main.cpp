#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &word)
{
    vector<string>::iterator iter;
    iter = unique(word.begin(), word.end());
    word.erase(iter, word.end());

    for(auto it = word.begin();it!=word.end();++it)
        cout<<*it<<" ";
}

int main()
{
    vector<string> vec = {"fox", "jumps", "over", "quick", "red", "red"
                          "slow", "the", "the", "turtle"};
    elimDups(vec);
    return 0;
}
