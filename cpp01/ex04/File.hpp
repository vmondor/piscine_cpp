#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

class File
{
    public :
        File(std::string filename, std::string s1, std::string s2);
        ~File();
        void    replace(std::string filename);

    
    private :
        std::string _outfile;
        std::string _s1;
        std::string _s2;
};


#endif