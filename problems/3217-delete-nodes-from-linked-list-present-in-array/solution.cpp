// 3217. Delete Nodes From Linked List Present in Array [Medium]
// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
// Language: C++ | Runtime: 100 ms | Memory: 263.4 MB

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (st.count(curr->val)) {
                prev->next = curr->next;  // delete
            } else {
                prev = curr;              // keep
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};
