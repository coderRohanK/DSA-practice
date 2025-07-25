#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* cur1 = head;

        // Find middle
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* cur = slow;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(cur != NULL){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        // Compare first half and reversed second half
        while(prev != NULL){
            if(prev->val != cur1->val){
                return false;
            }
            prev = prev->next;
            cur1 = cur1->next;
        }

        return true;
    }
};
