//
// Created by Jacob Pagan on 5/10/25.
//

#ifndef OPTIONSMETHODS_H
#define OPTIONSMETHODS_H

#endif //OPTIONSMETHODS_H

template<typename O>
class OptionsMethodsInterface {
public:
    virtual ~OptionsMethodsInterface() = default;
    virtual bool parity_check(const O& option) = 0;

};