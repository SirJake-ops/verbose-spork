//
// Created by Jacob Pagan on 5/10/25.
//

#ifndef OPTIONSMETHODS_H
#define OPTIONSMETHODS_H

#endif //OPTIONSMETHODS_H

#include "Call.h"
#include "Put.h"

template<typename O>
concept OptionType = std::same_as<O, Call> || std::same_as<O, Put>;
template<typename OptionType>
class OptionsMethodsInterface {
public:
    OptionsMethodsInterface() = default;
    virtual ~OptionsMethodsInterface() = default;
    virtual bool parity_check(const OptionType& option) = 0;

};