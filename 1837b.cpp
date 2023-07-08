#include <bits/stdc++.h>


using namespace  std;

void solve() {
    int n; cin >> n;
    std::string s;
    cin >> s;

    int count = 0;
    int maxn = -200, minn = 200;
    for(int i = 0; i < n; i++) {
        maxn = max(maxn, count);
        minn = min(minn, count);
        if(s[i] == '<') count++;
        else count--;
    }
    maxn = max(maxn, count);
    minn = min(minn, count);
    std::cout << abs(maxn - minn) + 1<< '\n';
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;

    while(t--) {
        solve();
    }

}
