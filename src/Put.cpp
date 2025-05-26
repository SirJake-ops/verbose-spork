//
// Created by Jacob Pagan on 5/10/25.
//

#include "../include/Put.h"

double Put::cumulative_distribution_function(double standard_deviation) const {
    return 0.5 * (1.0 + std::erf(standard_deviation / std::sqrt(2.0)));
}

double Put::price() const {
    return strike_price_ * std::exp(-rfr_ * time_to_expire_) *
           cumulative_distribution_function(-get_standard_deviation_two()) - current_stock_price_ *
                                                                             cumulative_distribution_function(
                                                                                     -get_standard_deviation_one());
}