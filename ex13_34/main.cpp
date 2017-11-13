#include <iostream>
#include <string>
#include <set>

using namespace std;

class Folder;

class Message {
    friend class Folder;
public:
    //folders被隐式初始化为空集合
    explicit Message(const std::string &str = ""):contents(str) { }
    //拷贝控制成员，用来管理指向本Message的指针
    Message(const Message &);                       //拷贝构造函数
    Message& operator=(const Message &);            //拷贝赋值运算符
    ~Message();                                     //析构函数
    //从给定Folder集合中添加/删除本Message
    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents;                           //实际消息文本
    std::set<Folder*> folders;                      //包含本Message的Folder
    //拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    //将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message &);
    //从folders中的每个Folder中删除本Message
    void remove_from_Folders();
};

class Folder {
public:
    Folder();
    ~Folder();
    Folder& operator =(const Folder &);
    Folder(const Folder &);

    void addMsg(Message *m3)
    {
        messages.insert(m3);
    }
    void remMsg(Message *m4)
    {
        messages.erase(m4);
    }

private:
    set<Message *> messages;
};

Message::Message(const Message &m):contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);              //将本消息添加到指向m的Folder中
}

Message &Message::operator=(const Message &rhs)
{
    //通过先删除指针再插入它们来处理自赋值情况
    remove_from_Folders();          //更新已有Folder
    contents = rhs.contents;        //从rhs拷贝消息内容
    folders = rhs.folders;          //从rhs拷贝Folder指针
    add_to_Folders(rhs);            //将本Message添加到那些Folder中
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f);             //将给定Folder添加到我们的Folder列表中
    f.addMsg(this);                 //将本Message添加到f的Message集合中
}

void Message::remove(Folder &f)
{
    folders.erase(&f);              //将给定Folder从我们的Folder列表中删除
    f.remMsg(this);                 //将本Message从f的Message集合中删除
}

void Message::add_to_Folders(const Message &m)
{
    for(auto f : m.folders)         //对每个包含m的Folder
        f->addMsg(this);            //向该Folder添加一个指向本Message的指针
}

void Message::remove_from_Folders()
{
    for(auto f :  folders)          //对folders中每个指针
        f->addMsg(this);            //从该Folder中删除本Message
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


