/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
// reference: https://leetcode.com/discuss/44411/simple-40ms-c-o-n-o-1-solution-with-only-one-while-loop

// It's a BFS traversal. now pointer is the current level traveler and head is the left most element at next level 
//and the tail is the right most element at next level till now. We move now pointer at current level 
//and populate the the next-link at its children level. (Here the gist is we can move now to its next 
//because this relationship was already populated in the previous round).

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode * now = root, * head = NULL, * tail = NULL;
        while(now){ // "now" is not null
            if(now -> left){
                if(!tail) // the first case. head and tail is both null, means it's the first time we come to this level
                    head = tail = now -> left;
                else{
                    tail -> next = now -> left;
                    tail = now -> left;
                }
            }
            if(now -> right){
                if(!tail)
                    head = tail = now -> right;
                else{
                    tail -> next = now -> right;
                    tail = now -> right;
                }
            }
            if(now -> next)
                now = now -> next;
            else{ // change now pointer to the next level
                now = head;
                head = tail = NULL;
            }
        }
    }
};