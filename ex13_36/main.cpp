#include <iostream>
#include <set>

using namespace std;

class Folder {
public:
    Folder();
    ~Folder();
    Folder& operator =(const Folder&);
    Folder(const Folder&);

    void addMsg(Message *m) { msg.insert(m); }
    void remMsg(Message *m) { msg.erase(m); }
private:
    set<Message *> messages;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
