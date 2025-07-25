// 141. Linked List Cycle [Easy]
// https://leetcode.com/problems/linked-list-cycle/
// Language: C++ | Runtime: 9 ms | Memory: 11.9 MB

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head ;
        ListNode* fast = head ;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
        }

        return false;
    }
};
