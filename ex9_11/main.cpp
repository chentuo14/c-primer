#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec1;                           //创建了一个int的vector
    vector<int> vec2{1,2,3};                    //创建了vec2并初始化为123
    vector<int> vec3(vec2);                     //创建了vec3并用vec2初始化（一样的）
    vector<int> vec4 = vec2;                    //vec4和vec2一样
    vector<int> vec5 = {3,2,1};                 //vec5创建了三个元素3,2,1
    vector<int> vec6(vec5.begin(), vec5.end());     //vec6从vec5开始到vec5结束，3,2,1


    return 0;
}
