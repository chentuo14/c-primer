#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int sum=0;
    double doubSum=0.0;
    for(auto num=vec.begin();num!=vec.end();++num)
    {
        sum+=stoi(*num);
        doubSum+=stod(*num);
    }

    cout<<"sum:"<<sum<<endl;
    cout<<"Double sum:"<<doubSum<<endl;

    return 0;
}
