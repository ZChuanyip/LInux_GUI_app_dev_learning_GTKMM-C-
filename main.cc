#include "todo.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "hi");

  Todo_application todo_app;

  //Shows the window and returns when it is closed.
  return app->run(todo_app);
}
