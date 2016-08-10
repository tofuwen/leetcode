/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        if(head -> next == NULL)
            return head;
        ListNode * ans = head -> next;
        ListNode * p1 = head;
        ListNode * p2 = p1 -> next;
        ListNode * p3 = p2 -> next;
        do {
            if(p3 && p3 -> next)
                p1 -> next = p3 -> next;
            else
                p1 -> next = p3;
            p2 -> next = p1;
            p1 = p3;
            if(p1)
                p2 = p1 -> next;
            else
                p2 = NULL;
            if(p2)
                p3 = p2 -> next;
            else
                p3 = NULL;
        }while(p2);
        return ans;
    }
};