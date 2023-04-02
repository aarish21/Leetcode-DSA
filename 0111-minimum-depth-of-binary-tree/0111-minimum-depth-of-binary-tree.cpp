/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int left = INT_MAX;
        int right = INT_MAX;
        if(root->left)
        left = 1+height(root->left);
        if(root->right)
        right = 1+ height(root->right);
        
        return min(left,right);
    }
  
    int minDepth(TreeNode* root) {
        return height(root);
    }
};