/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* odd = new ListNode(head->val);
        ListNode* even = new ListNode(head->next->val);
        ListNode* temp = head->next->next;
        ListNode* ans = odd, *ans2=even;
        // bool alt=1;
        while(temp){
            odd->next = new ListNode(temp->val);
            odd = odd->next;
            if(!temp->next) break;
            even->next = new ListNode(temp->next->val);;
            even=even->next;
            temp=temp->next->next;
        }
        odd->next=ans2;
        return ans;
    }
};