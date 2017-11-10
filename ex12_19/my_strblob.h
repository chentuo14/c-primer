#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
    friend bool eq(const StrBlobPtr&lhs, const StrBlobPtr&rhs);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    string& deref() const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();
private:
    shared_ptr<std::vector<std::string>> check(size_t i, const string&msg) const;

    weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

inline StrBlob::StrBlob():data(make_shared<std::vector<std::string>>()) { }

StrBlob::StrBlob(initializer_list<string> il):data(make_shared<std::vector<std::string>>(il)) { }

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

inline string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

void StrBlob::check(StrBlob::size_type i, const string &msg) const
{
    if(i>=data->size())
        throw out_of_range(msg);
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

inline string &StrBlobPtr::deref() const
{
    auto p = check(0, "dereference past end");
    return (*p)[curr];
}

inline StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::decr()
{
    --curr;
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

inline
shared_ptr<std::vector<string> > StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i>=ret->size())
        throw out_of_range(msg);
    return ret;
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

#endif // MY_STRBLOB_H




