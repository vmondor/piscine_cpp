/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/23 12:47:36 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>
#include <limits>


class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        std::map<std::string, float> readDataCsv( std::string& filename );
        std::string findDate( std::map<std::string, float>& btcPrice, std::string date );
        bool isValidValue( float value );
        bool emptyFile( const std::string filename );
        bool isLeapYear( int year );
        void readInputFile( std::string filename, std::map<std::string, float>& btcPrice );

    private:
        BitcoinExchange(BitcoinExchange const& src);
        BitcoinExchange& operator=(BitcoinExchange const& src);
       
};