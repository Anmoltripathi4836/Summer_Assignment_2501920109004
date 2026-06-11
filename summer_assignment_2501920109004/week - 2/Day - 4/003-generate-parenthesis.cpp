#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        return balance == 0;
    }

    void generate(string curr, int n, vector<string>& ans) {

        if (curr.length() == 2 * n) {

            if (isValid(curr))
                ans.push_back(curr);

            return;
        }

        generate(curr + '(', n, ans);
        generate(curr + ')', n, ans);
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        generate("", n, ans);

        return ans;
    }
};