#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* cur = head;
        ListNode* even = head->next;
        ListNode* temp=NULL;
        while(cur!=NULL && cur->next!=NULL && cur->next->next != NULL){
            temp=cur->next;
            cur->next=cur->next->next;
            temp->next=cur->next->next;
            cur=cur->next;
        }
        cur->next=even;
        return head;
    }
};