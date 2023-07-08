#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {

    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {1, 2, 3, 4};


    unordered_set<vector<int>> st;
    st.insert(a);
    st.insert(b);

    std::cout << st.size() << '\n';

    for(auto &c : st) {
        for(auto &b : c) {
          std::cout << b << ' ';
      }
    }
}
