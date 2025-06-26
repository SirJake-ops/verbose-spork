#include <iostream>
#include <cstdlib>

int main() {
    const auto Print = [](const std::string& message){std::cout << message << '\n';};

    Print("Hello, World!");




    //This line below will have to change for each user and will have to be adjusted for the path to their interpreter
    //TODO: Update the README.md for the proper way to set this up including the install requirements
    int result = std::system("python data_script.py");



    return result;
}