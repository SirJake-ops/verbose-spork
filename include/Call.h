//
// Created by Jacob Pagan on 5/10/25.
//

#ifndef CALL_H
#define CALL_H

#include <cmath>
#include <ostream>


class Call {
public:

    Call() = default;

    Call(const double current_stock_price, const double strike_price, const double time_to_expire, const double rfr,
         const double volatility) : current_stock_price_(current_stock_price),
                              strike_price_(strike_price),
                              time_to_expire_(time_to_expire),
                              rfr_(rfr),
                              volatility_(volatility) {
        standard_deviation_one_ = (std::log(current_stock_price / strike_price) + (rfr + std::pow(volatility, 2)) *
                                                                                  time_to_expire) /
                                  (volatility * std::sqrt(time_to_expire));

        standard_deviation_two_ = standard_deviation_one_ - (volatility * std::sqrt(time_to_expire));
    }

    [[nodiscard]] double cumulative_distribution_function(double standard_deviation) const;

    [[nodiscard]] double get_rfr() const {
        return rfr_;
    }


    [[nodiscard]] double get_current_price() const {
        return current_stock_price_;
    }

    [[nodiscard]] double get_strike_price() const {
        return strike_price_;
    }

    [[nodiscard]] double get_time_to_expire() const {
        return time_to_expire_;
    }

    [[nodiscard]] double get_volatility() const {
        return volatility_;
    }

    [[nodiscard]] double get_standard_deviation_one() const {
        return standard_deviation_one_;
    }

    [[nodiscard]] double get_standard_deviation_two() const {
        return standard_deviation_two_;
    }

    [[nodiscard]] double price() const;

    friend std::ostream &operator<<(std::ostream &os, Call lhs) {
        os << lhs.current_stock_price_ << " " << lhs.strike_price_ << " " << lhs.time_to_expire_
           << " " << lhs.rfr_ << " " << lhs.volatility_;

        return os;
    }

private:
    double current_stock_price_;
    double strike_price_;
    double time_to_expire_;
    double rfr_; //Risk-Free interest rate I am not typing that all out
    double volatility_;
    double standard_deviation_one_;
    double standard_deviation_two_;
};


#endif //CALL_H
