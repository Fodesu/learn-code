#include <iostream>
#include <map>
#include <string>
#include <string_view>

using namespace std;


int main() {

    std::string_view s = "";

    std::cout << s.length() << '\n';

    if(s.empty()) {
        std::cout << "HHHH" << '\n';
    }

}
