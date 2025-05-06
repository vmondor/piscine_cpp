#include <iostream>
#include <string>
#include "File.hpp"

File::File(std::string filename, std::string s1, std::string s2)
{
    this->_outfile = filename + ".replace";
    this->_s1 = s1;
    this->_s2 = s2;
    return ;
}

File::~File()
{
    return ;
}

void    File::replace(std::string filename)
{
    std::ifstream src(filename.c_str());
    if (!src)
    {
        std::cout << "Error : Open infile" << std::endl;
        return ;
    }
    std::ofstream dst(this->_outfile.c_str());
    if (!dst)
    {
        std::cout << "Error : Open outfile" << std::endl;
        src.close();
        return ;
    }
    std::string line;
    while (std::getline(src, line))
    {
        size_t start(0);
        while ((start = line.find(this->_s1, start)) != std::string::npos)
        {
            line.erase(start, this->_s1.length());
            line.insert(start, this->_s2);
            start += this->_s2.length();
        }
        dst << line << std::endl;
    }
    src.close();
    dst.close();
    return ;
}