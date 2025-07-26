// 160. Intersection of Two Linked Lists [Easy]
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Language: C++ | Runtime: 37 ms | Memory: 18.7 MB


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;

         ListNode* a = headA;
         ListNode* b = headB;

        while(a!=b){
            a = (a==nullptr)? headB : a->next;
            b = (b==nullptr)? headA : b->next;
        }
        return a;
    }
};
