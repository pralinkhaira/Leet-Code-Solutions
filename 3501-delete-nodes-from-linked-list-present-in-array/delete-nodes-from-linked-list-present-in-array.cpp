class Solution {
public:
    bitset<100001> hasN=0;
    
    ListNode* f(ListNode* curr){
        if (!curr) return NULL;
        curr->next=f(curr->next);
        if (hasN[curr->val]) curr=curr->next;
        return curr;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for(int x: nums) hasN[x]=1;
        ListNode dummy(0, head);
        f(&dummy);
        return dummy.next;
    }
};