#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int solve(vector<string>& tokens) {
        stack<int> s;

        int n = tokens.size();

        for (int i = 0; i < n; i++) {

            string curr = tokens[i];

            if (curr == "+" || curr == "-" ||
                curr == "*" || curr == "/") {

                int a = s.top();
                s.pop();

                int b = s.top();
                s.pop();

                if (curr == "+") {
                    s.push(b + a);
                }
                else if (curr == "-") {
                    s.push(b - a);
                }
                else if (curr == "*") {
                    s.push(b * a);
                }
                else if (curr == "/") {
                    s.push(b / a);
                }
            }
            else {
                s.push(stoi(curr));
            }
        }

        return s.top();
    }

    int evalRPN(vector<string>& tokens) {

        return solve(tokens);
    }
};