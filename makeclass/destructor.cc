#include "include/makeclass.ih"

void makeclass::make_destructor(std::string const &path)
{
    std::string file_name = path + "destructor.cc";

    std::string destructor = R"(
    #include "%1%.ih"

    %1%::~%1%()
    // destructor
    {

    }
    )";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << boost::format(destructor) % class_name;
    }
}