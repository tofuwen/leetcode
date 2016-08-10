int change(ListNode * l){
	if(!l)
		return 0;
	return l -> val;
}


class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode * ans = NULL;
    	ListNode * pre = NULL;
    	int cur = 0;
        while(l1 || l2 || cur){
        	int a = cur + change(l1) + change(l2);
        	if(!ans){
        		ans = new ListNode(a%10);
        		pre = ans;
        	}
        	else{
        		ListNode * h = new ListNode(a % 10);
        		pre -> next = h;
        		pre = h;
        	}
        	cur = a / 10;
        	if(l1)
        		l1 = l1 -> next;
        	if(l2)
        		l2 = l2 -> next;        
        }
      //  printf("%d\n", ans == NULL);
        return ans;
    }
};