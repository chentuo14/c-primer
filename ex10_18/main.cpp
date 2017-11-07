#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string make_plural(size_t ctr,const string &word, const string &ending)
{
  return (ctr==1) ? word : word+ending;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}

void biggers(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    for_each(words.begin(), words.end(),
             [](const string &s){ cout<<s<<" "; });
    cout<<endl;

    auto wc = partition(words.begin(), words.end(),
                        [sz](const string &a) { return a.size() >= sz;});

    auto count = wc - words.begin();
    cout<<count<<" "<<make_plural(count, "word", "s")
       <<" of length "<<sz<<" or longer"<<endl;

    for_each(words.begin(), wc, [](const string &s) { cout<<s<<" "; });
    cout<<endl;
}

int main()
{
    vector<string> words;
    string word;
    while(cin>>word)
        words.push_back(word);

    biggers(words, 4);

    return 0;
}
