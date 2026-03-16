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
        int count=0;
        ListNode* p=head;
        while(p!=NULL){
            count++;
            p=p->next;
        }
        if (n == count) {
            return head->next;
        }
        p=head;
        count-=n;
        while(count>1){
            p=p->next;
            count--;
        }
        if(p->next!=NULL){
            p->next=p->next->next;
        }
        return head;
    }
};