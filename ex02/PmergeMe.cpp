/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:10:08 by yamajid           #+#    #+#             */
/*   Updated: 2024/03/20 00:41:59 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
    (void)obj;
    return *this;
}

PmergeMe::~PmergeMe() {
}


std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start != std::string::npos && end != std::string::npos) {
        return str.substr(start, end - start + 1);
    }
    return "";
}


int PmergeMe::parseNumbers(std::string str, std::vector<int>& vect, std::deque<int>& dequ, size_t i){
    std::string trimmed = trim(str);
    if (trimmed.empty())
        return 0;
    long num;
    std::stringstream ss(trimmed);
    
    if (!(ss >> num) || !ss.eof() || num > INT_MAX || num < INT_MIN)
        return 0;
    if (num < 0)
        return 0;
    vect[i] = num;
    dequ[i] = num;
    return 1;
}

std::vector<std::pair<int, int> > PmergeMe::groupIntoPairsInVector(std::vector<int>& vect, int& lastelement){
    std::vector<std::pair<int, int> > pairs;

    for(size_t i = 0; i + 1 < vect.size(); i += 2)
        pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
    if (vect.size() % 2 == 1)
        lastelement = vect[vect.size() - 1];
    for(size_t i = 0; i < pairs.size(); i++)
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    std::sort(pairs.begin(), pairs.end());
    return pairs;
}

std::deque<std::pair<int, int> > PmergeMe::groupIntoPairsInDeque(std::deque<int>& vect, int& lastelement){
    std::deque<std::pair<int, int> > pairs;
    
    for(size_t i = 0; i + 1 < vect.size(); i += 2)
        pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
    if (vect.size() % 2 == 1)
        lastelement = vect[vect.size() - 1];
    for(size_t i = 0; i < pairs.size(); i++)
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    std::sort(pairs.begin(), pairs.end());
    return pairs;
}


std::vector<int>    PmergeMe::generateJacobSeq(size_t vectSize){
    std::vector<int>    Jacob;
    size_t j = 1;
    size_t i = 1;
    size_t current = 1;

    Jacob.push_back(0);
    while (true){
        if (current >= vectSize){   
            Jacob.push_back(vectSize);
            break ;
        }
        else if (current < vectSize){
            Jacob.push_back(current);
            current = i + (j * 2);
            j = i;
            i = current;
        }
    }
    return Jacob;
}

void PmergeMe::sortForDeque(std::deque<int>& vect){
    int lastelement = -1;
    std::deque<std::pair<int, int> > pairs = groupIntoPairsInDeque(vect, lastelement);
    std::vector<int> pendChain(pairs.size());
    vect.resize(pairs.size());
    
    for(size_t i = 0; i < pairs.size(); i++){
        vect[i] = pairs[i].first;
        pendChain[i] = pairs[i].second;
    }
    vect.insert(vect.begin(), pendChain[0]);
    std::vector<int> Jacob = generateJacobSeq(pendChain.size() - 1);
    for (size_t i = 1; i < Jacob.size(); i++){
        int index = Jacob[i];
        for (; index > Jacob[i - 1]; index--)
            vect.insert(std::lower_bound(vect.begin(), vect.end(), pendChain[index]), pendChain[index]);
    }
    if (lastelement != -1)
            vect.insert(std::lower_bound(vect.begin(), vect.end(), lastelement), lastelement);
}

void PmergeMe::sortForVector(std::vector<int>& vect) {
    int lastelement = -1;
    std::vector<std::pair<int, int> > pairs = groupIntoPairsInVector(vect, lastelement);
    std::vector<int> pendChain(pairs.size());
    vect.resize(pairs.size());
    
    for(size_t i = 0; i < pairs.size(); i++){
        vect[i] = pairs[i].first;
        pendChain[i] = pairs[i].second;
    }
    vect.insert(vect.begin(), pendChain[0]);
    std::vector<int> Jacob = generateJacobSeq(pendChain.size() - 1);
    for (size_t i = 1; i < Jacob.size(); i++){
        int index = Jacob[i];
        for (; index > Jacob[i - 1]; index--)
            vect.insert(std::lower_bound(vect.begin(), vect.end(), pendChain[index]), pendChain[index]);
    }
    if (lastelement != -1)
            vect.insert(std::lower_bound(vect.begin(), vect.end(), lastelement), lastelement);
}
