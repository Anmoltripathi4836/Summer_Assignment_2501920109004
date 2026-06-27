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

    bool isMirror(TreeNode* leftTree, TreeNode* rightTree) {

        if (leftTree == nullptr && rightTree == nullptr) {
            return true;
        }

        if (leftTree == nullptr || rightTree == nullptr) {
            return false;
        }

        if (leftTree->val != rightTree->val) {
            return false;
        }

        return isMirror(leftTree->left, rightTree->right) &&
               isMirror(leftTree->right, rightTree->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        return isMirror(root->left, root->right);
    }
};