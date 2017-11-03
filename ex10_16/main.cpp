#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr==1)?word:word+ending;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    //按长度排序
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                    {return a.size()<b.size();});
    //获取一个迭代器，指向第一个满足size()>=sz的元素
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a)
                        { return a.size()>=sz; });
    //计算满足size>=sz的元素的数目
    auto count = words.end() - wc;
    cout<<count<<" "<<make_plural(count, "word", "s")
       <<" of length "<<sz<<" or longer"<<endl;
    //打印长度大于等于给定值得单词，每个单词后面接一个空格
    for_each(wc, words.end(),
             [](const string &s) { cout<<s<<" ";});
    cout<<endl;
}

int main()
{
    vector<string> vec = {"fox", "jumps", "over", "quick", "red", "red"
                          "slow", "the", "the", "turtle"};
    biggies(vec, 4);
    return 0;
}
