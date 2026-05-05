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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL){
            return head;
        }
        int i=1;
        ListNode* curr=head;
        ListNode* pre=head;
        while(curr->next!=NULL){
            curr=curr->next;
            i++;
        }
        curr->next=pre;
        k=k%i;
        i=i-k-1;
        while(i!=0){
            pre=pre->next;
            i--;
        }
        head=pre->next;
        pre->next=NULL;
        return head;
    }
};