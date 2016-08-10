/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*
 #include <map>
 
 struct TreeIs
 {
     TreeNode* root;
     TreeNode* test;
     TreeIs(TreeNode* root, TreeNode* test):root(root),test(test){};
     friend bool operator < (const TreeIs& a, const TreeIs& b)
     {
         if(a.root==b.root)
            return a.test<b.test;
         return a.root< b.root;
     }
 };
 

 
class Solution {
public:
    map<TreeIs, bool> m;
    
    bool is(TreeNode* root, TreeNode* test){
        map<TreeIs, bool>::iterator iter;
        iter = m.find(TreeIs(root,test));
        if(iter!=m.end())
            return iter->second;
        if(test==root){
            m[TreeIs(root,test)] = true;
            return true;
        }
        if(root==NULL){
            m[TreeIs(root,test)] = false;
            return false;
        }
        bool okay1 = false, okay2 = false;
        if(root->left)
            okay1 = is(root->left,test);
        if(root->right)
            okay2 = is(root->right,test);
        m[TreeIs(root,test)] = okay1 || okay2;
        return okay1 || okay2;
    }
    bool isBoth(TreeNode* root, TreeNode* p, TreeNode* q){
        if(is(root,p) && is(root,q))
            return true;
        return false;
    }
    
    TreeNode* wrapper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
         if(root->left){
            if(isBoth(root->left,p,q))
                return wrapper(root->left,p,q);
        }
        if(root->right){
            if(isBoth(root->right,p,q))
                return wrapper(root->right,p,q);
        }
        return root;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       m.clear();
       return wrapper(root,p,q);
    }
};

*/


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;
       TreeNode* tl = lowestCommonAncestor(root->left, p, q);
       TreeNode* tr = lowestCommonAncestor(root->right, p, q);
       if(tl && tr)
        return root;
        if(!tl)
            return tr;
        return tl;
    }
};