// 21. Merge Two Sorted Lists [Easy]
// https://leetcode.com/problems/merge-two-sorted-lists/
// Language: C++ | Runtime: 0 ms | Memory: 19.6 MB


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode dummy(0);
          ListNode* tail = &dummy;

          while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else{
                
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
            
          }
        tail->next = list1 ? list1 : list2;
          return dummy.next;
    }
};
