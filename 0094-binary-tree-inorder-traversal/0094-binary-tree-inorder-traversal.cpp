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
    //iterative
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* n = root;
        stack<TreeNode*> st;
        vector<int> inorder;
        while(true){
            if(n!=NULL){
                st.push(n);
                n = n->left;
            }else{
                if(st.empty()) break;
                n = st.top();
                st.pop();
                inorder.push_back(n->val);
                n = n->right;
            }
        }
        return inorder;
        
    }
};