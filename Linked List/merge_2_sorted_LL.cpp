#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* head = NULL;
        ListNode* cur = NULL;

        // Initialize head
        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        cur = head;

        // Merge remaining nodes
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        // Attach remaining list
        if(list1 != NULL) cur->next = list1;
        else cur->next = list2;

        return head;
    }
};
