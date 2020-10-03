#include "include/makeclass.ih"

void makeclass::make_all()
{

    if (!std::filesystem::exists(class_name))
    {
      bool cpy = false;
      bool mv = false;
      std::filesystem::create_directory(class_name);
      std::string path = class_name + '/';
      make_class_constructor(path);
      std::cout << "\nAllow copy support? [y/N] ";
      std::string choice;
      std::getline(std::cin, choice);
      if (choice == "y")
      {
        cpy = true;
        make_copy_constructor(path);
        assignment_op(path);
      }

      std::cout << "\nAllow move support? [y/N] ";
      std::getline(std::cin, choice);
      if (choice == "y")
      {
        mv = true;
        make_move_constructor(path);
        move_assignment_op(path);
      }
      make_header(path, cpy, mv);
      make_iheader(path);
      make_destructor(path);
    }
}
