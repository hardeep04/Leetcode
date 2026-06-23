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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;
        ListNode* slow=head, *fast = head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode* second = newHead;
        ListNode* first = head;
        while(second){
            if(first->val != second->val){
                // reverse(newHead);
                return 0;
            } 
            first=first->next;
            second=second->next;
        }
        // reverse(newHead);
        return 1;
    }
};