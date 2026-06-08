#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int s = ransomNote.length();
        int t = magazine.length();
        
        vector<int>count(26 , 0);

        for(int i = 0; i < s; i++){
            count[ransomNote[i] - 'a']++;
        }

        vector<int>counting(26, 0);

        for(int i = 0; i  < t; i++){
            counting[magazine[i] - 'a']++;
        }

        for(int i = 0; i < count.size(); i++){
            if(count[i] > counting[i]){
                return false;
            }
        }
        
        return true;
    }
};