#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> vis(nums.size());
        int l = 0, r = 0;
        vis[0] = 1;
        while(r < nums.size()) {
            for(int i = max(r + 1, l) ; i <= l + nums[l] && i < nums.size(); i++) {
                vis[i] = 1;
                if(i == nums.size() - 1) {
                    break;
                }
            }
            r = l + nums[l];
            l++;
        }
        return vis[nums.size()-1];
    }
};


int main() {

  Solution s;
  std::vector<int> v = {3, 2, 1, 0, 4};
  std::cout << s.canJump(v) << '\n';


}
