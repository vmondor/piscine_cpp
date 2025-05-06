#include "RPN.hpp"


int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
		{
			std::cerr << "Error: invalid number of arguments." << std::endl;
			return 1;
		}
		RPN rpn = RPN();
		std::string expression(av[1]);
		rpn.calc(expression);
		int result = rpn.getResult();
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}

