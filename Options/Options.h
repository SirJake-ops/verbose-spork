//
// Created by Jacob Pagan on 5/10/25.
//

#ifndef OPTIONS_H
#define OPTIONS_H
#include "OptionsMethods.h"
#include "Calls/Call.h"
#include "Puts/Put.h"


class Options : OptionsMethods<Call, Put> {
public:
    Options(const Call &call, const Put &put): call_(call),
                                               put_(put) {}


    bool parity_check(const Call &call_option, const Put &put_option) override;

private:
    Call call_;
    Put put_;
};


#endif //OPTIONS_H
