#include <iostream>
#include <vector>

using namespace std;

int func(vector<string> &vi)
{
    int count=0;
    for(auto iter = vi.begin();iter!=vi.end();++iter)
    {
        if((*iter).size()<=6)
            count++;
    }
    return count;
}

int main()
{
    vector<string> vec = {"fox", "jumps", "over", "quick", "red", "red",
                          "slow", "the", "the", "turtle"};

    cout<<"num is "<<func(vec)<<endl;
    return 0;
}
