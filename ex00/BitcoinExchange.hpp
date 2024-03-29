/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:30:11 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/19 23:18:34 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>






#define DB "data.csv"


class BitcoinExchange{
    private:
        std::map<std::string, double> database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();
        double  getRate(std::string date, double quantity);
};


