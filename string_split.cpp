#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    std::string str = "Hello,World,This,Is,C++";
    char delimiter = ',';
    std::vector<std::string> tokens = split(str, delimiter);

    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }

    return 0;
}