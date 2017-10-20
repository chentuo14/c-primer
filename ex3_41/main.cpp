#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> v1(begin(a),end(a));

    for(int temp :v1)
        cout<<" "<<temp;

    return 0;
}
