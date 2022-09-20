#pragma once

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>



class Figure {
    public:
    virtual void change();
};

class Square: public Figure {
    public:
    void change() override;
};

class Circle: public Figure {
    public:
    void change() override;
};

class Triangle: public Figure {
    public:
    void change() override;
};


class Tab {
    std::vector <Figure*> content;
    public:

    Tab();
    Tab(std::string path);
    void save(std::string path);
    void add_figure(Figure* figure);
    void remove_figure(Figure* figure);
};


class Editor {
    std::vector <Tab*> open_tabs = {};
    Tab* current_focus = nullptr;
    public:
    void open_file(std::string path);
    void create_new_tab();
    void change_focus_to(Tab* tab);
    void save_tab(Tab* tab, std::string path);
    void start();
    void stop();
};
