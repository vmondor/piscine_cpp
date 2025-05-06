/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:09:54 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/23 12:52:18 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(RPN const& src)
{
    this->_stack = src._stack;
    this->_temp_result = src._temp_result;
}

RPN& RPN::operator=(RPN const& src)
{
    if (this != &src)
    {
        this->_stack = src._stack;
        this->_temp_result = src._temp_result;
    }
    return *this;
}

RPN::~RPN()
{

}

int RPN::tooLargeNumber( std::string str )
{
    int result;
    std::istringstream iss(str);
    iss >> result;
    if (result < -9 || result > 9)
        return 1;
    return 0;
}

void RPN::calc( std::string expression )
{
    std::istringstream iss(expression);
    std::string str;

    while (iss >> str)
    {
        if (this->tooLargeNumber(str))
            throw InvalidExpressionException();
        if (this->isOperator(str))
        {
            if (this->_stack.size() < 2)
                throw InvalidExpressionException();
            int op2 = this->_stack.top();
            this->_stack.pop();
            int op1 = this->_stack.top();
            this->_stack.pop();
            this->applyOperator(str[0], op1, op2);
            this->_stack.push(this->_temp_result);
        }
        else if (this->isNumber(str))
            this->_stack.push(std::atoi(str.c_str()));
        else
            throw InvalidExpressionException();
    }
    if (this->_stack.size() != 1)
        throw InvalidExpressionException();
    return ;
}

bool    RPN::isOperator( std::string str )
{
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return true;
    return false;
}

bool    RPN::isNumber( std::string str )
{
    size_t start = 0;
    if (str[0] == '-')
        start = 1;

    for (size_t i = start; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void     RPN::applyOperator(char c, int a, int b)
{
    switch (c)
    {
        case '+':
            this->_temp_result = a + b;
            break ;
        case '-':
            this->_temp_result = a - b;
            break ;
        case '*':
            this->_temp_result = a * b;
            break ;
        case '/':
            if (b == 0)
                throw DivisionByZeroException();
            this->_temp_result = a / b;
            break ;
        default:
            throw InvalidExpressionException();

    }
}

int RPN::getResult() const
{
    return this->_stack.top();
}