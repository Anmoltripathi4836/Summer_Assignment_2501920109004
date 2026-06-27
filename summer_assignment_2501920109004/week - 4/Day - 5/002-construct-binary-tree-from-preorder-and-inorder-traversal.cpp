#include <iostream>
#include <queue>
#include<unordered_map>
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
    unordered_map<int, int> inorderIndexMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }

        return build(preorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder,
                    int rootIndex,
                    int left,
                    int right) {

        if (left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[rootIndex]);

        int mid = inorderIndexMap[preorder[rootIndex]];

        root->left = build(preorder,
                           rootIndex + 1,
                           left,
                           mid - 1);

        root->right = build(preorder,
                            rootIndex + (mid - left) + 1,
                            mid + 1,
                            right);

        return root;
    }
};