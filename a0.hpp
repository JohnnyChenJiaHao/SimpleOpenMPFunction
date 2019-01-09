// File: a0.hpp
// FirstName: Jia Hao Johnny
// LastName: Chen
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A0_HPP
#define A0_HPP

#include <vector>
#include <iostream>
#include <omp.h>

// IMPLEMENT ME!
template <typename T, typename Pred>
void omp_extract_if(const std::vector<T>& in, std::vector<T>& out, Pred pred) {
        omp_lock_t lock_t;
        omp_init_lock(&lock_t);

#pragma omp parallel for schedule(auto) shared(in, out, pred)
        for (int x = 0; x < in.size(); ++x) {
            if (pred(x)) {
                omp_set_lock(&lock_t);
                out.push_back(x);
                omp_unset_lock(&lock_t);
            }
        }
} // omp_extract_if

#endif // A0_HPP
