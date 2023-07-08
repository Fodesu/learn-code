#include <bits/stdc++.h>


using namespace std;

int slove(const std::string& s) {
    char c = s[0];
    for(auto &v : s) {
        if(v != c) {
            return s.size() - 1;    
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while(t--) {
        std::string s;
        cin >> s;
        std::cout << slove(s) << '\n';
    }


}