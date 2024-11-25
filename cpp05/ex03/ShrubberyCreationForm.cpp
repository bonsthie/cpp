#include "ShrubberyCreationForm.h"
#include "log.h"
#include <fstream>

#define MIN_SIGN 145
#define MIN_EXEC 137

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src) {
    LOG("constructor ShrubberyCreationForm copy")
    if (this != &src)
        *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    LOG("destructor ShrubberyCreationForm")}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &src) {
    if (this == &src)
        return (*this);
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("default_shrubbery", MIN_SIGN,
            MIN_EXEC){LOG("constructor ShrubberyCreationForm empty")}

      ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
    : AForm(name, MIN_SIGN, MIN_EXEC) {
    LOG("constructor ShrubberyCreationForm empty")
}

void ShrubberyCreationForm::_interExecute(const Bureaucrat &b) const {

	std::ofstream outfile(std::string(b.getName() + "_shrubbery").c_str());
    if (!outfile.is_open()) {
        throw openFileFailed();
    }

outfile << "       /\\              /\\              /\\      \n"
            << "      /\\*\\            /\\*\\            /\\*\\     \n"
            << "     /\\O\\*\\          /\\O\\*\\          /\\O\\*\\    \n"
            << "    /*/\\/\\*\\        /*/\\/\\*\\        /*/\\/\\*\\   \n"
            << "   /\\O\\/\\*\\/\\      /\\O\\/\\*\\/\\      /\\O\\/\\*\\/\\  \n"
            << "  /\\*\\/\\*\\/\\*\\    /\\*\\/\\*\\/\\*\\    /\\*\\/\\*\\/\\*\\ \n"
            << " /\\O\\/\\/*/\\/O/\\  /\\O\\/\\/*/\\/O/\\  /\\O\\/\\/*/\\/O/\\\n"
            << "       ||              ||              ||      \n"
            << "       ||              ||              ||      \n"
            << "       ||              ||              ||      \n";
    outfile.close();

    std::cout << "ASCII trees created in " << b << "_shrubbery file.\n";
}

ERR_WHAT(ShrubberyCreationForm, openFileFailed, "Failed to create the file.")
