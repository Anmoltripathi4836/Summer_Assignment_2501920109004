#include <iostream>
#include <queue>
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
    TreeNode* searchBST(TreeNode* root, int val) {

        if(root == nullptr) {
            return nullptr;
        }

        if(root->val == val) {
            return root;
        }

        if(val < root->val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};