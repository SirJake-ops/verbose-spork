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
            _size(size) {}


    std::vector<OptionType> generateVectorTesting() {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> dis(0, 1);
        _generatorVec.resize(_size);

        for (int i = 0; i < _generatorVec.size(); i++) {

        }
    }

private:
    OptionType _option{}; //This is not a double but rather a option with a
    int _size;
    std::vector<OptionType> _generatorVec{};
};