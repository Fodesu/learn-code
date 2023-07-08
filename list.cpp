#include <ctime>
#include <list>
#include <iostream>
#include <sys/select.h>
#include <unordered_map>
#include <sys/time.h>
#include <vector>

using namespace std;


class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        history.erase(mp[key].second);
        history.push_front(key);
        mp[key].second = history.begin();
        return mp[key].first;
    }
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            history.erase(mp[key].second);
        } else if(history.size() == capacity) {
            history.pop_back();
        }
        history.push_front(key);
        mp[key] = {value, history.begin()};
    }
private:
    size_t capacity;
    std::list<int> history;
    std::unordered_map<int, pair<int, std::list<int>::const_iterator>> mp;
};



class Solution {
public:
    vector<vector<string>> ans;
    int vis[10][10];
    int vish[10], visk[10];
    bool check(int h, int k, int n) {
        if(vish[h]) return false;
        if(visk[k]) return false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i + j == h + k && vis[i][j]) return false;
                if(abs(h - i) == abs(k - j) && vis[i][j]) return false;
            }
        }
        return true;
    }
    void dfs(int n, int h, vector<string>& mp){
        if(h == n) {
            ans.push_back(mp);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(check(h, i, n)) {
                vis[h][i] = 1;
                vish[h] = 1;
                visk[i] = 1;
                mp[h][i] = 'Q';
                dfs(n, h + 1, mp);
                mp[h][i] = '.';
                vis[h][i] = 0;   
                vish[h] = 0;
                visk[i] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> mp;
        string s('.', n);
        for(int i = 0; i < n; i++) {
            vector<string> a = {s};
            ans.push_back(a);
        }
        dfs(n, 0, mp);
        return ans;
    }
};

int main() {

    // LRUCache c(4);
    // for(int i = 1; i < 10; i++) {
    //     c.put(i, i);
    //     std::cout << c.get(i) << '\n';
    // }

    // for(int i = 1; i < 10; i++) {
    //     c.put(i, i);
    //     std::cout << c.get(i) << '\n';
    // }

    // std::time_t result = std::time(0);
    // std::cout << std::asctime(std::localtime(&result)) 
    //           << result << " seconds since the Epoch\n";

    // timeval tv;

    // gettimeofday(&tv, nullptr);
    // std::cout << tv.tv_sec * 1000 + tv.tv_usec << '\n';

    Solution s;
    auto ans =  s.solveNQueens(4);

    for(auto c : ans) {
        for(auto v : c) {
            std::cout << v << '\n';
        }
    }

}