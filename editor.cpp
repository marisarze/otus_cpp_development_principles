/**
 * @file editor.cpp
 * @author marisarze (you@domain.com)
 * @brief 
 * @version MY_PROJECT_VERSION
 * @date BUILD_DATE
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include "editor.h"
#include <fmt/core.h>
#include <fmt/format.h>
#include <algorithm>
#include <memory>
#include <cstdio>


#define UNUSED(variable) (void)variable


/**
 * @brief Utility function for printing messages using <fmt> library plus new line character.
 * Usage: println("Some sentence for formatting {}", "XXX") results to "Some sentence for formatting XXX"
 *  
 * @tparam Args types of parameters for formatting target message
 * @param format target message for printing
 * @param args formatting variables
 */
template <typename... Args>
void println(std::string format, const Args&... args) {
  fmt::print(format, args...);
  std::putc('\n', stdout);
}

/**
 * @brief implementation of the method for changing the graphic primitive "Square"
 * 
 */
void Square::change() {
    println("SQUARE is changed");
}

/**
 * @brief implementation of the method for changing the graphic primitive "Circle"
 * 
 */
void Circle::change() {
    println("CIRCLE is changed");
}

/**
 * @brief implementation of the method for changing the graphic primitive "Triangle"
 * 
 */
void Triangle::change() {
    println("TRIANGLE is changed");
}

/**
 * @brief implementation of the method for changing the graphic primitive "Rectangle"
 * 
 */
void Rectangle::change() {
    println("RECTANGLE is changed");
}

/**
 * @brief Construct a new Tab:: Tab object
 * 
 */
Tab::Tab(){}


/**
 * @brief Construct a new Tab:: Tab object from path
 * 
 * @param path path for loading tab (new document)
 */
Tab::Tab(std::string path){
    UNUSED(path);
}

/**
 * @brief saving Tab to document 
 * 
 * @param path path for saving the tab
 */
void Tab::save(std::string path){
    println("Tab saved to \'{}\'", path);
}

/**
 * @brief Method for adding figure to tab content
 * 
 * @param figure target figure for adding
 */
void Tab::add_figure(std::shared_ptr<Figure> figure){
    content.emplace_back(figure);
    println("New figure {} was added to tab {}", fmt::ptr(figure), fmt::ptr(this));
}

/**
 * @brief Method for removing figure from tab content, if figure is not in content prints
 *  corresponding message about nothing to remove.
 * 
 * @param figure target figure for remove
 */
void Tab::remove_figure(std::shared_ptr<Figure> figure){
    auto it = std::find(content.begin(), content.end(), figure);
    if (it != content.end()){
        content.erase(it);
        println("Figure {} erased from tab {}", fmt::ptr(figure.get()), fmt::ptr(this));
    } else {
        println("There is nothing to remove from tab {}", fmt::ptr(this));
    }
}

/**
 * @brief Construct a new Editor:: Editor object
 * 
 */
Editor::Editor(){
    println("Editor created");
}

/**
 * @brief loading new document to open tabs
 * 
 * @param path path for loading new tab
 */
void Editor::open_file(std::string path){
    auto new_tab = std::make_shared<Tab>(path); 
    open_tabs.emplace_back(new_tab);
    println("New empty tab {} created with loading from \'{}\'", fmt::ptr(new_tab.get()), path);
    change_focus_to(new_tab);
}

/**
 * @brief creating new empty tab
 * 
 */
void Editor::create_new_tab(){
    auto new_tab = std::make_shared<Tab>(); 
    open_tabs.emplace_back(new_tab);
    println("New empty tab {} created", fmt::ptr(new_tab.get()));
    change_focus_to(new_tab);
}

/**
 * @brief closing tab (removing it from open tabs). 
 * If the tab does not exist among the open ones, then displays the appropriate message.
 *  
 * @param tab target tab for closing
 */
void Editor::close_tab(std::shared_ptr<Tab> tab){
    auto it = std::find(open_tabs.begin(), open_tabs.end(), tab);
    if (it != open_tabs.end()){
        open_tabs.erase(it);
        println("Tab {} erased from the editor", fmt::ptr(tab.get()));
        if ((int)open_tabs.size()>0){
            change_focus_to(open_tabs[0]);
        } else {
            current_tab = nullptr;
        }
    } else {
        println("Target tab {} is not exist among open tabs", fmt::ptr(tab.get()));
    }
}

/**
 * @brief changing focus to target tab through setting "current_tab" parameter value.
 * if tab is not among open tabs, then corresponging warning will be prompt.
 * @param tab Target tab to shift focus.
 */
void Editor::change_focus_to(std::shared_ptr<Tab> tab){
    auto it = std::find(open_tabs.begin(), open_tabs.end(), tab);
    if (it != open_tabs.end()){
        current_tab = tab;
        println("Current focus changed to {}", fmt::ptr(tab.get()));
    } else {
        println("The focus can not be changed to {}", fmt::ptr(tab.get()));
    }
}

/**
 * @brief Starting of abstract editor
 * 
 */
void Editor::start(){
    println("Starting the engine");
}

/**
 * @brief Storpping of abstract editor
 * 
 */
void Editor::stop(){
    println("Preparing for stopping the engine...Stopped");
}
