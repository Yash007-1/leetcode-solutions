/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> q;
        bool ltor=true;
        q.push(root);

        while (!q.empty()) {

            
            int n=q.size();
            vector<int> l(n);

           
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();

                q.pop();
               
                 int index = ltor ? i : n - 1 - i;
                l[index] = curr->val;
                
             
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);

               
                
            }
            res.push_back(l);
            ltor=!ltor;
        }
        return res;
    }
};