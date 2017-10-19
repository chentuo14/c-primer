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

    return 0;
}
