//
// Created by Jacob Pagan on 5/13/2025.
//

#ifndef BLACK_SCHOLES__MONTE_OPTIONS_H
#define BLACK_SCHOLES__MONTE_OPTIONS_H

#include <vector>
#include "Call.h"
#include "Put.h"
#include "OptionsMethodsInterface.h"


template<typename O>
concept OptionsType = std::same_as<O, Call> || std::same_as<O, Put>;
template<typename OptionsType>
class Options : OptionsMethodsInterface<OptionsType> {

    explicit Options(const std::vector<OptionsType>& options): options_(options) {}
    ~Options() = default;

    bool parity_check(const OptionsType& option) override;



private:
    std::vector<OptionsType> options_;
};


#endif //BLACK_SCHOLES__MONTE_OPTIONS_H
