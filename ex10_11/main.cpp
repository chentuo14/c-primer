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

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> vec = {"fox", "jumps", "over", "quick", "red", "red"
                          "slow", "the", "the", "turtle"};
    stable_sort(vec.begin(), vec.end(), isShorter); //按长度重新排序
    elimDups(vec);
    return 0;
}
