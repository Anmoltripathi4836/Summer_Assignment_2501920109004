#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int currentsum = 0;
        
        for(int i = 0; i < k; i++){
            currentsum +=  nums[i];
        }

        int maxsum = currentsum;

        for(int i = k; i < n; i++){
        currentsum = currentsum - nums[i - k] + nums[i];
        maxsum = max(maxsum, currentsum);
       }
       return(double)maxsum/k;
    }
};