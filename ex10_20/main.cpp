#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec = {"fox", "jumps", "over", "quick", "red", "red",
                          "slow", "the", "the", "turtle"};
    int mycount = count_if(vec.begin(), vec.end(),[](const string a)->bool
                            {if(a.size()>6) return true; else return false;});
    cout<<"string count is "<<mycount<<endl;
    return 0;
}
