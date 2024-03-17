/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:30:15 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/17 03:51:52 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    parseDataBase(std::map<std::string, double>& database) {
    std::fstream    datafile("data.csv");
    std::string     dataline;

    if (datafile.is_open()){
        std::getline(datafile, dataline);
        if (dataline != "date,exchange_rate") {
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
}

int checkLine(std::string date){
        std::stringstream iss;
        iss << date;
        char d1, d2;
        
        int year = 0, month = 0, day = 0;
        if (date.size() != 10){
            std::cerr << "Error: Invalide date format" << std::endl;
            return 0;
        }
        if (!(iss >> year >> d1 >> month >> d2 >> day) || !iss.eof()){
            std::cerr << "Error: Invalid Date" << std::endl;
            return 0;
        }
        if (d1 != '-' || d2 != '-')
            std::cerr << "Error: Invalid Date" << std::endl;
        if(year < 2009 || (month < 1 || month > 12) || (day < 1 || day > 31)){
            std::cerr << "Error: bad input => " << year << d1 << month << d2 << day << std::endl;
            return 0;
        }
        if ((month % 2 == 0 && month < 8 && day > 30) || (month % 2 != 0 && month > 7 && day > 30)){
            std::cerr << "Error: This day doesen't exist" << std::endl;
            return 0;
        }
        return 1;
    }     
        
double checkValue(std::string value){
    std::stringstream  iss;

    iss << value;
    double val = 0.0;
    if (!(iss >> val) || !iss.eof()){   
        std::cout << "Error: Invalid Value" << std::endl;
        return 0;
    }
    if (val > 1000){   
        std::cout << "Error: too large a number" << std::endl;
        return 0;
    }
    else if (val < 0){
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    return val;
}

void    parseInput(std::map<std::string, double>& database, std::string filename){
    std::fstream    inputFile(filename);
    std::string     dataline;
    double val = 0.0;
    
    if (inputFile.is_open()){
        std::getline(inputFile, dataline);
        if (dataline != "date | value") {
            std::cerr << "Error: invalid file format" << std::endl;
            exit(1);
        }
        std::map<std::string, double>::iterator it;
        std::map<std::string, double>::iterator low ;
        while (getline(inputFile, dataline)){
                // std::cout<<"line:" << dataline <<std::endl;
            if (dataline.empty())
                continue;
            size_t pos = dataline.find(" | ");
            std::string date = dataline.substr(0, pos);
            std::string value = dataline.substr(pos + 3);
            if ((checkLine(date) != 0) && ((val = checkValue(value)) != 0)){
                it = database.find(date);
                if (it != database.end())
                    std::cout << date << " " << "  =>  " << value << "   =  " << std::fixed << std::setprecision(1) << it->second * val << std::endl;
                else {
                        low = database.lower_bound(date);
                        if (low != database.end()){
                            low--;
                            std::cout << date << " " << "  =>  " << std::fixed << std::setprecision(1) << value << " =  " << std::fixed << std::setprecision(2) << low->second * std::strtod(value.c_str(), NULL) << std::endl;
                        }
                        else
                            std::cerr << "Error: Date Not Found" << std::endl;                       
                
                }
            }
        }
        inputFile.close();
    }
}

int main (int argc, char **argv){
    
    BitcoinExchange data;
    if (argc != 2)
        return std::cerr << "usage: ./btc [filename]" << std::endl, 0;
    try{
        parseDataBase(data.getDatabase());
        parseInput(data.getDatabase(), argv[1]);
        
        
    }
    catch(const std::exception&){
        std::cout << "Error : Invalid Input" << std::endl;
    }
    
    return 1;
}

// std::lower_bound(map.begin, )