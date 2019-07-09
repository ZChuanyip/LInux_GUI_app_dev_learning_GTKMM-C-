
//#include <gtkmm/button.h>
//#include <gtkmm/grid.h>
//#include <gtkmm/entry.h>
//#include <gtkmm/checkbutton.h>
//#include <gtkmm/window.h>
#include <gtkmm.h>

class Todo_application : public Gtk::Window
{
	public:
	 Todo_application(); //constructor
	 Gtk::TreeViewColumn* pColumn = Gtk::manage(new Gtk::TreeViewColumn);
	 virtual ~Todo_application(); //destructor

	 
	protected:
		
	 //Signal handlers:
	 void add_button_clicked();
	 void delete_button_clicked();
	 void quit_button_clicked();
	 void on_selection_changed();
	 
	 //Tree model columns:
	  class ModelColumns : public Gtk::TreeModel::ColumnRecord
	  {
	  public:

		ModelColumns()
		{ add(m_col_id); add(m_col_percentage); add(m_col_name);}

		Gtk::TreeModelColumn<unsigned int> m_col_id;
		Gtk::TreeModelColumn<int> m_col_percentage;
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
	  };

	  ModelColumns m_Columns;

	  int count;
	  bool any_row_selected = false;
	 
	 //Member widgets:
		////Entry
		Gtk::Entry new_task_entry;
		
		//buttons
		Gtk::Button add_button;
		Gtk::Button delete_button;
		Gtk::Button test_button;
		
		Gtk::CheckButton todo_check_button;
		
		////Grid
		Gtk::Grid button_grid;
		
	  //tree model and list store
	  Gtk::ScrolledWindow m_ScrolledWindow;
	  Gtk::TreeView m_TreeView;
	  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
	  Gtk::TreeModel::Row row;
	  Glib::RefPtr<Gtk::TreeSelection> m_refTreeSelection;
	  
	  std::string iconpath="app_icon.png";
};



