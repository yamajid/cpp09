/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:08:15 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/20 00:47:16 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <ctime>
#include <iomanip>


int main(int argc, char **argv){
    std::vector<int> holdervect;
    std::deque<int> holderdequ;
    
    if (argc < 2)
        return std::cout << "Usage: ./PmergeMe [...]", 0;
    holdervect.resize(argc - 1);
    holderdequ.resize(argc - 1);
    for (size_t i = 1; i <= holdervect.size(); i++)
        if (PmergeMe::parseNumbers(argv[i],holdervect, holderdequ, i - 1) == 0)
            return std::cout << "Invalid Number" << std::endl, 0;
    if (holdervect.size() < 2)
        return std::cout << "Not Enough Numbers" << std::endl, 0;
    std::cout << "Before: ";
    for (size_t i = 0; i < holdervect.size(); i++)
        std::cout << holdervect[i] << " ";
    std::cout << std::endl;
    clock_t startv = clock();
    PmergeMe::sortForVector(holdervect);
    clock_t endv = clock();
    double totalv = double(endv - startv) / CLOCKS_PER_SEC;
    std::cout << "After:  ";
    for (size_t i = 0; i < holdervect.size(); i++)
        std::cout << holdervect[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << std::setprecision(5) << totalv << " us" <<  std::endl;
    clock_t startd = clock();
    PmergeMe::sortForDeque(holderdequ);
    clock_t endd = clock();
    double totald = double(endd - startd) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::fixed << std::setprecision(5) << totald << " us" << std::endl;
}