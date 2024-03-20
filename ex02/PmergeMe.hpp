/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:06:33 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/20 00:09:49 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>


class   PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        static int parseNumbers(std::string str, std::vector<int>& vect, std::deque<int>& dequ, size_t i);
        static std::vector<std::pair<int, int> > groupIntoPairsInVector(std::vector<int>& vect, int& lastelement);
        static std::deque<std::pair<int, int> > groupIntoPairsInDeque(std::deque<int>& vect, int& lastelement);
        static std::vector<int>    generateJacobSeq(size_t vectSize);
        static void sortForDeque(std::deque<int>& vect);
        static void sortForVector(std::vector<int>& vect);
};