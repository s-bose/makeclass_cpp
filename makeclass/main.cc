#include "include/makeclass.ih"

int main(int argc, char **argv)
{
    std::string class_name = argv[1];
    std::string namespace_name = argv[2];
    makeclass maker = makeclass(class_name, namespace_name);
    maker.make_all();
}
