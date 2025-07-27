// 83. Remove Duplicates from Sorted List [Easy]
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Language: C++ | Runtime: 0 ms | Memory: 16.1 MB

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
        ListNode* curr = head ;

        while(curr && curr->next){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }

        return head ;
    }
};
