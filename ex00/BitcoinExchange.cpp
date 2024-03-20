/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:30:13 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/19 22:58:05 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <string>



BitcoinExchange::BitcoinExchange(){
    std::fstream    datafile(DB);
    std::string     dataline;

    if (!datafile.is_open() || !std::getline(datafile, dataline) || dataline != "date,exchange_rate") {
        std::cerr << "Error: invalid file format" << std::endl;
        exit(1);
    }
    while (getline(datafile, dataline)){
        if (dataline.empty())
            continue;
        size_t pos = dataline.find(",");
        if (pos == std::string::npos)
            exit(1);
        std::string date = dataline.substr(0, pos);
        std::string value = dataline.substr(pos + 1);
        database[date] = std::strtod(value.c_str(), NULL);
    }
    datafile.close();
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
    *this = obj;
}

double  BitcoinExchange::getRate(std::string date, double quantity){
    std::map<std::string, double>::iterator it = database.find(date);
    if (it != database.end())
        return it->second * quantity;
    else{
        it = database.lower_bound(date);
        if (it == database.begin())
            throw std::runtime_error("Error: Date Not Found");
        it--;
        return it->second * quantity;
    }
}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other){
        database = other.database;
    }
    return *this;
}