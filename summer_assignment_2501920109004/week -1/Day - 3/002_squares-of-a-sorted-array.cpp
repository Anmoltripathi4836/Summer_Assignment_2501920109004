#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n; i++){
            int square = nums[i] * nums[i];
            ans.push_back(square);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};