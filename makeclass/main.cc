#include "include/makeclass.ih"

void usage(std::string &&program_name);

int main(int argc, char **argv)
{
    std::string class_name, namespace_name;
    switch(argc)
    {
        case 1:
        default:
            usage(std::string(argv[0]));
            return 1;
        case 2:
            class_name = argv[1];
            break;
        case 3:
            class_name = argv[1];
            namespace_name = argv[2];
            break;
    }
    makeclass maker = makeclass(class_name, namespace_name);
    maker.make_all();
}

void usage(std::string &&program_name)
{
    std::cout << "usage: " << program_name << " class" << " [namespace]\n";
    std::cout << R"(
    class       : name of the class
    namespace   : (optional) custom namespace for the class

    generates a list of files for the given class name.
    these files are:
    1. class.h          // main header file
    2. class.ih         // internal header file
    3. class1.cc        // default constructor file
    4. desctructor.cc   // destructor file

    additionally, if copy and move supports are specified:
    5. class2.cc        // copy constructor file
    6. class3.cc        // move constructor file
    7. operator1.cc     // assignment operator file (for copy)
    8. operator2.cc     // assignment operator file (for move)
    )" << '\n';

}
