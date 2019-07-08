//#ifdef TODO_H
//#define TODO_H


#include <gtkmm/button.h>
//#include <gtkmm/label.h>
//#include <gtkmm/entry.h>
//#include <gtkmm/checkbutton.h>
//#include <gtkmm/grid.h>
#include <gtkmm/window.h>

class Todo_application : public Gtk::Window
{
	public:
	 Todo_application(); //constructor
	 virtual ~Todo_application(); //destructor
	
	protected:
	 //Signal handlers:
	 void add_button_clicked();
	 //void delete_button_clicked();

	 //Member widgets:
		////Labels
		//Gtk::Label title;
		
		////Entry
		//Gtk::entry todo_entry;
		
		//buttons
		Gtk::Button add_button;
		//Gtk::Button delete_button;
		//Gtk::CheckButton todo_check_button;
		
		////Grid
		//Gtk::Grid grid;
		
	 

};

//#endif //todo_h

