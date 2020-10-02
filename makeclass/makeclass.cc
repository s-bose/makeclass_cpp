#include "include/makeclass.ih"

makeclass::makeclass(std::string const &classname)
    : class_name(classname)
    , copy_constructor(false)
    , move_constructor(false)

{
    /*
        only class name passed, default construction
        1 header file
        1 internal header file
        1 source file (default constructor)
    */
}

makeclass::makeclass(std::string const &classname, std::string const &_namespace, bool cpy_construct, bool mv_construct)
    : class_name(classname)
    , _namespace(_namespace)
    , copy_constructor(cpy_construct)
    , move_constructor(mv_construct)
{}

void makeclass::make_all()
{
    
    if (!std::filesystem::exists(class_name))
    {
        std::filesystem::create_directory(class_name);
        std::string path = class_name + '/';
        make_header(path);
        make_class_constructor(path);
        make_copy_constructor(path);
        make_move_constructor(path);
        make_destructor(path);
    }
}