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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if(root==NULL) return vector<vector<int>>();
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
       
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
                TreeNode* n = q.front();
                q.pop();
                int index = (flag) ? i : size-i-1;
                level[index] = n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            flag = !flag;
            ans.push_back(level);
           
        }
        return ans;
    }
};