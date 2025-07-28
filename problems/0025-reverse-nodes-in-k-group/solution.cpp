// 25. Reverse Nodes in k-Group [Hard]
// https://leetcode.com/problems/reverse-nodes-in-k-group/
// Language: C++ | Runtime: 0 ms | Memory: 16.6 MB


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1 ) return head ;

        ListNode* dummy = new ListNode(0);
        dummy->next = head ;

        ListNode* curr = dummy , *prev = dummy , *next = dummy ;
        int count = 0 ;

        while(curr->next != nullptr){
            curr = curr->next;
            count++;
        }

        while(count >= k){
            curr = prev->next;
            next = curr->next;

            for(int i = 1 ; i< k ; i++){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next ;
                next = curr->next;
            }

            prev = curr ;
            count -= k;
        }

        return dummy->next;
    }
};
