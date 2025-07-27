// 82. Remove Duplicates from Sorted List II [Medium]
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Language: C++ | Runtime: 0 ms | Memory: 15.5 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head ;

        ListNode* prev = dummy ;

        while(head){
        if(head->next && head->val == head->next->val){
            int dulval = head->val;
            while(head && head->val == dulval){
                head = head->next;
            }
            prev->next = head ;
        }else{
            prev = prev->next;
            head = head->next;
        }
      }

      return dummy->next;
    }
};
