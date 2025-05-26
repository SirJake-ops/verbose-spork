//
// Created by Jacob Pagan on 5/13/2025.
//

#ifndef BLACK_SCHOLES__MONTE_OPTIONS_H
#define BLACK_SCHOLES__MONTE_OPTIONS_H

#include <vector>
#include "Call.h"
#include "Put.h"


template<typename T>
concept OptionsType = std::same_as<T, Call> || std::same_as<T, Put>;

template<OptionsType C, OptionsType P>
class Options {

    explicit Options(const std::vector<C> &call_options, const std::vector<P> &put_options)
            : call_options_(call_options), put_options_(put_options) {}

    ~Options() = default;

    bool parity_check(const C &call, const P &put, double tolerance) override;


private:
    C call_option_;
    P put_option_;
    std::vector<C> call_options_;
    std::vector<P> put_options_;
};


#endif //BLACK_SCHOLES__MONTE_OPTIONS_H
