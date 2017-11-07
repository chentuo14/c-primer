#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;

    vector<int> vi;

    while (in_iter!=eof)
        vi.push_back(*in_iter++);

    sort(vi.begin(),vi.end(), [](int a, int b) {return a>b;});

    ostream_iterator<int> out(cout, " ");
    copy(vi.begin(), vi.end(), out);

    return 0;
}
