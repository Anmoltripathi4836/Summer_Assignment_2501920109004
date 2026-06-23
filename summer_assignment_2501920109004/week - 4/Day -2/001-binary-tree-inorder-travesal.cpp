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
    void Inorder(TreeNode* root,vector<int>& ans){
        if(root == nullptr){
            return;
        }

        Inorder(root->left,ans);
        ans.push_back(root->val);
        Inorder(root->right,ans);
    }

    

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        Inorder(root,ans);

        return ans;
    }
};