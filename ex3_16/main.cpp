#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;                     //1个，空
    vector<int> v2(10);                 //10,空
    vector<int> v3(10, 42);             //10, 都是42
    vector<int> v4{10};                 //1个，10
    vector<int> v5{10, 42};             //2个，10、42
    vector<string> v6{10};              //1个，10
    vector<string> v7{10, "hi"};        //2个，10、hi

    for(auto i : v1)
        cout << i << " ";
    cout<<endl;
    for(auto i : v2)
        cout << i << " ";
    cout<<endl;
    for(auto i : v3)
        cout << i << " ";
    cout<<endl;
    for(auto i : v4)
        cout << i << " ";
    cout<<endl;
    for(auto i : v5)
        cout << i << " ";
    cout<<endl;
    for(auto i : v6)
        cout << i << " ";
    cout<<endl;
    for(auto i : v7)
        cout << i << " ";
    cout<<endl;

    return 0;
}
