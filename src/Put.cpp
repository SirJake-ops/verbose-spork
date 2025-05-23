//
// Created by Jacob Pagan on 5/10/25.
//

#include "../include/Put.h"

double Put::cumulative_distribution_function(double standard_deviation) const {
    return 0.5 * (1.0 + std::erf(standard_deviation / std::sqrt(2.0)));
}
