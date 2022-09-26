#include "editor.h"
#include <iostream>
#include <memory>
#include <fmt/core.h>

#define UNUSED(variable) (void)variable

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    try
    {
        auto editor = Editor();
        editor.start();
        editor.open_file("Some unexpected path");
        editor.current_tab->add_figure(std::shared_ptr<Circle>());
        auto content = editor.current_tab->content;
        (content[0])->change();
        // println("content size: {}", std::to_string((int)(content.size())));
        // editor.current_tab->add_figure(std::shared_ptr<Square>());
        // // editor.current_tab->content[0]->change();
        // editor.current_tab->save("Another unexpected path");
        // editor.create_new_tab();
        // editor.current_tab->add_figure(std::shared_ptr<Rectangle>());
        // // editor.current_tab->content[0]->change();
        // editor.current_tab->add_figure(std::shared_ptr<Triangle>());
        // // editor.current_tab->content[0]->change();
        // editor.current_tab->remove_figure(editor.current_tab->content[0]);
        // editor.current_tab->save("Secret path");
        // editor.close_tab(editor.open_tabs[0]);
        // editor.close_tab(editor.open_tabs[0]);
        // editor.stop();

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
