/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:42:10 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/20 00:04:08 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <stdexcept>

RPN::RPN() {
}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &obj) {
    (void)obj;
    return *this;
}

RPN::~RPN() {
}

int RPN::calc(char op, int a, int b)
{
    if (op == '/' && b == 0)
        throw std::runtime_error("Error: devision by zero");
    else if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '/') return a / b;
    return a * b;
}

int  RPN::evalRPN(std::string str)
{
    std::stack<int> result;

    for (size_t i = 0; i < str.size(); i++) {
        if (isspace(str[i])) 
            continue;
        else if (i != str.size() - 1 && !isspace(str[i + 1]))
            throw std::runtime_error("Error");
        else if (isdigit(str[i])) {
            result.push(str[i] - '0');
        }
        else if (str[i] == '-' || str[i] == '+' || str[i] == '/' || str[i] == '*') {
            if (result.size() < 2)
                throw std::runtime_error("Error");
            int b = result.top(); result.pop();
            int a = result.top(); result.pop();
            result.push(RPN::calc(str[i], a, b));
        } else
            throw std::runtime_error("Error");
    }
    if (result.size() != 1)
        throw std::runtime_error("Error");
    return result.top();
}