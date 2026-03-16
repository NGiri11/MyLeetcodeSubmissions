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
    ListNode* reverse(ListNode* head, int left, int right) {
        if(!head || left==right){
            return head;
        }
        vector<int> v;
        ListNode* s=head;
        ListNode* e=head;
        ListNode* s1=head;
        for(int i=1;i<left;i++){
            s=s->next;
        }
        s1=s;
        for(int i=0;i<right;i++){
            e=e->next;
        }
        while(s!=e){
            v.push_back(s->val);
            s=s->next;
        }
        s=s1;
        int i=v.size()-1;
        while(s!=e){
            s->val=v[i];
            i--;
            s=s->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c=0,i=k;
        ListNode* curr=head;
        while(curr!=NULL){
            c++;
            curr=curr->next;
        }
        while(i<=c && k!=1){
            head=reverse(head, i-k+1, i);
            i=i+k;
        }
        return head;
    }
};