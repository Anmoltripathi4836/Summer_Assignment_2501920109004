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
    pair<int, int> diameterHelper(TreeNode* root) {

        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> leftInfo = diameterHelper(root->left);
        pair<int, int> rightInfo = diameterHelper(root->right);

        int currDiam = leftInfo.second + rightInfo.second;

        int finalDiam = max(currDiam,
                            max(leftInfo.first, rightInfo.first));

        int finalHt = max(leftInfo.second, rightInfo.second) + 1;

        return {finalDiam, finalHt};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterHelper(root).first;
    }
};