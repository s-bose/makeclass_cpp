#include "include/makeclass.ih"

makeclass::makeclass(std::string const &classname, std::string const &_namespace)
    : class_name(classname)
    , _namespace(_namespace)
{}

// ! CONSTRUCTOR SKELETON BUILDER

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


// ! DESTRUCTOR SKELETON BUILDER

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

// ! HEADER SKELETON BUILDER

void makeclass::make_header(std::string const &path, bool cpy, bool mv)
{
    std::string file_name = path + class_name + ".h";

    std::string additional_methods;

    std::string class_def = R"(
    class %1%
    {
        public:
        %1%();
        %2%

        private:

    };
    )";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);

        file_writer << boost::format("#ifndef %1%_H_\n#define %1%_H_\n") % to_uppercase(class_name);

        if (_namespace != "")
        {
            file_writer << "\nnamespace " << _namespace << "\n{\n";
        }


        if (cpy)
        {
          additional_methods += "%1%(%1% const &other);\n";
          additional_methods += "\t\t%1% &operator=(%1% const &other);\n";
        }
        if (mv)
        {
          additional_methods += "\t\t%1%(%1% const &&tmp);\n";
          additional_methods += "\t\t%1% &operator=(%1% const &&tmp);\n";
        }

    
        if (additional_methods != "")
            additional_methods = str(boost::format(additional_methods) % class_name);

        file_writer << boost::format(class_def)
            % class_name
            % additional_methods;

        file_writer << ((_namespace == "") ? "\n#endif\n" : "\n}\n#endif\n");
    }
}

// ! INTERNAL HEADER SKELETON BUILDER

void makeclass::make_iheader(std::string const &path)
{
    std::string file_name = path + class_name + ".ih";
    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);

        file_writer << "#include " << class_name << ".h\n";

        if (_namespace != "")
            file_writer << "using namespace " << _namespace << ";\n";
    }
}

// ! ASSIGNMENT OPERATORS

void makeclass::assignment_op(std::string const &path)
{
    std::string file_name = path + "operator1.cc";

    std::string assignment_op = R"(
    #include "%1%.ih"

    %1% &%1%::operator=(%1% const &other)
    // assignment op
    {

    }
    )";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << boost::format(assignment_op) % class_name;
    }
}

void makeclass::move_assignment_op(std::string const &path)
{
    std::string file_name = path + "operator2.cc";

    std::string mv_assignment_op = R"(
    #include "%1%.ih"

    %1% &%1%::operator=(%1% const &&tmp)
    // move assignment op
    {

    }
    )";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << boost::format(mv_assignment_op) % class_name;
    }
}

// !
