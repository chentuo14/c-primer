#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s1;
    vector<string> arryStr;
    unsigned int i = 0;

    while(cin>>s1 && i<10)              //输入10次
    {
        arryStr.push_back(s1);
        i++;
    }

    for(unsigned int i=0;i<arryStr.size();i++)      //提升为大写
    {
        for(int j=0;j<arryStr[i].length();j++)
        {
            arryStr[i][j] = toupper(arryStr[i][j]);
        }
    }

    for(int i = 0;i<arryStr.size();i++)         //输出
    {
        cout<<arryStr[i]<<endl;
    }

    return 0;
}
