//
// Created by Jacob Pagan on 5/13/2025.
//

#ifndef BLACK_SCHOLES__MONTE_OPTIONS_H
#define BLACK_SCHOLES__MONTE_OPTIONS_H

#include <vector>

template<typename O>
class Options {

    explicit Options(const std::vector<O>& options): options_(options) {}
    ~Options() = default;

private:
    std::vector<O> options_;
};


#endif //BLACK_SCHOLES__MONTE_OPTIONS_H
