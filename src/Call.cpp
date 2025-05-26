//
// Created by Jacob Pagan on 5/10/25.
//

#include "../include/Call.h"

double Call::cumulative_distribution_function(double standard_deviation) const {
    return 0.5 * (1.0 + std::erf(standard_deviation / std::sqrt(2.0)));
}

double Call::price() const {
    return current_stock_price_ * cumulative_distribution_function(get_standard_deviation_one()) -
           strike_price_ * std::exp(-rfr_ * time_to_expire_) *
           cumulative_distribution_function(get_standard_deviation_two());
}
