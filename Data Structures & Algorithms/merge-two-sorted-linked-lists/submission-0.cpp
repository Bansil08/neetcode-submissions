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
    ListNode* solve(ListNode*l1,ListNode* l2){
        if(!l1)return l2;
        if(!l2)return l1;

        if(l1->val>=l2->val){
            l2->next=solve(l1,l2->next);
            return l2;
        }
        else{
            l1->next=solve(l1->next,l2);
            return l1;
        }
        return NULL;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)return NULL;
        if(!list1)return list2;
        if(!list2)return list1;
        return solve(list1,list2);
    }
};
