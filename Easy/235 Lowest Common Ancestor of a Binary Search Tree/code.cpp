//same as Lowest Common Ancestor of a Binary Tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)
            return root;
        TreeNode * t1 = lowestCommonAncestor(root->left,p,q);
        TreeNode * t2 = lowestCommonAncestor(root->right,p,q);
        if(t1 && t2)
            return root;
        if(!t1)
            return t2;
        return t1;
    }
};