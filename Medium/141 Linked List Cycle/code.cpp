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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode * low = head -> next;
        if(low == NULL)
            return false;
        ListNode * fast = low -> next;
        while(fast != NULL && fast != low){
            low = low -> next;
            fast = fast -> next;
            if(!fast)
                return false;
            fast = fast -> next;
        }
        return fast != NULL;
    }
};