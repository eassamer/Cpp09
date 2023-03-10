#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        vec = other.vec;
        lst = other.lst;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::insertion_sort_vec(std::vector<int> &vec, int left, int right)
{
    for (int i = left + 1; i <= right; ++i) {
        int key = vec[i];
        int j = i - 1;
        
        while (j >= left && vec[j] > key) {
            vec[j+1] = vec[j];
            j--;
        }
        
        vec[j+1] = key;
    }
}

void PmergeMe::merge_vec(std::vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; ++i) {
        L[i] = vec[left + i];
    }
    
    for (int j = 0; j < n2; ++j) {
        R[j] = vec[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::sort_vec(std::vector<int> &vec, int left, int right, int k)
{
    if (left < right) {
        if (right - left + 1 <= k) {
            insertion_sort_vec(vec, left, right);
        }
        else {
            int mid = left + (right - left) / 2;
            
            sort_vec(vec, left, mid, k);
            sort_vec(vec, mid+1, right, k);
            merge_vec(vec, left, mid, right);
        }
    }
}

int PmergeMe::check_is_num(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}
double PmergeMe::sorter(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        if (check_is_num(av[i]))
        {
            vec.push_back(std::stoi(av[i]));
            lst.push_back(std::stoi(av[i]));
        }
        else
            throw std::invalid_argument("Error: " + std::string(av[i]) + " is not a number");
    }
    sort_vec(vec, 0, vec.size() - 1, vec.size() / 4);
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
}