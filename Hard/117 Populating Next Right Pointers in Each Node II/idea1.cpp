/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// This is a wrong idea!

// Reason: it's a bfs!
// So, when we use the next for fa pointer, it may have a brother but the next pointer is NULL!
// Similarly, if we use queue instead of recursion, I think it's a right idea.
// But the problem say "constant space", we cannot use queue.
// However, I highly doubt the word "constant".
// If we ever use recursion, then it's not constant space. We use stack for recursion...

class Solution {
public:
    void find(TreeLinkNode * fa, TreeLinkNode * cur, bool left){
        if(fa == NULL){
            cur -> next = NULL;
        }
        else{
            if(left && fa -> right)
                cur -> next = fa -> right;
            else{
                if(fa -> next && fa -> next -> left)
                    cur -> next = fa -> next -> left;
                else{
                    if(!fa -> next)
                        cur -> next = NULL;
                    else
                        find(fa->next, cur, true);
                }
            }
        }
    }

    void solve(TreeLinkNode * fa, TreeLinkNode * cur, bool left){
        if(!cur)
            return;
        find(fa, cur, left);
        solve(cur, cur->left, true);
        solve(cur, cur->right, false);
    }

    void connect(TreeLinkNode *root) {
        solve(NULL, root, false);
    }
};