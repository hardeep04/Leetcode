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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;
        ListNode* t = list1;
        while(t){
            v.push_back(t->val);
            t = t->next;
        }
        t=list2;
        while(t){
            v.push_back(t->val);
            t = t->next;
        }
        sort(v.begin(), v.end());
        if(v.empty()) return nullptr;

        ListNode* ans = new ListNode(v[0]);
        ListNode* temp = ans;
        for(int i=1; i<v.size(); i++){
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return ans;
    }
};