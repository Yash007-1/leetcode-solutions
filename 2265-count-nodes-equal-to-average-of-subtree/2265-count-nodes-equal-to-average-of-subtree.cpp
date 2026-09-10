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
    pair<int, int> f(TreeNode* root) {
        if (root == NULL)
            return {0, 0};
        auto l=f(root->left);
        auto r=f(root->right);
        return {1 + l.first +r.first,
                root->val + l.second + r.second};
    }
    int averageOfSubtree(TreeNode* root) {
        if (root == NULL)
            return 0;
        auto p = f(root);
        if (p.second / p.first == root->val) {
            return 1 + averageOfSubtree(root->left) +
                   averageOfSubtree(root->right);
        } else
            return averageOfSubtree(root->left) + averageOfSubtree(root->right);
    }
};