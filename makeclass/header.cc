#include "include/makeclass.ih"

void makeclass::make_header(std::string const &path)
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

        file_writer << boost::format("#ifndef %1%_H_\n#define %1%_H_\n") % boost::to_upper_copy<std::string>(class_name);
        
        if (_namespace != "")
        {
            file_writer << "\nnamespace " << _namespace << "\n{\n";
        }


        if (copy_constructor)
            additional_methods += "%1%(%1% const &other);\n";
        if (move_constructor)
            additional_methods += "\t\t%1%(%1% const &&tmp);\n";


        file_writer << boost::format(class_def) 
            % class_name 
            % (boost::format(additional_methods) % class_name);

        file_writer << "}\n" << "#endif\n";
    }
}