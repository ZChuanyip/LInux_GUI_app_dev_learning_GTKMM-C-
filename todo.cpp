#include "todo.h"
#include <iostream>

using namespace std;

Todo::Todo()
: title("To-Do application"),
  //todo_entry("New to-do task"),
  //add_button("Add new task"),
  //delete_button("Delete task"),
  //todo_check_button("Existing task")
{
  // Sets the border width of the window.
  set_border_width(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
              
  add_button.signal_clicked().connect(sigc::mem_fun(*this, &todo::add_button_clicked));
  delete_button.signal_clicked().connect(sigc::mem_fun(*this, &todo::delete_button_clicked));
  
  // This packs the button into the Window (a container).
  add(title);
  add(todo_entry);
  add(add_button);
  add(delete_button);
  add(todo_check_button);

  // The final step is to display this newly created widget...
  title.show();
  todo_entry.show();
  add_button.show();
  delete_button.show();
  todo_check_button.show();
}

Todo::~Todo()
{
}

void Todo::add_button_clicked()
{
  std::cout << "I want to add task!!" << std::endl;
}

void Todo::delete_button_clicked()
{
  std::cout << "I want to delete task!!" << std::endl;
}
