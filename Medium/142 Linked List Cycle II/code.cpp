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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode * low = head -> next;
        if(!low || !low -> next)
            return NULL;
        ListNode * fast = low -> next;
        while(fast != NULL && fast != low){
            low = low -> next;
            fast = fast -> next;
            if(!fast)
                return NULL;
            fast = fast -> next;
        }
        if(!fast)
            return NULL;
        low = head;
        while(low != fast){
            low = low -> next;
            fast = fast -> next;
        }
        return fast;
    }
};