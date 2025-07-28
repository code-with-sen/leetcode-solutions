// 876. Middle of the Linked List [Easy]
// https://leetcode.com/problems/middle-of-the-linked-list/
// Language: C++ | Runtime: 0 ms | Memory: 10.1 MB

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // fast moves 2 steps, slow moves 1 step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // when fast reaches the end, slow is at the middle
        return slow;
    }
};
