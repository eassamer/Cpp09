// #include <iostream>
// #include <list>

// using namespace std;

// // Insertion sort function for sorting small subarrays
// void insertionSort(list<int>& lst, list<int>::iterator left, list<int>::iterator right) {
//     for (auto i = next(left); i != next(right); ++i) {
//         int key = *i;
//         auto j = prev(i);
        
//         while (j != prev(left) && *j > key) {
//             *(next(j)) = *j;
//             j = prev(j);
//         }
        
//         *(next(j)) = key;
//     }
// }

// // Merge function for merging two sorted subarrays
// void merge(list<int>& lst, list<int>::iterator left, list<int>::iterator mid, list<int>::iterator right) {
//     list<int> L(left, next(mid));
//     list<int> R(mid, next(right));
    
//     auto i = L.begin();
//     auto j = R.begin();
    
//     while (i != L.end() && j != R.end()) {
//         if (*i <= *j) {
//             *(left++) = *(i++);
//         }
//         else {
//             *(left++) = *(j++);
//         }
//     }
    
//     while (i != L.end()) {
//         *(left++) = *(i++);
//     }
    
//     while (j != R.end()) {
//         *(left++) = *(j++);
//     }
// }

// // Merge-insertion sort function
// void mergeInsertionSort(list<int>& lst, list<int>::iterator left, list<int>::iterator right, int k) {
//     if (distance(left, right) > 1) {
//         if (distance(left, right) <= k) {
//             insertionSort(lst, left, right);
//         }
//         else {
//             auto mid = next(left, distance(left, right) / 2);
            
//             mergeInsertionSort(lst, left, mid, k);
//             mergeInsertionSort(lst, mid, right, k);
            
//             merge(lst, left, mid, right);
//         }
//     }
// }

// // Main function
// int main() {
//     list<int> lst = {8, 1, 4, 2, 9, 3, 7, 5};
//     int k = 4; // subarray size
    
//     mergeInsertionSort(lst, lst.begin(), lst.end(), k);
    
//     for (auto x : lst) {
//         cout << x << " ";
//     }
    
//     return 0;
// }


#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe p;
    try
    {
        (void)ac;
        p.sorter(av);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}