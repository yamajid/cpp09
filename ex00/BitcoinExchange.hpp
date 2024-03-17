/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:30:11 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/17 03:55:01 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>

typedef std::map<std::string, double> DB;

class BitcoinExchange{
    private:
        DB database;
    public:
        DB& getDatabase();
        BitcoinExchange();    
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        BitcoinExchange(const BitcoinExchange& other);
};


