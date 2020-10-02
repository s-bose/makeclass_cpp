#include "include/makeclass.ih"

int main(int argc, char **argv)
{
    std::string class_name = argv[1];
    makeclass maker = makeclass(class_name, "my_namespace", true, true);
    maker.make_all();
}