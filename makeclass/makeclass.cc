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

    // std::string default_constructor = R"(
    // #include "%1%.ih"

    // %1%::%1%()
    // // default constructor
    // {

    // }
    // )";

    // std::ostringstream default_constructor;
    // default_constructor << "#include " << class_name << ".ih\n\n";
    // default_constructor << class_name << "::" << class_name << "()\n";
    // default_constructor << "{\n}\n";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << "#include \"" << class_name << ".ih\"\n\n";
        file_writer << class_name << "::" << class_name << "()\n";
        file_writer << "{\n}\n";
        // file_writer << default_constructor.str();
        file_writer.close();
    }
}

void makeclass::make_copy_constructor(std::string const &path)
{
    /*
        copy constructor builder
    */

   std::string file_name = path + class_name + "2.cc";

//    std::string copy_constructor = R"(
//     #include "%1%.ih"

//     %1%::%1%(%1% const &other)
//     // copy constructor
//     {

//     }
//    )";

    // std::ostringstream copy_constructor;
    // copy_constructor << "#include " << class_name << ".ih\n\n";
    // copy_constructor << class_name << "::" << class_name << '(' << class_name << " const &other)\n";
    // copy_constructor << "{\n}\n";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << "#include \"" << class_name << ".ih\"\n\n";
        file_writer << class_name << "::" << class_name << '(' << class_name << " const &other)\n";
        file_writer << "{\n}\n";
        // file_writer << copy_constructor.str();
        file_writer.close();
    }
}

void makeclass::make_move_constructor(std::string const &path)
{
    /*
        move constructor builder
    */
   std::string file_name = path + class_name + "3.cc";

    // std::string move_constructor = R"(
    // #include "%1%.ih"

    // %1%::%1%(%1% const &&tmp)
    // // move constructor
    // {

    // }
    // )";
    
    // std::ostringstream move_constructor;
    // move_constructor << "#include " << class_name << ".ih\n\n";
    // move_constructor << class_name << "::" << class_name << '(' << class_name << " const &&tmp)\n";
    // move_constructor << "{\n}\n";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << "#include \"" << class_name << ".ih\"\n\n";
        file_writer << class_name << "::" << class_name << '(' << class_name << " const &&tmp)\n";
        file_writer << "{\n}\n";
        // file_writer << move_constructor.str();
        file_writer.close();
    }
}


// ! DESTRUCTOR SKELETON BUILDER

void makeclass::make_destructor(std::string const &path)
{
    std::string file_name = path + "destructor.cc";

    // std::string destructor = R"(
    // #include "%1%.ih"

    // %1%::~%1%()
    // // destructor
    // {

    // }
    // )";

    // std::ostringstream destructor;
    // destructor << "#include " << class_name << ".ih\n\n";
    // destructor << class_name << "::~" << class_name << "()\n";
    // destructor << "{\n}\n";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << "#include \"" << class_name << ".ih\"\n\n";
        file_writer << class_name << "::~" << class_name << "()\n";
        file_writer << "{\n}\n";
        // file_writer << destructor.str();
        file_writer.close();
    }
}

// ! HEADER SKELETON BUILDER

void makeclass::make_header(std::string const &path, bool cpy, bool mv)
{
    std::string file_name = path + class_name + ".h";

    std::stringstream additional_methods;

    // std::string class_def = R"(
    // class %1%
    // {
    //     public:
    //     %1%();
    //     %2%

    //     private:

    // };
    // )";

    // std::ostringstream class_decl;
    // class_decl << "class " << class_name << '\n';
    // class_decl << "{\n\tpublic:\n" << "\t\t" << class_name << "();\n";


    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);

        file_writer << "#ifndef " << to_uppercase(class_name) << "_H_\n#define " << to_uppercase(class_name) << "_H_\n";

        if (_namespace != "")
        {
            file_writer << "\nnamespace " << _namespace << "\n{\n";
        }

        file_writer << "class " << class_name << '\n';
        file_writer << "{\n\tpublic:\n" << "\t\t" << class_name << "();\n";

        if (cpy)
        {
          additional_methods << "\t\t" << class_name << '(' << class_name << " const &other);\n";
          additional_methods << "\t\t" << class_name << " &operator=(" << class_name << " const &other);\n";
        }
        if (mv)
        {
          additional_methods << "\t\t" << class_name << '(' << class_name << " const &&tmp);\n";
          additional_methods << "\t\t" << class_name << " &operator=(" << class_name << " const &&tmp);\n";
        }


        // if (additional_methods != "")
        //     additional_methods = str(boost::format(additional_methods) % class_name);

        file_writer << additional_methods.str();

        file_writer << "\n\tprivate:\n};";

        file_writer << ((_namespace == "") ? "\n#endif\n" : "\n}\n#endif\n");
        file_writer.close();
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

        file_writer << "#include \"" << class_name << ".h\"\n\n";

        if (_namespace != "")
            file_writer << "using namespace " << _namespace << ";\n";

        file_writer.close();
    }
}

// ! ASSIGNMENT OPERATORS

void makeclass::assignment_op(std::string const &path)
{
    std::string file_name = path + "operator1.cc";

    // std::string assignment_op = R"(
    // #include "%1%.ih"

    // %1% &%1%::operator=(%1% const &other)
    // // assignment op
    // {

    // }
    // )";

    // std::ostringstream assignment;
    // assignment << "#include " << class_name << ".ih\n\n";
    // assignment << class_name << " &" << class_name << "::operator=(" << class_name << " const &other)\n";
    // assignment << "{\n}\n";


    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << "#include \"" << class_name << ".ih\"\n\n";
        file_writer << class_name << " &" << class_name << "::operator=(" << class_name << " const &other)\n";
        file_writer << "{\n}\n";
        // file_writer << assignment.str();
        file_writer.close();
    }
}

void makeclass::move_assignment_op(std::string const &path)
{
    std::string file_name = path + "operator2.cc";

    // std::string mv_assignment_op = R"(
    // #include "%1%.ih"

    // %1% &%1%::operator=(%1% const &&tmp)
    // // move assignment op
    // {

    // }
    // )";

    // std::ostringstream mv_assignment;
    // mv_assignment << "#include " << class_name << ".ih\n\n";
    // mv_assignment << class_name << " &" << class_name << "::operator=(" << class_name << " const &&tmp)\n";
    // mv_assignment << "{\n}\n";

    if (!std::filesystem::exists(file_name))
    {
        std::ofstream file_writer;
        file_writer.open(file_name);
        file_writer << "#include \"" << class_name << ".ih\"\n\n";
        file_writer << class_name << " &" << class_name << "::operator=(" << class_name << " const &&tmp)\n";
        file_writer << "{\n}\n";
        // file_writer << mv_assignment.str();
        file_writer.close();
    }
}

