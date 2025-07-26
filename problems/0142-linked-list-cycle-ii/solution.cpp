// 142. Linked List Cycle II [Medium]
// https://leetcode.com/problems/linked-list-cycle-ii/
// Language: C++ | Runtime: 10 ms | Memory: 11.4 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;

        ListNode* slow = head ;
        ListNode* fast = head ;

        while(fast && fast->next){
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
