// 206. Reverse Linked List [Easy]
// https://leetcode.com/problems/reverse-linked-list/
// Language: C++ | Runtime: 0 ms | Memory: 13.5 MB


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr ;
            curr = next;
        }
        return prev;
    }
};
