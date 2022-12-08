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
    void helper(TreeNode* root,vector<int> &a){
        if(!root)
            return;
        if (!root->left && !root->right)
            a.push_back(root->val);
        if (root->left)
        helper(root->left,a);
        if (root->right)
        helper(root->right,a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        if((!root1 && root2) || root1 && !root2)
            return false;
        vector<int> x,y;
        helper(root1,x);
        helper(root2,y);
        
        if(x==y)
            return true;
        
        
        return false;
    }
};