#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <vector>

class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};


class Screen {
    friend void Window_mgr::clear(ScreenIndex i);
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {} // 2
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
    {
    } // 3

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }
    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }

    void do_display(std::ostream& os) const { os << contents; }
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

void Window_mgr::clear(ScreenIndex i)
{
    if(i>=screens.size()) return;
    Screen& s = screens[i];
    s.contents = std::string(s.height*s.width, ' ');
}


inline Screen& Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

#endif // FRIEND_H
