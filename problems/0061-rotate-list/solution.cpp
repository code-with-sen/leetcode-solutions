// 61. Rotate List [Medium]
// https://leetcode.com/problems/rotate-list/
// Language: C++ | Runtime: 0 ms | Memory: 16.5 MB


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head ;

        ListNode* tail = head ;
        int len = 1 ;

        while(tail->next){
            tail = tail->next;
            len++;
        }

        tail->next = head ;
        k = k % len;

        int steptonewtail = len - k ;
        ListNode* newtail = tail ;

        while(steptonewtail--){
            newtail = newtail->next;
        }

        ListNode* newhead = newtail->next;
        newtail->next = nullptr;

        return newhead;
        
    }
};
