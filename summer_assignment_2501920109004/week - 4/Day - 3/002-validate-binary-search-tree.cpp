#include <iostream>
#include <queue>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* root, long minVal, long maxVal) {

        if(root == nullptr) {
            return true;
        }

        if(root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }
};