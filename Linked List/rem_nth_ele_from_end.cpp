#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        // If fast is NULL, it means we need to delete the head node
        if(fast == NULL){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Move both pointers until fast reaches the last node
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from end
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};
