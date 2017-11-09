#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <vector>
#include <memory>

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> i1) : data(std::make_shared<std::vector<std::string>>(i1)) { }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //添加和删除元素
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    //元素访问
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string &StrBlob::front()
{
    //如果vector为空，check会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const
{
    if(i >= data->size())
        throw out_of_range(msg);
}


#endif // STRBLOB_H

