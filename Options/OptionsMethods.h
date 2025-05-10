//
// Created by Jacob Pagan on 5/10/25.
//

#ifndef OPTIONSMETHODS_H
#define OPTIONSMETHODS_H

#endif //OPTIONSMETHODS_H

template<typename C, typename P>
class OptionsMethods {
public:
    virtual ~OptionsMethods() = default;
    virtual bool parity_check(const C& call_option, const P& put_option) = 0;

};