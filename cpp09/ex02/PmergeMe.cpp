/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:09:54 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/22 17:09:41 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( int ac, char** av )
{
    try
    {
        this->parsing(ac, av);
        std::cout << "Before : ";
        this->displayVec();

        clock_t startVec = clock();
        this->mergeInsertSortVec();
        clock_t endVec = clock();
        double tempVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;

        clock_t startLst = clock();
        this->mergeInsertSortLst();
        clock_t endLst = clock();
        double tempLst = static_cast<double>(endLst - startLst) / CLOCKS_PER_SEC;

        std::cout << "After  : ";
        this->displayVec();

        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::list   : " << tempLst << " us" << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << tempVec << " us" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::parsing( int ac, char **av )
{
    std::string str;
    int         value;
    
    for (int i = 1; i < ac; i++)
    {
        str = av[i];
        if (str.empty())
                throw InvalidParsingException();
        for (size_t j = 0; j < str.size(); j++)
        {
            if (!isdigit(str[j]))
                throw InvalidParsingException();
        }
        value = std::atoi(str.c_str());
        if (value < 0)
            throw InvalidParsingException();
        this->_lst.push_back(value);
        this->_vec.push_back(value);
    }
    std::set<int> numbers;
    for (std::list<int>::const_iterator it = this->_lst.begin(); it != this->_lst.end(); it++)
    {
        if (!numbers.insert(*it).second)
            throw InvalidParsingException();
    }
}
void    PmergeMe::displayLst( void ) const
{
    for (std::list<int>::const_iterator it = this->_lst.begin(); it != this->_lst.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::displayVec( void ) const
{
    for (std::vector<int>::const_iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::mergeInsertSortVec( void )
{
    if (this->_vec.size() == 1)
        return ;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < this->_vec.size(); i += 2)
    {
        if (i + 1 < this->_vec.size())
        {
            if (this->_vec[i] > this->_vec[i + 1])
                pairs.push_back(std::make_pair(this->_vec[i + 1], this->_vec[i]));
            else
                pairs.push_back(std::make_pair(this->_vec[i], this->_vec[i + 1]));
        }
        else
            pairs.push_back(std::make_pair(this->_vec[i], -1));
    }
    std::vector<int> vect;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        vect.push_back(it->first);
    }
    std::sort(vect.begin(), vect.end());
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second != -1)
        {
            std::vector<int>::iterator pos = std::upper_bound(vect.begin(), vect.end(), it->second);
            vect.insert(pos, it->second);
        }
    }
    this->_vec = vect;
}

void    PmergeMe::mergeInsertSortLst( void )
{
    if (this->_lst.size() == 1)
        return ;
    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = this->_lst.begin();
    while (it != this->_lst.end())
    {
        int first = *it;
        it++;
        int second = -1;
        if (it != this->_lst.end())
        {
            second = *it;
            it++;
        }
        if (first > second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
    }
    std::list<int> lsttemp;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        lsttemp.push_back(it->first);
    }
    lsttemp.sort();
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second != -1)
        {
            std::list<int>::iterator pos = lsttemp.begin();
            while (pos != lsttemp.end() && *pos < it->second)
            {
                pos++;
            }
            lsttemp.insert(pos, it->second);
        }
    }
    this->_lst = lsttemp;
}
