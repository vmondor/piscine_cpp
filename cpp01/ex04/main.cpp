#include <iostream>
#include <string>
#include <fstream>
#include "File.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 4)
	{
		std::cout << "Invalid argument" << std::endl;
		return (1);
	}
	else
	{
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];

		File	file(filename, s1, s2);
		file.replace(filename);
		
	}
	return (0);
}
