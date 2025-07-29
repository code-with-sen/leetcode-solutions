// 23. Merge k Sorted Lists [Hard]
// https://leetcode.com/problems/merge-k-sorted-lists/
// Language: C++ | Runtime: 3 ms | Memory: 18.4 MB


class Solution {
public:
    struct compare{
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare> minheap;

        for(auto list : lists){
            if(list != nullptr)
                minheap.push(list);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!minheap.empty()){
            ListNode* curr = minheap.top();
            minheap.pop();


            tail->next = curr;
            tail = tail->next;

            if(curr->next){
                minheap.push(curr->next);
            }
        }

        return dummy->next;
    }
};
