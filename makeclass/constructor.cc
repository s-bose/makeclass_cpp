#include "include/makeclass.ih"

void makeclass::make_class_constructor(std::string const &path)
{
    /*
        default constructor builder
    */
    std::string file_name = path + class_name + "1.cc";

    std::string default_constructor = R"(
    #include "%1%.ih"

    %1%::%1%()
    // default constructor
    {

    }
    )";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer; 
        file_writer.open(file_name);
        file_writer << boost::format(default_constructor) % class_name;
    }
}

void makeclass::make_copy_constructor(std::string const &path)
{
    /*
        copy constructor builder
    */

   std::string file_name = path + class_name + "2.cc";

   std::string copy_constructor = R"(
    #include "%1%.ih"

    %1%::%1%(%1% const &other)
    // copy constructor
    {

    }
   )";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << boost::format(copy_constructor) % class_name;
    }
}

void makeclass::make_move_constructor(std::string const &path)
{
    /*
        move constructor builder
    */
   std::string file_name = path + class_name + "3.cc";

    std::string move_constructor = R"(
    #include "%1%.ih"

    %1%::%1%(%1% const &&tmp)
    // move constructor
    {

    }
    )";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << boost::format(move_constructor) % class_name;
    }
}








