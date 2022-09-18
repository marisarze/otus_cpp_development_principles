#include <iostream>
#include <vector>
#include "editor.h"
#include <fmt/core.h>


class Figure {
    public:
    std::string name="AbStRaCt_FiGuRe";
};

class Square: public Figure {
    public:
    std::string name="SqUaRe_FiGuRe";
};

class Circle: public Figure {
    public:
    std::string name="CiRcLe_FiGuRe";
};

class Triangle: public Figure {
    public:
    std::string name="TrIaNgLe_FiGuRe";
};


class Tab {
    std::vector <Figure*> content;
    public:

    Tab(){};
    Tab(std::string path){}

    void save(std::string path){
        
    }

    void add_figure(Figure* figure){
        content.emplace_back(figure);
        fmt::print("Figure {} was added to tab {}", figure->name, this);
    }

    void remove_figure(Figure* figure){
        auto it = std::find(content.begin(), content.end(), figure);
        content.erase(it);
        delete *it;
        fmt::print("Figure {} was removed from Tab {}", figure->name, this);
    }
}


class Editor {
    std::vector <Tab*> open_tabs = {};
    Tab* current_focus = nullptr;
    public:
    void open_file(std::string path){
        auto new_tab = new Tab(path); 
        open_tabs.emplace_back(new_tab);
        change_focus_to(new_tab);
        fmt::print("New empty tab created with loading from {}", path);
    }

    void create_new_tab(){
        auto new_tab = new Tab();
        fmt::print("New empty tab created");
    }

    void change_focus_to(Tab* tab){
        current_focus = tab;
        fmt::print("Current focus changed to {}", tab);
    }

    void save_tab(Tab* tab, std::string path){
        tab->save(path);
        fmt::print("Tab {} was saved to file {}", tab, path);
    }

    void start(){
        fmt::print("Starting the engine.");
    }

    void close(){
        fmt::print("Preparing for closing the engine...Closed.");
    }












}