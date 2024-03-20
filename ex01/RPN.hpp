/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:40:17 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/20 00:08:26 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>




class   RPN {
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& obj);
        ~RPN();
        static int evalRPN(std::string str);
        static int calc(char op, int a, int b);
};
