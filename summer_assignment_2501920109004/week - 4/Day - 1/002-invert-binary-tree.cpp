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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            swap(node->left, node->right);

            if(node->left) {
                q.push(node->left);
            }

            if(node->right) {
                q.push(node->right);
            }
        }

        return root;
    }
};