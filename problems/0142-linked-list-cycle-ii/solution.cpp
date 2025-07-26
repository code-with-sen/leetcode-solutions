// 142. Linked List Cycle II [Medium]
// https://leetcode.com/problems/linked-list-cycle-ii/
// Language: C++ | Runtime: 7 ms | Memory: 11.4 MB

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;

        ListNode* slow = head ;
        ListNode* fast = head ;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
