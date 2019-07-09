#include "todo.h"
#include <iostream>

Todo_application::Todo_application()
{
  int w, h;
  // initial window.
  this->set_title("To-Do application");
  this->set_border_width(10);
  this->set_default_size (480, 480);
  this->set_resizable(false);
  this->get_size(w, h);
  this->set_icon_from_file(iconpath);
  //set buttons label
  add_button.add_label("Add new task");
  delete_button.add_label("Delete task");
  delete_button.set_sensitive(false);
  
  //set entry label
  new_task_entry.set_placeholder_text("New task");
  new_task_entry.set_max_length(100);
  // Button onclick handlers
  add_button.signal_clicked().connect(sigc::mem_fun(*this, &Todo_application::add_button_clicked));
  delete_button.signal_clicked().connect(sigc::mem_fun(*this, &Todo_application::delete_button_clicked));
    
  // Add widgets into the grid. **attach(widget/UI element,col, row, width ratio, height ratio)
  button_grid.attach(new_task_entry,0,0,2,1);
  button_grid.attach(add_button, 0,1,1,1);
  button_grid.attach(delete_button,1,1,1,1);
 // button_grid.attach(test_button,0,1,1,1);
 
  
  //set_size
  add_button.set_size_request((w-20)/2, 20);
  delete_button.set_size_request((w-20)/2, 20);
  new_task_entry.set_size_request(w-20,20);
  
  
  //Create the Tree model:
   m_refTreeModel = Gtk::ListStore::create(m_Columns);

   m_TreeView.set_model(m_refTreeModel);


  //Fill the TreeView's model
  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 1;
  row[m_Columns.m_col_name] = "Demo task1";

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 2;
  row[m_Columns.m_col_name] = "Demo task2";

  //row = *(m_refTreeModel->append());
  //row[m_Columns.m_col_id] = 3;
  //row[m_Columns.m_col_name] = "Do other laboratory Works";

    //set selection listener on list
    m_refTreeSelection = m_TreeView.get_selection();
    m_refTreeSelection->signal_changed().connect( sigc::mem_fun(*this, &Todo_application::on_selection_changed));
  //set counter for rows default by 2
  count = 2;
  //Add the TreeView's view columns:
  //This number will be shown with the default numeric formatting.
  m_TreeView.append_column("ID", m_Columns.m_col_id);
  m_TreeView.append_column("Task Description", m_Columns.m_col_name);
  show_all_children();
  button_grid.attach(m_TreeView, 0,2,2,5);
  //display button and add grid to window
  button_grid.show_all();
  add(button_grid);
}

Todo_application::~Todo_application()
{
}

void Todo_application::add_button_clicked()
{
  count++;

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = count;
  row[m_Columns.m_col_name] = new_task_entry.get_text();
  new_task_entry.set_text("");
  std::cout << "I want to add "+ new_task_entry.get_text()  << std::endl;
}

void Todo_application::delete_button_clicked()
{
  Gtk::TreeModel::iterator store_iter = m_refTreeSelection->get_selected();
  m_refTreeModel->erase(store_iter);
  std::cout << "I want to delete this task :D" << std::endl;
}

void Todo_application::on_selection_changed()
{
	delete_button.set_sensitive(true);

    Gtk::TreeModel::iterator iter = m_refTreeSelection->get_selected();
    Gtk::TreeModel::Row row = *iter;
    std::cout << "Slelected task!!" << std::endl;
}

