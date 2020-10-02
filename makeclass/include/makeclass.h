#ifndef MAKECLASS_H_
#define MAKECLASS_H_

#include <string>

class makeclass
{
        std::string const class_name;
        std::string const _namespace;

        bool copy_constructor, move_constructor;

    public:
        makeclass(std::string const &class_name);
        makeclass(std::string const &class_name, std::string const &_namespace, bool cpy_construct, bool mv_construct);
        
        void make_all();
        void make_header(std::string const &path);
        // void make_iheader();
        
        void make_class_constructor(std::string const &path);
        void make_copy_constructor(std::string const &path);
        void make_move_constructor(std::string const &path);
        void make_destructor(std::string const &path);

        // void make_copy_assignment();
        // void make_move_assignment();



};


#endif