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
        unordered_map<ListNode*, int> m;
        ListNode* t=head;
        while(1){
            if(t==NULL) return t;
            if(m.find(t)!=m.end()) return t;
            m[t]=1;
            t=t->next;
        }
        return NULL;
    }
};