/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:43:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/03 13:53:22 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(T const &elem)
{
    std::cout << elem << " ";
}

void multiplyByTwo(int &elem)
{
    elem *= 2;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    int length = 5;

    std::cout << "Tableau initial : ";
    iter(intArray, length, printElement<int>);
    std::cout << std::endl;

    std::cout << "Multiplication par 2 de chaque élément : ";
    iter(intArray, length, multiplyByTwo);
    iter(intArray, length, printElement<int>);
    std::cout << std::endl;

    std::string stringArray[] = {"apple", "banana", "cherry"};
    int stringLength = 3;

    std::cout << "Tableau de chaînes : ";
    iter(stringArray, stringLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}