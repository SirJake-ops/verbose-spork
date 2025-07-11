//
// Created by Jacob Pagan on 5/13/2025.
//

#include "../include/Options.h"

template<OptionsType C, OptionsType P>
bool Options<C, P>::parity_check(const C& call, const P& put) {
    /**
     * Call - Put = Current_Stock_price - Strike_price * exp(-rfr*time_to_expire)
     * */
    constexpr double tolerance = 1e-4;
     const auto call_ = static_cast<Call>(call);
     const auto put_ = static_cast<Put>(put);

     const double lhs = call_.price() + put_.get_strike_price() * std::exp(-put_.get_rfr() * call_.get_time_to_expire());
     const double rhs = put_.price() + put_.get_current_price();

     return std::abs(lhs - rhs) < tolerance;
}