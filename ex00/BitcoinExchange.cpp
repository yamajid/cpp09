/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:30:13 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/17 03:55:09 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    
}

BitcoinExchange::~BitcoinExchange(){
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
    *this = obj;
}
DB& BitcoinExchange::getDatabase()
{
    return database;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other){}
    return *this;
}