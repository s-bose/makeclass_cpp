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
            break;
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
    std::cout << "usage: " << program_name << " class" << "[namespace]" ;
}
