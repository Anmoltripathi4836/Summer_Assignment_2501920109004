#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> pCount(26, 0);
        vector<int> window(26, 0);
        vector<int> ans;

        for(char ch : p)
        {
            pCount[ch - 'a']++;
        }

        int left = 0;

        for(int right = 0; right < s.size(); right++)
        {
            window[s[right] - 'a']++;

            if(right - left + 1 > p.size())
            {
                window[s[left] - 'a']--;
                left++;
            }

            if(right - left + 1 == p.size())
            {
                if(window == pCount)
                {
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};

