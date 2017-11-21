#include <iostream>

using namespace std;

class StrBlob
{
    friend bool operator ==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator !=(const StrBlob &lhs, const StrBlob &rhs);
};

bool operator ==(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data == rhs.data;
}

bool operator !=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs==rhs);
}

class StrBlobPtr
{
    friend bool operator ==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator !=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
};

bool operator ==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

bool operator !=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

class StrVec
{
    friend bool operator ==(const String &lhs, const String &rhs);
    friend bool operator !=(const String &lhs, const String &rhs);
private:
    const char *str;
};

bool operator ==(const String &lhs, const String &rhs)
{
    return strcmp(lhs.str,rhs.str);
}

bool operator !=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
