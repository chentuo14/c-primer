#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    string word;
    map<string, size_t> word_count;
    while(cin>>word)
    {
        auto ret = word_count.insert({word, 1});
        if(!ret.second)
            ++ret.first->second;
    }

    for(const auto &w : word_count)
        cout<<w.first<<" "<<w.second<<" times"<<endl;

    return 0;
}
