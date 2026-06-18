#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& temperatures,vector<int>& ans){
        stack<int>s;
        int idx = temperatures.size() - 1;
        ans[idx] = 0;
        s.push(idx);
        for(idx = idx -1; idx >=0; idx--){
            int curr = temperatures[idx];
            while(!s.empty() && temperatures[idx] >= temperatures[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans[idx] = 0;
            }else {
                ans[idx] = s.top() - idx;
            }

            s.push(idx);
        }
    }


    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        solve(temperatures, ans);

        return ans;
    }
};