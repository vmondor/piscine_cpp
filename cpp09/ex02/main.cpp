/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:49:36 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/22 17:07:49 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Invalid argument" << std::endl;
		return 1;
	}
	else
		PmergeMe me(ac, av);
    return 0;
}

