#include <iostream>
#include <string>

using namespace std;


int main() {
    long long a = 1, b = 1;
    for(int i = 1; i < 8; i++) {
        a = a * 8;
        b = b * 7;
    }
    std::cout << a - b << " / " << a << '\n';
        


}
