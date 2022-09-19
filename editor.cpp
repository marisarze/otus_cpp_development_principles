#include <iostream>
#include <vector>
#include "editor.h"
#include <fmt/core.h>
#include <algorithm>


void Square::change() {
    fmt::print("The SQUARE is changed");
};

void Circle::change() {
    fmt::print("The CIRCLE is changed");
};

void Triangle::change() {
    fmt::print("The TRIANGLE is changed");
};


Tab::Tab(){};

Tab::Tab(std::string path){};

void Tab::save(std::string path){};

void Tab::add_figure(Figure* figure){
        content.emplace_back(figure);
};

void Tab::remove_figure(Figure* figure){
    auto it = std::find(content.begin(), content.end(), figure);
    content.erase(it);
    delete *it;
};


void Editor::open_file(std::string path){
    auto new_tab = new Tab(path); 
    open_tabs.emplace_back(new_tab);
    change_focus_to(new_tab);
    fmt::print("New empty tab created with loading from {}", path);
};

void Editor::create_new_tab(){
    auto new_tab = new Tab();
    fmt::print("New empty tab created");
};

void Editor::change_focus_to(Tab* tab){
    current_focus = tab;
    fmt::print("Current focus changed to {}", tab);
};

void Editor::save_tab(Tab* tab, std::string path){
    tab->save(path);
    ;fmt::print("Tab {} was saved to file {}", tab, path);
}

void Editor::start(){
    fmt::print("Starting the engine");
};

void Editor::stop(){
    fmt::print("Preparing for stopping the engine...Stopped");
};
