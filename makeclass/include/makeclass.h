#ifndef MAKECLASS_H_
#define MAKECLASS_H_

#include <string>

class makeclass
{
  std::string const class_name;
  std::string const _namespace;

public:
  makeclass(std::string const &class_name,
            std::string const &_namespace = "");

  void make_all();

  void make_header(std::string const &path, bool cpy, bool mv);
  void make_iheader(std::string const &path);
  void make_class_constructor(std::string const &path);
  void make_copy_constructor(std::string const &path);
  void make_move_constructor(std::string const &path);
  void make_destructor(std::string const &path);

  void assignment_op(std::string const &path);
  void move_assignment_op(std::string const &path);

  std::string to_uppercase(std::string str);
};

inline std::string makeclass::to_uppercase(std::string str)
{
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  return str;
}

#endif
