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
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* copyTail = dummy;
        ListNode* curr = head;
        while (curr) {
            copyTail->next = new ListNode(curr->val);
            copyTail = copyTail->next;
            curr = curr->next;
        }
        ListNode* temp = dummy->next;
        curr=head->next;
        ListNode* temp2 = new ListNode(head->val);
        while(curr){
            ListNode* Next=curr->next;
            curr->next = temp2;
            temp2=curr;
            curr=Next;
        }
        while(temp && temp2){
            cout<<temp->val<<" "<<temp2->val<<endl;
            if(temp->val != temp2->val) return 0;
            temp=temp->next;
            temp2=temp2->next;
        }
        return 1;
    }
};