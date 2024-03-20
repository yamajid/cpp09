/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 05:16:17 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/19 23:55:15 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <ostream>

int main(int ac, char **av) 
{
    if (ac != 2) 
        return std::cerr << "Error" << std::endl, 1;

    try {
        std::cout << RPN::evalRPN(av[1]) << std::endl;
    } catch (std::exception &e) {
        return std::cerr << e.what() << std::endl, 1;
    }
}