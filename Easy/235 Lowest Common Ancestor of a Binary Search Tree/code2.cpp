/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// another algorihtm
// only works for BST

#include <algorithm>
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)
            return NULL;
        int m = min(p->val, q->val);
        int M = max(p->val, q->val);
        int now = root->val;
        if(now == m || now == M)
            return root;
        if(now > m && now < M)
            return root;
        if(now < m)
            return lowestCommonAncestor(root->right, p,q);
        return lowestCommonAncestor(root->left, p,q);
    }
};