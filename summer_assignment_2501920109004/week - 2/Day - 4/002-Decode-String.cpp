#include <iostream>
#include <vector>
#include<stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {

        stack<int> numberStack;
        stack<string> stringStack;

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {

                int num = 0;

                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                numberStack.push(num);
                i--;
            }

            else if (s[i] != ']') {

                stringStack.push(string(1, s[i]));
            }

            else {

                string curr = "";

                while (!stringStack.empty() &&
                       stringStack.top() != "[") {

                    curr = stringStack.top() + curr;
                    stringStack.pop();
                }

                stringStack.pop(); 

                int k = numberStack.top();
                numberStack.pop();

                string repeated = "";

                while (k--) {
                    repeated += curr;
                }

                stringStack.push(repeated);
            }
        }

        string ans = "";

        while (!stringStack.empty()) {
            ans = stringStack.top() + ans;
            stringStack.pop();
        }

        return ans;
    }
};