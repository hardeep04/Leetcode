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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s=0;
        ListNode* t = head;

        while(t){
            t=t->next;
            s++;
        }        
        
        n = s-n;
        if(n==0) return head->next;
        t = head;
        while(t){
            if(n==1){
                t->next = t->next->next;
                break;
            }
            t=t->next;
            n--;
        }
        return head;
    }
};