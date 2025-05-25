//
// Created by Jacob Pagan on 5/24/2025.
//



#include "../../include/Call.h"
#include "../../include/Put.h"
#include <vector>
#include <random>

template<typename O>
concept OptionType = std::same_as<O, Call> || std::same_as<O, Put>;
template<typename OptionType>
class Generator {
public:

    explicit Generator(OptionType option, int size) :
            _option(option),
            _size(size) {
        generateVectorTesting();
    }


    void generateVectorTesting() {
        for (int i = 0; i < _size; i++) {
            double current_stock_price = getRandomNumber(0.0, 300.0);
            double strike_price = getRandomNumber(0.0, 300.0);
            double time_to_expire = getRandomNumber(0.0, 1.0);
            double rfr = getRandomNumber(0.0, 1.0);
            double volatility = getRandomNumber(0.0, 1.0);

            OptionType option(current_stock_price, strike_price, time_to_expire, rfr, volatility);

            _generatorVec.push_back(option);
        }
    }

    std::vector<OptionType> getVector() {
        return _generatorVec;
    }

private:
    OptionType _option{}; //This is not a double but rather a option with a
    int _size;
    std::vector<OptionType> _generatorVec{};

    double getRandomNumber(double low, double high) {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<> dis(low, high);
        return dis(gen);
    }
};