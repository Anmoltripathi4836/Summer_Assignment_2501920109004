#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = 0;
        int maxsum = INT_MIN;
        int n = nums.size();

        for(int i  = 0; i < n; i++){
            currentsum += nums[i];
            maxsum = max(maxsum , currentsum);
            if(currentsum < 0) {
                currentsum = 0;
            }
        }
        return maxsum;
    }
};