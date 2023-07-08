#include <fstream>
#include "json.hpp"
#include <iostream>

using namespace std;
using json = nlohmann::json;

int main() {

    std::ifstream f("example.json");
    json data = json::parse(f);

    std::cout << data << '\n';
    
}