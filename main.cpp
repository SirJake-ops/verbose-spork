#include <iostream>
#include <cstdlib>

int main() {
    const auto Print = [](const std::string& message){std::cout << message << std::endl;};

    Print("Hello, World!");




    //This is where we will get the data hence its name lol
    int result = std::system("python data_script.py");



    return result;
}