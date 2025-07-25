// 206. Reverse Linked List [Easy]
// https://leetcode.com/problems/reverse-linked-list/
// Language: C++ | Runtime: 0 ms | Memory: 13.6 MB

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while( curr != nullptr){
            ListNode* next = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
        
        
    }
};
