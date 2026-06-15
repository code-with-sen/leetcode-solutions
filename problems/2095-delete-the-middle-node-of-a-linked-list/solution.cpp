// 2095. Delete the Middle Node of a Linked List [Medium]
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Language: C++ | Runtime: 0 ms | Memory: 312.1 MB

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
    ListNode* deleteMiddle(ListNode* head) {
        delet(head,head);
        return head;
    }

    void delet(ListNode* &head,ListNode* h)
    {
        if(h==nullptr || h->next==nullptr){
           head=head->next;
        }
        else{
            delet(head->next,h->next->next);
        }
    }
};
