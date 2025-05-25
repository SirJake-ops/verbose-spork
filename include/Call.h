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

    Call(double current_stock_price, double strike_price, double time_to_expire, double rfr,
         double volatility): current_stock_price_(current_stock_price),
                             strike_price_(strike_price),
                             time_to_expire_(time_to_expire),
                             rfr_(rfr),
                             volatility_(volatility) {
        standard_deviation_one_ = (std::log(current_stock_price / strike_price) + (rfr + std::pow(volatility, 2)) *
                                   time_to_expire) / (volatility * std::sqrt(time_to_expire));

        standard_deviation_two_ = standard_deviation_one_ - (volatility * std::sqrt(time_to_expire));
    }

    [[nodiscard]] double cumulative_distribution_function(double standard_deviation) const;

    [[maybe_unused]] double getrfr() const {
        return rfr_;
    }

    [[nodiscard]] double get_time_to_expire() const {
        return time_to_expire_;
    }

    friend std::ostream& operator<<(std::ostream& os, Call lhs) {
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
