#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<pair<string, string>> arr;

        for (int i = 0; i < strs.size(); i++) {

            string originalString = strs[i];
            string sortedString = strs[i];

            sort(sortedString.begin(), sortedString.end());

            pair<string, string> p;
            p.first = sortedString;
            p.second = originalString;

            arr.push_back(p);
        }

        sort(arr.begin(), arr.end());

        vector<vector<string>> answer;
        vector<string> currentGroup;

        for (int i = 0; i < arr.size(); i++) {

            if (i == 0) {
                currentGroup.push_back(arr[i].second);
            }
            else {
                if (arr[i].first == arr[i - 1].first) {
                    currentGroup.push_back(arr[i].second);
                }
                else {
                    answer.push_back(currentGroup);
                    currentGroup.clear();
                    currentGroup.push_back(arr[i].second);
                }
            }
        }

        if (currentGroup.size() > 0) {
            answer.push_back(currentGroup);
        }

        return answer;
    }
};