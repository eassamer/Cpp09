#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <list>

class PmergeMe {
    private :
        std::vector<int> vec;
        std::list<int> lst;
    public :
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        void print();
        double sorter(char **av);
        int check_is_num(char *str);
        void sort_vec(std::vector<int> &vec, int left, int right, int k);
        void insertion_sort_vec(std::vector<int> &vec, int left, int right);
        void merge_vec(std::vector<int> &vec, int left, int mid, int right);
};
#endif