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
    int printInorder(TreeNode* node)
{
    if (node == NULL)
        return 0;
 
   
    int left = 1 + printInorder(node->left);
 
  
   
    
    int right= 1+printInorder(node->right);
    return max(right,left);
}
    int maxDepth(TreeNode* root) {
        return printInorder(root);
    }
};