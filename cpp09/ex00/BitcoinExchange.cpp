/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:09:54 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/23 12:47:47 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src)
{
    (void)src;
}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& src)
{
    (void)src;
    return *this;
}       

std::map<std::string, float> BitcoinExchange::readDataCsv( std::string& filename )
{
    std::map<std::string, float> btcPrice;
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return btcPrice;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        float price;
        if(std::getline(ss, date, ',') && ss >> price)
            btcPrice[date] = price;
    }
    file.close();
    return btcPrice;
}

std::string BitcoinExchange::findDate( std::map<std::string, float>& btcPrice, std::string date )
{
    std::map<std::string, float>::const_iterator it = btcPrice.lower_bound(date);
    if (it != btcPrice.end() && it->first == date)
        return it->first;
    if (it == btcPrice.begin())
        return "";
    if (it == btcPrice.end()  || it->first != date)
        it--;
    return it->first;
}

bool BitcoinExchange::isValidValue( float value )
{
    return (value >= 0 && value <= 1000);
}

bool BitcoinExchange::emptyFile( const std::string filename )
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;
    file.seekg(0, std::ios::end);
    if (file.tellg() == 0)
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}

bool BitcoinExchange::isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

void BitcoinExchange::readInputFile( const std::string filename, std::map<std::string, float>& btcPrice )
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return ;
    }
        
    if (this->emptyFile(filename))
    {
        std::cerr << "Error: File is empty." << std::endl;
        file.close();
        return ;
    }
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
    {
        std::cerr << "Error: The header file is wrong." << std::endl;
        file.close();
        return ;
    }
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;

        bool flag = true;
        for ( size_t i = 0; i < line.size(); i++ )
        {
            if ((i == 4 || i == 7) && line[i] != '-')
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                flag = false;
                break ;
            }
            if (!isdigit(line[i]) && line[i] != '-' && line[i] != ' ' && line[i] != '|' && line[i] != '.')
            {
                
                std::cerr << "Error: bad input => " << line << std::endl;
                flag = false;
                break ;
            }
        }
        if (!flag)
            continue ;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date.erase(date.find_last_not_of(" \n\r\t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));
            if (date.size() != 10)
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            int year, month, day;
            std::stringstream dateStream(date.substr(0, 4));
            dateStream >> year;
            std::stringstream monthStream(date.substr(5, 2));
            monthStream >> month;
            std::stringstream dayStream(date.substr(8, 2));
            dayStream >> day;

            if ((month == 2 && day == 29 && !this->isLeapYear(year)) || (month == 2 && day > 29))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            else if (month < 1 || month > 12)
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }  

            float value;
            std::istringstream(valueStr) >> value;
            if (!this->isValidValue(value))
            {
                if (value < 0)
                    std::cerr << "Error: not a positive number." << std::endl;
                else if (value > 1000)
                    std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            std::string beforeDate = this->findDate(btcPrice, date);
            if (beforeDate.empty())
            {
                std::cerr << "Error: no available data for date => " << date << std::endl;
                continue;
            }
            float btc = btcPrice.at(beforeDate);
            float result = value * btc;
            if (valueStr != "0" && value == 0)
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue; 
            }
            else
                std::cout << date << " => " << value << " = " << result << std::endl;
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{

}