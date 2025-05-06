#include <iostream>
#include <string>

void	megaphone(std::string &str)
{
	for(int i = 0; i < (int)str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		std::string str;
		for (int i = 1; i < ac; i++)
		{
			if (i > 1)
				str += " ";
			str += av[i];
		}
		megaphone(str);
		std::cout << str << std::endl;
	}
	return (0);
}