#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlength = 0;
        int left = 0;
        for(int right = 0; right < n; right++){
           for(int i = left; i < right; i++){
            if(s[i] == s[right]){
                left = i+1;
                break;
            }
           }
           maxlength = max(maxlength, right - left + 1);
        }
        return maxlength;
    }
};